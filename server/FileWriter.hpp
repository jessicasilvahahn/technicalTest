#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include "DataReceiver.hpp"
#include "../file/File.hpp"
#include <sstream>
#include <iomanip>

class FileWriter : public DataReceiver
{
public:
    FileWriter(std::shared_ptr<boost::asio::ip::tcp::socket> socket, std::string clientId, std::size_t maxFileSize, std::chrono::seconds timeout);
    void save(const char* data, std::size_t length) override;
    void close() override;
    void newFile();

private:
    File currentFile_;
    std::string prefix_;      
    int counter_;
    std::size_t size_;
    std::size_t maxFileSize_;
};

#endif