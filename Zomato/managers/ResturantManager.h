#ifndef RESTURNATMANAGER_H
#define RESTURNATMANAGER_H

#include<iostream>
#include "../models/Resturant.h"
#include<mutex>
#include<string>
#include<algorithm>
using namespace std;

class ResturantManager {
private:
    vector<Resturant *> resturants;
    static ResturantManager* instance;
    static mutex mutx;
    ResturantManager() {

    }
public:
    static ResturantManager* getInstace() {
        if(!instance) {
            lock_guard<mutex> lock(mutx);
            if(!instance) { // Thread Safe
                instance = new ResturantManager();
            }
        }
        return instance;
    }

    void addResturant(Resturant* r) {
        resturants.push_back(r);
    }

    vector<Resturant*> searchByLocation(string &loc) {
        vector<Resturant*> result;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);

        for (auto &r: resturants) {
            string rl = r->getLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if (rl == loc) {
                result.push_back(r);
            }
        }
        return result;

    }
};

ResturantManager* ResturantManager::instance = nullptr;
mutex ResturantManager::mutx;


#endif
