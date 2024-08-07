#include<iostream>
using namespace std;

class base {
    protected:
        int age;
    public:
        base(int n = 0): age(n) {} // Default parameter for constructor

        void identify() {
            cout << "Enter AGE: ";
            cin >> age;
        }
};

class derive: public base {
    public:
        int add;
        int k;
        derive(int n = 0): base(n) {} // Default parameter for constructor

        //calling base function
        using base::identify;


        void identify(int ki) {
            base::identify();
            add = age + 5;
            cout << "Age: " << age << ", Add: " << add << endl;
        }
};

int main() {
    derive d1;
    d1.identify(10);

    d1.identify();

    return 0;
}
