class Client
{
    public:
        Client(double, double, int);
        bool paymentMethod();
        bool queueChoice();
        double totalItemsValue();
        double purchaseTime(int);

    private:
        bool payWithMoney_, searchSmallestQueue_;
        int items_;
        double totalItemsValue_, arrivalTime_, departureTime_;
};
