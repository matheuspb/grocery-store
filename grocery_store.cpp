#include "cashier.hpp"
#include "client.hpp"

int main()
{
    Cashier *caixa = new Cashier(1, 400.0, "Dimito");
    Client* aux = new Client(0, 0, caixa->cashierEfficiency());
    caixa->insertClient(*aux);
    std::cout << caixa->totalGain() << "\n";
    caixa->insertClient(*aux);
    std::cout << caixa->totalGain() << "\n";
}
