#include "FileWriter.hpp"

FileWriter::FileWriter(std::shared_ptr<boost::asio::ip::tcp::socket> socket, std::string clientId, std::size_t maxFileSize, std::chrono::seconds timeout) 
    : DataReceiver(socket, maxFileSize, timeout), 
    prefix_(clientId), 
    counter_(0), 
    size_(0), 
    maxFileSize_(maxFileSize)
    {
        newFile();
    }

void FileWriter::save(const char* data, std::size_t length)
{
    if (size_ + length > maxFileSize_) 
    {
        std::size_t remainingSpace = maxFileSize_ - size_;
        currentFile_.write(data, remainingSpace);
        currentFile_.flush();
        newFile();
        currentFile_.write(data + remainingSpace, length - remainingSpace);
    } 
    else 
    {
        currentFile_.write(data, length);
    }

    size_ += length;
}

void FileWriter::newFile()
{
    currentFile_.close();
    std::stringstream fileNameSS;
    fileNameSS << prefix_ << "_" << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << "_" << counter_++ << ".dat";
    currentFile_.open(fileNameSS.str(), std::ios::binary | std::ios::out);
    size_ = 0;
}

void FileWriter::close()
{
    currentFile_.close();
}