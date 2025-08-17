#ifndef MENUITEM_H
#define MENUITEM_H

#include<iostream>
using namespace std;

class MenuItem {
    int code;
    string name;
    double price;
public:
    MenuItem(const string& name, const double& price, const int& code): code(code), name(name), price(price) { }

    // Getter 
    int getCode() {
        return code;
    }
    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }

};


#endif
