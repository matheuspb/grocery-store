#include <iostream>
#include <sstream>
#include "grocery_store.hpp"
#include "input.hpp"

int main() {
    structures::CircularList<Cashier> cashiers;

    std::vector<std::string> parameters = input::readInputFile();
    if (parameters.size() == 0) parameters = input::readParametersInput();
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

