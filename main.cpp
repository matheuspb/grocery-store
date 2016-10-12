#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "grocery_store.hpp"

std::vector<std::string> readInputFile();

int main() {
    structures::CircularList<Cashier> cashiers;

    std::vector<std::string> parameters = readInputFile();
    for (auto i = 0; i < std::stoi(parameters[3]); ++i) {
        std::stringstream read_line(parameters[i+4]);
        std::string cashier_name;
        int salary, efficiency;
        read_line >> cashier_name >> efficiency >> salary;
        std::cout << efficiency << "\n";
        Cashier newCashier(efficiency, salary, cashier_name);
        cashiers.push_front(newCashier);
    }

    GroceryStore store(std::stoi(parameters[1])*3600, std::stoi(parameters[2]), std::move(cashiers));
    store.simulate();
    store.showResults();
}

std::vector<std::string> readInputFile() {
    auto output_vector = std::vector<std::string>{};
    std::ifstream file;
    file.open("input_parameters.txt");
    while (!file.eof()) {
        char read_line[80];
        file.getline(read_line, 80);
        if (read_line[0] != '#')
        {
           output_vector.push_back(read_line);
        }
    }
    return output_vector;
}
