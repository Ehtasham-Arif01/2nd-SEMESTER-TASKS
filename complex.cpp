#include<iostream>
using namespace std;

//complex class 
class complex{
    int real;
    int imag;
    public:
    
    //default constructer
    complex()
    {
        //default constructer
    }

    //parameterized constructer
    complex(int r,int i):real(r),imag(i){}

    //friend function declaration.
    friend complex Add_complex(complex c1,complex c2);

    //dsiplay function
    void display()
    {
        cout<<"( "<<real<<" + "<<imag<<"i ) "<<endl;
    }
};

//Add_complex function definition.
complex Add_complex(complex c1,complex c2)
{
complex result;
result.real=c1.real + c2.real;
result.imag=c1.imag + c2.imag;
return result;
}

//main function.
int main()
{
//objects of complex class and passing values.
complex c1(3,4);
complex c2(6,2);

//passing the objects to Add_complex function.
complex c3=Add_complex(c1,c2);

//diplaying values..
cout<<"\n  1)  ";
c1.display();
cout<<"  2)  ";
c2.display();
cout<<"SUM : ";
c3.display();
cout<<endl;

return 0;

}