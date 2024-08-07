#include<iostream>
using namespace std;
//creating class of name complex.
class complex{
private:
float real;
float imagenary;

public:
//default constructer.
complex()
{

}

//parameterized constructer.
complex(float real_input, float imagenery_input)
{
this->real=real_input;
this->imagenary=imagenery_input;
}

//setters.

void set(float real_input,float imagenery_input)
{
    this->real=real_input;
    this->imagenary=imagenery_input;
}

//getters.

float getreal(){
    return real;
}

float getimagenery()
{
    return imagenary;
}

//To display the complex number onject.
void disp()
{
cout<<endl<<"REAL NO IS : "<<real<<endl;
cout<<"IMAGENERY NO IS :"<<imagenary<<endl;
}

//to sum two complex number and return complex value.
complex complex_sum(complex c)
{
    complex result;
    result.real=real+ c.real;
    result.imagenary=imagenary + c.imagenary;

    return result;
}
};//endl of the class.

//MAin function()
int main()
{
    //creating the objects.
    complex c1(2,5);
    complex c2(8,-9);
    complex c3;

//displaying the complex numbers.
    cout<<"\nFIRST COMPLEX  NO ";
    c1.disp();
    cout<<"\nSECOND COMPLEX NO ";
    c2.disp();

//calling function to calculate the complex_sum.
    c3=c1.complex_sum(c2);

    cout<<"\nSUM OF TWO COMPLEX NUMBERS";
    c3.disp();
    cout<<endl;

    return 0;

}