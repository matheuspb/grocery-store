#include <iostream>
/*
 *  TODO: Fila de clientes
 */
class Cashier
{
    public:
        Cashier(int, double, std::string);

    private:
        int cashierEfficiency_;
        double salary_;
        std::string ID_;
};
