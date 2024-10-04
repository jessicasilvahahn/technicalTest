#include "File.hpp"

File::~File()
{
    close();
}

void File::open(std::string filename, std::ios::openmode mode) {
    stream_.open(filename, mode);
    if (!stream_.is_open())
    {
        std::cerr << "File::open: Failed to open file: " << filename << std::endl;
    }
}
 
void File::write(const char* data, std::size_t length)
{
    if (stream_)
    {
        stream_.write(data, length);
    }
    else 
    {
        std::cerr << "File::write: File not open" << std::endl;
    }
}

std::size_t File::read(char* buffer, std::size_t size)
{
    stream_.read(buffer, size);
    return stream_.gcount();
}

void File::close()
{
    if (stream_.is_open())
    {
        stream_.close();
    }
}

void File::flush()
{

stream_.flush();

}
