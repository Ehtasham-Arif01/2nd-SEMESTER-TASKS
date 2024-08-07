#include<iostream>
using namespace std;

class circle{
    int *radius;
    public:

//you have to clear about dynamic array+dynamic
    circle()
    {
        radius = new int (0);
    }

//user defined copy constructer.
//making deep copy constructer
    circle (const circle &r)
    {
        cout<<"CONSTRUCTER CALLING "<<endl;
        radius=new int (*(r.radius));

    }

    
    void set_radius(int r)
    {
        *radius=r;
    }

    void display()
    {
        cout<<"RADIUS IS :: "<<*radius<<endl;
    }

    //destructer
    ~circle()
    {
        cout<<"DESTRUCTER IS CALLING "<<endl;
        delete radius;
    }

};

int main()
{
    circle c1;
    c1.set_radius(4);
    cout<<"RADOIS 1 "<<endl;
    c1.display();

    circle c2;
    cout<<"RADOIS 2 "<<endl;
    c2=c1;
    c2.display();

    //problem with shallow copy.
    c1.set_radius(10);
    cout<<"RADOIS 1 "<<endl;
    c1.display();
    cout<<"RADOIS 2 "<<endl;
    c2.display();
}