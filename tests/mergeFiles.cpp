#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <algorithm>

// Função para extrair a sequência numérica do nome do arquivo
int extract_sequence_number(const std::string& file_name)
{
    size_t last_underscore = file_name.find_last_of('_');
    size_t last_dot = file_name.find_last_of('.');
    
    if (last_underscore != std::string::npos && last_dot != std::string::npos && last_dot > last_underscore) {
        std::string sequence_str = file_name.substr(last_underscore + 1, last_dot - last_underscore - 1);
        return std::stoi(sequence_str);  // Converte a sequência numérica para int
    }
    return -1;  // Retorna -1 se não encontrar a sequência
}

void merge_files(const std::vector<std::string>& input_files, const std::string& output_file)
{
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

        // Copia o conteúdo do arquivo de entrada para o arquivo de saída
        std::cout << "Merging file: " << input_file << std::endl;
        output << input.rdbuf();
        input.close();
    }

    output.close();
    std::cout << "Files merged successfully into: " << output_file << std::endl;
}

std::vector<std::string> get_files_from_directory(const std::string& directory) 
{
    std::vector<std::string> files;
    DIR* dir = opendir(directory.c_str());
    if (dir == nullptr) {
        std::cerr << "Failed to open directory: " << directory << std::endl;
        return files;  // Retorna uma lista vazia se não puder abrir o diretório
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_type == DT_REG) {  // Arquivo regular
            std::string file_name = directory + "/" + entry->d_name;
            files.push_back(file_name);
        }
    }
    closedir(dir);
    return files;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: merge_files <directory> <output_file>\n";
        return 1;
    }

    std::string directory = argv[1];
    std::string output_file = argv[2];

    // Pega todos os arquivos do diretório especificado
    std::vector<std::string> input_files = get_files_from_directory(directory);

    // Ordena os arquivos com base na sequência numérica extraída do nome
    std::sort(input_files.begin(), input_files.end(), [](const std::string& a, const std::string& b) {
        return extract_sequence_number(a) < extract_sequence_number(b);
    });

    // Mescla os arquivos
    merge_files(input_files, output_file);

    return 0;
}