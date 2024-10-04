#include "Client.hpp"

Client::Client(const std::string& host, const std::string& port)
    : resolver_(io_context_), 
    socket_(io_context_)
{
    connect(host, port);
}

void Client::sendFile(const std::string& file_path) {
    File file_;

    file_.open(file_path, std::ios::binary | std::ios::in);

    char buffer[BUFFER_SIZE];
    while (true) {
        std::size_t bytesTransferred = file_.read(buffer, sizeof(buffer));
        if (bytesTransferred == 0) {
            break;
        }
        boost::asio::write(socket_, boost::asio::buffer(buffer, bytesTransferred));
        std::cout << "Sent " << bytesTransferred << " bytes." << std::endl;
    }

    std::cout << "Client::sendFile: File sent successfully!\n";
}

void Client::connect(const std::string& host, const std::string& port) {
    boost::asio::connect(socket_, resolver_.resolve(host, port));
    std::cout << "Client::connect: Connected to server at " << host << ":" << port << std::endl;
}