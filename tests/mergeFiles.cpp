#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <dirent.h>
#include <sys/stat.h>

void merge_files(const std::vector<std::string>& input_files, const std::string& output_file) {
    std::ofstream output(output_file, std::ios::binary);
    if (!output) {
        std::cerr << "Failed to open output file: " << output_file << std::endl;
        return;
    }

    for (const auto& input_file : input_files) {
        std::ifstream input(input_file, std::ios::binary);
        if (!input) {
            std::cerr << "Failed to open input file: " << input_file << std::endl;
            continue;
        }

        // Copy the contents of the input file to the output file
        output << input.rdbuf();
        input.close();
    }

    output.close();
    std::cout << "Files merged successfully into: " << output_file << std::endl;
}

std::vector<std::string> get_files_from_directory(const std::string& directory) {
    std::vector<std::string> files;
    DIR* dir = opendir(directory.c_str());
    if (dir == nullptr) {
        std::cerr << "Failed to open directory: " << directory << std::endl;
        return files; // Return empty list if directory cannot be opened
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_type == DT_REG) { // Regular file
            std::string file_name = directory + "/" + entry->d_name;
            files.push_back(file_name);
        }
    }
    closedir(dir);
    return files;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: merge_files <directory> <output_file>\n";
        return 1;
    }

    std::string directory = argv[1];
    std::string output_file = argv[2];

    // Get all files from the specified directory
    std::vector<std::string> input_files = get_files_from_directory(directory);

    // Merge the files
    merge_files(input_files, output_file);

    return 0;
}