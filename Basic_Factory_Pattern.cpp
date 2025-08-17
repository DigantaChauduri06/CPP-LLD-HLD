#include<iostream>
using namespace std;
// Absract Class
class Burger {
  public:
    virtual void prepare() = 0;
};

// Child Class 1
class BasicBurger : public Burger{
  public:
    void prepare() override {

    }
};
// Child Class 2
class StanderdBurger : public Burger{
  public:
    void prepare() override {

    }
};
// Child Class 3
class GourmetBurger : public Burger{
  public:
    void prepare() override {

    }
};

class BurgerFactory {
  public:
    Burger* createBurger(string burgerType) {
      if (burgerType == "BasicBurger") {
        return new BasicBurger();

      } else if(burgerType == "StanderedBurger") {
        return new StanderdBurger();

      } else if (burgerType == "GourmetBurger"){
        return new GourmetBurger();
      } else {
        return nullptr;
      }
    }
};


int main ()
{
  string type = "StanderedBurger";
  BurgerFactory *bf = new BurgerFactory();
  Burger* burger = bf->createBurger(type);
  burger->prepare();

  return 0;
}
