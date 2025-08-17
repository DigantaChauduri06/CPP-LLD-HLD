#include<iostream>
#include<mutex>
using namespace std;

class Singleton {
    Singleton() {
        cout << "New Object Created" << endl;
    }
    static Singleton* instance;
    static mutex mtx;
    public:
        static Singleton* getInstance() {
            if (instance == nullptr) {
                lock_guard<mutex> lock(mtx); //  Locking the thread
                if (instance == nullptr) { // lets say we have multiple threads sitting on line 14 and some thread got priority and create instance but when its unlocked if we didn't put this check it will create another instance as well, to avoid this we will double check 
                    instance = new Singleton();
                }
            }
            return instance;
        }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main ()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    // s1->getInstance();

  return 0;
}


/**
 * Logging system
 * Database Connection
 * Config manager
 */