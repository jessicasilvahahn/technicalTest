#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <fstream>

class File {
public:
    File(){};
    ~File();
    void open(std::string filename, std::ios::openmode mode);
    void write(const char* data, std::size_t length);
    std::size_t read(char* buffer, std::size_t size);
    void close();
    void flush();
private:
    std::fstream stream_;
};

#endif