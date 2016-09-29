class Client
{
    public:
        Client(double, double, int);

        //! Returns the 'paymant method' to a client.
        /*!
         *  Just return 'true' if the client will pay with money and 'false'if he will
         *pay with check, with a percentage of 80 to pay with money.
         */
        bool paymentMethod();

        //! Returns the queue choice criterion.
        /*!
         *  Returns 'true' if the client choose the queue by the number of people in,
         *and 'false' if the client choose the queue by the items number.
         */
        bool queueChoice();
        double allProductsCost();
        double purchaseTime(int);

    private:
        bool payWithMoney_, searchSmallestQueue_;
        int items_;
        double totalItemsValue_, arrivalTime_, departureTime_;
};
