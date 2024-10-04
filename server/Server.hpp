#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include "Session.hpp"
#include "FileWriter.hpp"
#include <chrono>

using boost::asio::ip::tcp;

class Server {
public:
    Server(boost::asio::io_context& io_context, int port, std::size_t maxFileSize, int timeout, std::string prefix);
    void accept();

private:
    std::string generateClientId(const tcp::socket& socket);
    tcp::acceptor acceptor_;
    std::size_t maxFileSize_;
    std::chrono::seconds timeout_;
    std::string prefix_;
};

#endif