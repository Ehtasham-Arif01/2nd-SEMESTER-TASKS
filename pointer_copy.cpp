#include<iostream>
using namespace std;


class circle{

int *radius;
public:
//default constructer
circle()
{
    radius=new int;
}
//setter
void set_radius(int r)
{
    *radius=r;
}
//display function
void display()
{
    cout<<"RADIUS IS ;"<<*radius<<endl;
}
//user defined copy constructer.
//deep copy
circle(const circle &c1)
{
    radius = new int(*(c1.radius));
}

};

//main function
int main()
{
    circle c1;
    c1.set_radius(2);
    c1.display();


    //obj2
    circle c2=c1;
    c2.display();


    c2.set_radius(200);

    c1.display();
    c2.display();

    return 0;
}