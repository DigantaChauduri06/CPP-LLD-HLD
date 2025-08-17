#include<iostream>
using namespace std;

class Singleton {
    Singleton() {
        cout << "New Object Created" << endl;
    }
    static Singleton* instance;
    public:
        static Singleton* getInstance() {
            return instance;
        }
};

Singleton* Singleton::instance = new Singleton();

int main ()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    // s1->getInstance();

  return 0;
}


// Not practical because
/**
 * This will ensure it will create the object before main() calls, so if it is memory intesive then applicaion will be slow at first, or maybe that object is not getting used by anything in that case, memory will get wasted.
 */