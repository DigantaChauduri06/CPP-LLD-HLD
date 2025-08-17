#include<iostream>
using namespace std;

class PaymentStrategy {
    public:
        virtual void pay() = 0;
};

class PaypalPay : public PaymentStrategy {
    public:
        void pay() override {
            cout << "I am using Paypal client" << endl;
        }
};

class UPIPay : public PaymentStrategy {
    public:
        void pay() override {
            cout << "I am using UPI client" << endl;
        }
};

class Client {
    public:
        Client(PaymentStrategy &paymentClient) {
            paymentClient.pay();
        }
    
};


int main ()
{
    PaymentStrategy *paypal = new PaypalPay();
    Client* client = new Client(*paypal);

  return 0;
}
