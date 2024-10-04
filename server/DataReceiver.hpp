#ifndef DATA_RECEIVER_H
#define DATA_RECEIVER_H

#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iostream>
#include <vector>

class DataReceiver : public std::enable_shared_from_this<DataReceiver>
{
public:
    explicit DataReceiver(std::shared_ptr<boost::asio::ip::tcp::socket> socket, std::size_t maxFileSize, std::chrono::seconds timeout);
    ~DataReceiver()
    {
        delete[] data_;
    }
    void receive();
    virtual void save(const char* data, std::size_t length){};
    virtual void close(){};
    void closeConnection();

private:
    void startTimer();
    void handleReceive(const boost::system::error_code& error, std::size_t length);
    std::shared_ptr<boost::asio::ip::tcp::socket> socket_;
    std::chrono::seconds timeout_;
    char* data_;
    std::size_t bufferSize_;
    boost::asio::steady_timer timer_;
};

#endif