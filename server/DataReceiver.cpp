#include "DataReceiver.hpp"

DataReceiver::DataReceiver(std::shared_ptr<boost::asio::ip::tcp::socket> socket, std::size_t maxFileSize, std::chrono::seconds timeout)
    : socket_(socket), 
    timer_(socket_->get_executor(), timeout), 
    bufferSize_(maxFileSize), 
    timeout_(timeout)
{
    data_ = new char[bufferSize_];
}

void DataReceiver::receive() 
{
    socket_->async_read_some(boost::asio::buffer(data_, sizeof(data_)),
        std::bind(&DataReceiver::handleReceive, shared_from_this(),
            std::placeholders::_1, std::placeholders::_2));
}
void DataReceiver::handleReceive(const boost::system::error_code& error, std::size_t length) 
{
    if (!error) 
    {
        if (length > 0)
        {
            save(data_, length); // call save from child class
        }
        startTimer();
        receive(); // continue receiving data
    } 
    else if (error != boost::asio::error::eof) 
    {
        std::cerr << "DataReceiver::receive: Error receiving data: " << error.message() << std::endl;
        closeConnection();
    }
}

void DataReceiver::startTimer() 
{
    timer_.expires_after(timeout_);
        auto self(shared_from_this());
        timer_.async_wait([this, self](boost::system::error_code error) {
            if (!error) {
                std::cerr << "DataReceiver::startTimer: Connection timed out" << std::endl;
                closeConnection();
            }
        });
}

void DataReceiver::closeConnection()
{
    if (socket_) {
        std::cerr << "DataReceiver::closeConnection" << std::endl;
        boost::system::error_code error;
        socket_->close(error);
    }

    close();
}