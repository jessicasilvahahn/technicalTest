#ifndef CLIENT_H
#define CLIENT_H

#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include "../file/File.hpp"
#include <iomanip>

using boost::asio::ip::tcp;

class Client {
public:
    Client(const std::string& host, const std::string& port);
    void sendFile(const std::string& file_path);

private:
    void connect(const std::string& host, const std::string& port);
    
    boost::asio::io_context io_context_;
    tcp::resolver resolver_;
    tcp::socket socket_;
    const std::size_t BUFFER_SIZE = 1024;
};

#endif