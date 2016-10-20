// Copyright 2016 Lucas Bordignon and Matheus Bittencourt
#ifndef CLIENT_HPP
#define CLIENT_HPP

class Client {
public:
    Client() = default;
    Client(int);


    //! Returns the queue choice criterion.
    /*!
     *  Returns 'true' if the client choose the queue by the number of people in,
     *and 'false' if the client choose the queue by the items number.
     */
    bool searchSmallestQueue() const;
    bool payWithMoney() const;
    int purchaseTime(int) const;
    int totalPurchaseValue() const;

private:
    //! Returns the 'paymant method' to a client.
    /*!
     *  Just return 'true' if the client will pay with money and 'false'if he will
     *pay with check, with a percentage of 80 to pay with money.
     */
    int allProductsCost() const;

    bool payWithMoney_;
    bool searchSmallestQueue_;
    int items_;
    int arrivalTime_{0};
    int totalPurchaseValue_;
};

#endif
