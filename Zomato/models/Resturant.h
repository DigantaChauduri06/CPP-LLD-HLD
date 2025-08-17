#ifndef RESTURANT_H
#define RESTURANT_H

#include<iostream>
#include<vector>
#include "MenuItem.h"
using namespace std;

class Resturant {
private:
    static int nextResturantId;
    int resturnatId;
    string name;
    string location;
    vector<MenuItem> menu; // 1 to meny
public:
    Resturant(const string& name, const string& location): name(name), location(location) {
        this->resturnatId = nextResturantId++;
    }
    ~Resturant() {
        cout << "Deleting Resturant: " << name << ", clearning out the menu as well" << endl;
        menu.clear();
    }

    string getName() {
        return name;
    }

    string getLocation() {
        return location;
    }
    void addMenuItem(const MenuItem &item) {
        menu.push_back(item);
    }

    const vector<MenuItem>& getMenu() const {
        return this->menu;
    }
};

int Resturant::nextResturantId = 0;

#endif