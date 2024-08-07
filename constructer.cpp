#include<iostream>
using namespace std;

//class
class Rectangle{
private:
int length;
int width;

public:
//default contructer.
//constructer is always kept public:
Rectangle()
{
length=0;
width=0;
}

//parameterized constructer.
Rectangle(int a, int w)
{
    length= a;
    width= w;
}

//getter.
int getlength()
{
    return length;
}

int getwidth(){
    return width;
}


//setters
void setlength(int l){
    length=l;

}

void setwidth(int b){
    width=b;
}
//are member fuction..

int cal_area()
{
    int area=length*width;
    return area;
}
};//end of class

//passing an object to function by value
int calArea(Rectangle r)
{
    int area=r.getlength() * r.getwidth();
    return area;
}
int main()
{

    int length,width;
    cout<<"ENTER LENGTH :";
    cin>>length;
    cout<<"ENTER WIDTH :";
    cin>>width;
    Rectangle r1(length,width);
    cout<<"THE REA OF RETANGLE IS :"<<calArea(r1)<<endl;

//Rectangle r1(length,width);
//r1.setlength(length);
//r1.setwidth(width);

cout<<"THE VALUE OF LENGTH IS "<<r1.getlength()<<endl;
cout<<"THE WIDTH IS      S : "<<r1.getwidth();

//calling the area function.
cout<<endl<<"the rae of the given raectagle is "<<r1.cal_area()<<endl;
return 0;
}