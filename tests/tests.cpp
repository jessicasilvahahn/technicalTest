#include <gtest/gtest.h>
#include "../client/Client.hpp"
#include <cstdlib>
#include <string>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
const std::string DIR = "/data/technicalTest/tests/";

bool isEmpty(const fs::path& dir)
{
    return fs::is_empty(dir);
}

void removeAllFiles(const fs::path& dir)
{
    if (fs::exists(dir) && fs::is_directory(dir))
    {
        for (fs::directory_iterator it(dir), end; it != end; ++it)
        {
            fs::remove(*it);
        }
        
    }
    else
    {
        std::cerr << "The specified path is not a directory." << std::endl;
    }
}

void sendFile(std::string filePath)
{
    const char* portChar = getenv("PORT");
    const char* hostChar = getenv("HOST");
    std::string port(portChar);
    std::string host(hostChar);
    Client client(host, port);
    client.sendFile(filePath);
}


TEST(sendFile, SimpleOne)
{
    try 
    {
        std::string filePath = DIR + "sample/file.txt";
        sendFile(filePath);
        ASSERT_FALSE(isEmpty(DIR + "data"));
        
    } 
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

TEST(sendFile, BigOne)
{
    std::string filePath = DIR + "sample/resume.pdf";
    sendFile(filePath);
    ASSERT_FALSE(isEmpty(DIR + "data"));
}

int main(int argc, char **argv) {
    if(!isEmpty(DIR + "data"))
    {
        removeAllFiles(DIR + "data");
    }
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}