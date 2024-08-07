#include<iostream>
using namespace std;
class complex{
double real;
double imag;
public:
complex(double r, double i):real(r),imag(i){}

double getreal()
{
    return real;
}

double get_imag()
{
    return imag;
}
//operarter overloading as memeber function
// complex operator+(complex &obj1)
// {
//     double r= real + obj1.real;
//     double i= imag + obj1.imag;
//     return (complex(r, i));
// }
};

//implementin as non member function
complex operator+(complex &obj1,complex &obj2)
{
    double r= obj1.getreal() + obj2.getreal();
    double i=obj1.get_imag() + obj2.get_imag();
    return (complex(r, i));
}


int main()
{
complex c1(3.4,6);
cout<<"\n\n";
cout<<c1.getreal();
cout<<"\n\n";
cout<<c1.get_imag();
cout<<"\n\n";
complex c2(8,4);
cout<<"\n\n";
cout<<c2.getreal();
cout<<"\n\n";
cout<<c2.get_imag();
cout<<"\n\n";



complex c3=c1+ c2;
cout<<c3.getreal();
cout<<"\n\n";
cout<<c3.get_imag();

return 0;

}