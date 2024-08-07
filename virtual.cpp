#include <iostream>
using namespace std;

class account {
protected:
    int account_number;
    float account_balance; // New member variable
public:
    // Constructor
    account(int number, float balance) : account_number(number), account_balance(balance) {}

    // Member function to display account details
    virtual void display() {
        cout << "Account Number: " << account_number << endl;
        cout << "Account Balance: $" << account_balance << endl; // Displaying new member variable
    }
};

class checking : public virtual account {
protected:
    float checking_balance;
public:
    // Constructor
    checking(int number, float balance, float checking_balance) : account(number, balance), checking_balance(checking_balance) {}

    // Member function to display checking account details
    void display() override {
        account::display();
        cout << "Checking Balance: $" << checking_balance << endl;
    }
};

class savings : public virtual account {
protected:
    float savings_balance;
public:
    // Constructor
    savings(int number, float balance, float savings_balance) : account(number, balance), savings_balance(savings_balance) {}

    // Member function to display savings account details
    void display() override {
        account::display();
        cout << "Savings Balance: $" << savings_balance << endl;
    }
};

class ibc : public checking, public savings {
public:
    // Constructor
    ibc(int number, float balance, float checking_balance, float savings_balance) 
        : account(number, balance), checking(number, balance, checking_balance), savings(number, balance, savings_balance) {}

    // Member function to display ibc account details
    void display() override {
        cout << "IB Account Details:" << endl;
        checking::display();
        savings::display();
    }
};

int main() {
    // Creating an ibc object
    ibc my_ibc(123456, 15000.0, 5000.0, 10000.0);

    // Displaying ibc account details
    my_ibc.display();

    return 0;
}
