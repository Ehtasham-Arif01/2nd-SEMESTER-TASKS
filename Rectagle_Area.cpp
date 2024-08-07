#include<iostream>
using namespace std;

// Class definition
class Rectangle {
private:
    int length;
    int width;

public:
    // Default constructor
    Rectangle() {
        length = 0;
        width = 0;
    }

    // Parameterized constructor
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    // Getter functions
    int getLength() {
        return length;
    }

    int getWidth() {
        return width;
    }
};

int main() {
    int length, width;
    cout << "ENTER LENGTH AND WIDTH: " << endl;
    cin >> length >> width;

    // Creating objects
    Rectangle r1;  // Default constructor
    Rectangle r(length, width);  // Parameterized constructor

    cout << "Length of the rectangle is: " << r.getLength() << endl;
    cout << "Width of the rectangle is: " << r.getWidth() << endl;

    return 0;
}
