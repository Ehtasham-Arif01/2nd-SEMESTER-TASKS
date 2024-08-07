#include<iostream>
using namespace std;

// Forward declaration of classB since it's used in the friend declaration in classA
class classB;

class classA {
private:
    int x; // Moved x to private since it's accessed in the friend function
public:
    classA(int A): x(A) {} // Constructor to initialize x
    friend int Add(classA a, classB b); // Friend function declaration
};

class classB {
private:
    int y; // Moved y to private since it's accessed in the friend function
public:
    classB(int B): y(B) {} // Constructor to initialize y
    friend int Add(classAa, classB b); // Friend function declaration
};

// Friend function definition
int Add(classA a, class b) {
    return (a.x + b.y);
}
int main() {
    classA a(6);
    classB b(5);

    cout << "Result of addition: " << Add(a, b) << endl; // Call to the friend function
    return 0;
}
