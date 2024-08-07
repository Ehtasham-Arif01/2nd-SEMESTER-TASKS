#include<iostream>
using namespace std;

class XYZ{

private://all things below it are private...
int a;//Data members
int b;
int c;

public://Functions are kept public usually
void get_data()//MEmber functions 
{

cout<<"ENTER A :";
cin>>a;
cout<<"ENTR B  :";
cin>>b;
cout<<"ENTER C: ";
cin>>c;

}
void display_data()
{
cout<<"A ===> "<<a<<endl;
cout<<"B ===> "<<b<<endl;
cout<<"C ===> "<<c<<endl;
}



};

int main()
{

//object of the given class.
//class name  name_of_object.
XYZ xyz;

//Accessing the member functions of the class.

xyz.get_data();
xyz.display_data();



return 0;
}