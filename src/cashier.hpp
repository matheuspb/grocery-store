// Copyright 2016 Lucas Bordignon and Matheus Bittencourt
#ifndef CASHIER_HPP
#define CASHIER_HPP

#include <iostream>
#include "array_queue.hpp"
#include "client.hpp"

class Cashier {
public:
    Cashier() = default;
    Cashier(int, int, std::string);

    std::size_t clientsQueueSize() const;
    void insertClient(Client&);
    void removeFirstClient();
    void update();
    int averageGain() const;
    int totalGain() const;
    int netGain(int) const;
    int cashierEfficiency() const;
    int clientsQueueTime() const;
    int averageTime() const;
    std::string name() const;
    int salary() const;

private:
    int cashierEfficiency_{1};
    int totalClientsNumber_{0};
    int clientsQueueTime_{0};
    int actualClientTime_{1};
    int totalQueueTime_{0};
    int totalGain_{0};
    int salary_{0};
    std::string ID_{};
    structures::ArrayQueue<Client> clientsQueue_{10u};
};

#endif
