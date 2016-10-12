#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "grocery_store.hpp"

std::vector<std::string> readInputFile() {
    auto output_vector = std::vector<std::string>{};
    std::ifstream file;
    file.open("input_parameters.txt");
    while (!file.eof()) {
        std::string read_line;
        std::getline(file, read_line);
        if (read_line[0] != '#' && read_line.length() > 0 && read_line[0] != ' ')
        {
            output_vector.push_back(read_line);
        }
    }
    return output_vector;
}

int main() {
    structures::CircularList<Cashier> cashiers;

    std::vector<std::string> parameters = readInputFile();
    for (auto i = 0; i < std::stoi(parameters[3]); ++i) {
        std::stringstream read_line(parameters[i+4]);
        std::string cashier_name;
        int salary, efficiency;
        read_line >> cashier_name >> efficiency >> salary;
        Cashier newCashier(efficiency, salary, cashier_name);
        cashiers.push_front(newCashier);
    }

    GroceryStore store(std::stoi(parameters[1])*3600, std::stoi(parameters[2]),
                        std::move(cashiers));
    store.simulate();
    store.showResults();
}

