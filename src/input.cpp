#include "input.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>

namespace input {

    std::vector<std::string> readInputFile(std::string path)
    {
        std::vector<std::string> output_vector;
        std::ifstream file;
        file.open(path);
        if (!file.is_open())
            throw std::runtime_error("File not found or couldn't be opened");
        while (!file.eof()) {
            std::string read_line;
            std::getline(file, read_line);
            if (read_line[0] != '#' && read_line.length() > 0
                    && read_line[0] != ' ') {
                output_vector.push_back(read_line);
            }
        }
        return output_vector;
    }

    std::vector<std::string> readParametersInput()
    {
        std::vector<std::string> output_vector;
        std::string read_line;
        std::cout << "Grocery store name:" << "\n";
        std::getline(std::cin, read_line);
        output_vector.push_back(read_line);
        std::cout << "Time to be simulated (hours):" << "\n";
        std::getline(std::cin, read_line);
        output_vector.push_back(read_line);
        std::cout << "Pace that clients are created (seconds):" << "\n";
        std::getline(std::cin, read_line);
        output_vector.push_back(read_line);
        std::cout << "Number of cashiers:" << "\n";
        std::getline(std::cin, read_line);
        output_vector.push_back(read_line);
        for (auto i = 0; i < std::stoi(output_vector[3]); ++i) {
            std::cout << "Cashier info (name efficiency salary):" << "\n";
            std::getline(std::cin, read_line);
            output_vector.push_back(read_line);
        }
        return output_vector;
    }

}
