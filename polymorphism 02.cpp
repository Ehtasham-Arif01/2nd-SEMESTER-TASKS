#include <iostream>
//using math's built-in functions so using <cmath>
#include<cmath>
using namespace std;

// class Shapes
class Shapes {
public:
    //default constructer
    Shapes(){};
    virtual float area() const = 0; 
    // destructor
    ~Shapes(){} 
};

// 2D shapes derived from Shapes
class TwoDShapes : public Shapes {
public:
    //default constructer
    TwoDShapes(){}
    virtual float area() const = 0;
    // Virtual destructor
    ~TwoDShapes() {}
};

// 3D shapes derived from Shapes
class ThreeDShapes : public Shapes {
public:
    //default constructer
    ThreeDShapes(){};
    virtual float area() const = 0;
    virtual float volume() const = 0; 
     // destructor
    ~ThreeDShapes() {}
};

// Circle class derived from TwoDShapes
class Circle : public TwoDShapes {
private:
    float radius;
public:
    // Constructor
    Circle(float r) : radius(r) {} 
    float area() const{
        return radius * radius;
    }
    ~Circle() {} // Destructor
};

// Square class derived from TwoDShapes
class Square : public TwoDShapes {
private:
    float side;
public:
    Square(float s) : side(s) {} // Constructor
    float area() const{
        return side * side;
    }
    ~Square() {} // Destructor
};

// Cube class derived from ThreeDShapes
class Cube : public ThreeDShapes {
private:
    float length, width, height;
public:
    Cube(float l, float w, float h) : length(l), width(w), height(h) {} // Constructor
    float area() const{
        return 2 * (length * width * height);
    }
    float volume() const{
        return length * width * height;
    }
    ~Cube() {} // Destructor
};

// Pyramid class derived from ThreeDShapes
class Pyramid : public ThreeDShapes {
private:
    float base, height;
public:
    // Constructor
    Pyramid(float b, float h) : base(b), height(h) {} 
    float area() const{
        return (2 * base * sqrt((base / 2) * (base / 2) + height * height));
    }
    float volume() const{
        return ((base * base * height) / 3);
    }
    ~Pyramid() {} // Destructor
};

int main() {
    // Array of pointers to TwoDShapes
    //with the help of array index initilizing the the circle and squre.
    TwoDShapes* array[2];
    array[0] = new Circle(5);
    array[1] = new Square(4);

    // Array of pointers to ThreeDShapes
        //with the help of array index initilizing the the cube and pyramind.
    ThreeDShapes* array_2[2];
    array_2[0] = new Cube(3, 4, 5);
    array_2[1] = new Pyramid(6, 8);

    // Display areas of 2D shapes
    cout << "\n2D Shapes:" <<endl;
    for (int i = 0; i < 2; ++i) {
        cout << "Area of Shape " << i+1 << ": " << array[i]->area()<<endl;
    }

    // Display areas and volumes of 3D shapes
    std::cout << "\n3D Shapes:" <<endl;
    for (int i = 0; i < 2; ++i) {
        cout << "Area of Shape " << i+1 << ": " <<array_2[i]->area()<<endl;
        cout << "Volume of Shape " << i+1 << ": " <<array_2[i]->volume()<<endl<<endl;
    }

    cout<<endl;
    // Delete dynamically allocated memory
    for (int i = 0; i < 2; ++i) {
        delete array[i];
        delete array_2[i];
    }

    return 0;
}
