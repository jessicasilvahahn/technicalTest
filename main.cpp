#include <iostream>
#include <thread>
#include <vector>
#include "server/Server.hpp"
#include "client/Client.hpp"

int main(int argc, char* argv[]) 
{
    if (argc < 1) {
        std::cerr << "Usage: <server|client> <port|host> [numThreads|file_path]\n";
        return 1;
    }

    std::string mode = argv[1];

    if (mode == "server") {
        if (argc < 6) {
            std::cerr << "Usage: server <port> <numThreads> <timeout> <bufferSize> <prefix>" << std::endl;
            return 1;
        }

        try {
            int port  = std::atoi(argv[2]);
            int numThreads = std::atoi(argv[3]);
            int timeout = std::atoi(argv[4]);
            std::size_t maxFileSize = std::atoi(argv[5]);
            std::string prefix = argv[6];
            boost::asio::io_context io_context;

            // Start the server
            Server server(io_context, port, maxFileSize, timeout, prefix);

            // Create a thread pool
            std::vector<std::thread> thread_pool;
            for (int i = 0; i < numThreads; ++i) {
                thread_pool.emplace_back([&io_context] { io_context.run(); });
            }

            // Join all threads
            for (auto& thread : thread_pool) {
                thread.join();
            }
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } 
    else if (mode == "client")
    {
        if (argc < 4) {
            std::cerr << "Usage: client <host> <port> <file_path>" << std::endl;
            return 1;
        }

        std::string host = argv[2];
        int port = std::atoi(argv[3]);
        std::string file_path = argv[4];

        try {
            // Start the client and send the file
            Client client(host, std::to_string(port));
            client.sendFile(file_path);
        }
        catch (std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    else
    {
        std::cerr << "Invalid mode. Please use 'server' or 'client'" << std::endl;
        return 1;
    }

    return 0;
}