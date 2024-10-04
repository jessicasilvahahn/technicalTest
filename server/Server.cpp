#include "Server.hpp"

Server::Server(boost::asio::io_context& io_context, int port, std::size_t maxFileSize, int timeout, std::string prefix)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)), 
    maxFileSize_(maxFileSize), 
    timeout_(std::chrono::seconds(timeout)), 
    prefix_(prefix)
{
    accept();
}

void Server::accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code error, tcp::socket socket) {
            if (!error) {
                std::string clientId = generateClientId(socket);
                std::cout << "Server::accept: Accepted connection from: " << clientId << std::endl;
                prefix_ += clientId;

                std::shared_ptr<boost::asio::ip::tcp::socket> socketPtr = std::make_shared<boost::asio::ip::tcp::socket>(std::move(socket));

                // Create a new DataReceiver instance for this session
                auto dataReceiver = std::make_shared<FileWriter>(socketPtr, prefix_, maxFileSize_, timeout_);

                // Create a new Session with the DataReceiver instance
                std::make_shared<Session>(dataReceiver)->start();
            }
            accept(); // Keep accepting more clients
        });
}

std::string Server::generateClientId(const tcp::socket& socket) {
    // Generate a unique ID for each client (e.g., IP address + port)
    return socket.remote_endpoint().address().to_string() + "_" + std::to_string(socket.remote_endpoint().port());
    
}
