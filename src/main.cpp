#include <iostream>
#include <sstream>
#include "grocery_store.hpp"
#include "input.hpp"

int main(int argc, char* argv[]) {
    structures::CircularList<Cashier> cashiers;
    
    std::vector<std::string> parameters;
    if (argc == 2) {
        parameters = input::readInputFile(argv[1]);
    } else if (argc == 1) {
        parameters = input::readParametersInput();
    } else {
        std::cout << "Usage: ./main.out parameter_file\n";
        return 1;
    }

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

