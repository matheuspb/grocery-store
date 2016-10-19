#include "input.hpp"
#include <stdexcept>

namespace input {

    std::vector<std::string> readInputFile(std::string path)
    {
        using namespace std;
        vector<string> output_vector;
        ifstream file;
        file.open(path);
        if (!file.is_open())
            throw std::runtime_error("File not found or couldn't be opened");
        while (!file.eof()) {
            string read_line;
            getline(file, read_line);
            if (read_line[0] != '#' && read_line.length() > 0
                    && read_line[0] != ' ') {
                output_vector.push_back(read_line);
            }
        }
        return output_vector;
    }

    std::vector<std::string> readParametersInput()
    {
        using namespace std;
        auto output_vector = vector<string>{};
        string read_line;
        cout << "Nome do supermercado:" << "\n";
        getline(cin, read_line);
        output_vector.push_back(read_line);
        cout << "Tempo a ser simulado:" << "\n";
        getline(cin, read_line);
        output_vector.push_back(read_line);
        cout << "Tempo de chegada de clientes:" << "\n";
        getline(cin, read_line);
        output_vector.push_back(read_line);
        cout << "Numero de caixas:" << "\n";
        getline(cin, read_line);
        output_vector.push_back(read_line);
        for (auto i = 0; i < stoi(output_vector[3]); ++i) {
            cout << "Informacoes do caixa(nome eficiencia salario):" << "\n";
            getline(cin, read_line);
            output_vector.push_back(read_line);
        }
        return output_vector;
    }

}
