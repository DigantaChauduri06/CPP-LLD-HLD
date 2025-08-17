#ifndef ORDER_H
#define ORDER_H

#include<string>
#include<iostream>
#include<Resturant.h>
using namespace std;

class Order {
private:
    int id;
    Resturant
    string address;
    Cart* cart;
public:
    User(int userId, string name, string address): userId(userId), name(name), address(address) {
        cart = new Cart();
    }

    ~User() {
        cout << "Deleting the user means you are also deleting the cart associated " << endl;
        delete cart;
    }

    string getName() const {
        return name;
    }
    string getAddress() const {
        return address;
    }
    Cart* getCart() const {
        return this->cart;
    }

};


#endif