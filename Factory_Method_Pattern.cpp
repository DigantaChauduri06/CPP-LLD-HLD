#include<iostream>
using namespace std;

// Abstract Class
class Burger {
  public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

// Burger Variants for BK
class BasicBurger : public Burger{
  public:
    void prepare() override {
        cout << "Preparing Burger King Basic Burger 🍔" << endl;
    }
};
class StanderdBurger : public Burger{
  public:
    void prepare() override {
        cout << "Preparing Burger King Standard Burger 🍔" << endl;
    }
};
class GourmetBurger : public Burger{
  public:
    void prepare() override {
        cout << "Preparing Burger King Gourmet Burger 🍔" << endl;
    }
};

// Burger Variants for McDonald's
class BasicBurger2 : public Burger{
  public:
    void prepare() override {
        cout << "Preparing McDonald's Basic Burger 🍔" << endl;
    }
};
class StanderdBurger2 : public Burger{
  public:
    void prepare() override {
        cout << "Preparing McDonald's Standard Burger 🍔" << endl;
    }
};
class GourmetBurger2 : public Burger{
  public:
    void prepare() override {
        cout << "Preparing McDonald's Gourmet Burger 🍔" << endl;
    }
};

// Abstract Factory
class BurgerFactory {
  public:
    virtual Burger* createBurger(string burgerType) = 0;
    virtual ~BurgerFactory() = default;
};

// Burger King Factory
class BKFactory : public BurgerFactory {
    public:
        Burger* createBurger(string burgerType) override {
            if (burgerType == "BasicBurger") {
                return new BasicBurger();
            } else if(burgerType == "StanderedBurger") {
                return new StanderdBurger();
            } else if (burgerType == "GourmetBurger"){
                return new GourmetBurger();
            } else {
                cout << "Unknown burger type in Burger King Factory!" << endl;
                return nullptr;
            }
        }
};

// McDonald's Factory
class MacDFactory : public BurgerFactory {
    public:
        Burger* createBurger(string burgerType) override {
            if (burgerType == "BasicBurger") {
                return new BasicBurger2();
            } else if(burgerType == "StanderedBurger") {
                return new StanderdBurger2();
            } else if (burgerType == "GourmetBurger"){
                return new GourmetBurger2();
            } else {
                cout << "Unknown burger type in McDonald's Factory!" << endl;
                return nullptr;
            }
        }
};

int main ()
{
    string type = "StanderedBurger";

    cout << "Customer entered Burger King 🍔" << endl;
    BurgerFactory *bf = new BKFactory();
    Burger* burger = bf->createBurger(type);
    if (burger) burger->prepare();

    cout << "\nCustomer entered McDonald's 🍟" << endl;
    BurgerFactory *bf2 = new MacDFactory();
    Burger* burger2 = bf2->createBurger(type);
    if (burger2) burger2->prepare();

    // cleanup
    delete burger;
    delete burger2;
    delete bf;
    delete bf2;

    return 0;
}
