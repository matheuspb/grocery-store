#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

namespace input {
    std::vector<std::string> readInputFile(std::string);
    std::vector<std::string> readParametersInput();
}

#endif
