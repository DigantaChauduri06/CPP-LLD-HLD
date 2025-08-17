#ifndef USER_H
#define USER_H

#include<string>
#include<iostream>
using namespace std;

class User {
private:
    int userId;
    string name;
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