#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

class Client
{
    public:
        Client(int);

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
        int purchaseTime(int);
        double totalPurchaseValue();
        void deparureTime(int);
        bool payWithMoney();

    private:
        bool payWithMoney_, searchSmallestQueue_;
        int items_, departureTime_, arrivalTime_;
        double totalPurchaseValue_;
};
#endif
