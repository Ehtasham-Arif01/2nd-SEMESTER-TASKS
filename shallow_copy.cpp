#include<iostream>
using namespace std;

class sample{
int id;

public:
void init(int x)
{
    id=x;
}

void display()
{
    cout<<"ID : "<<id<<endl;
}
};

int main()
{
    sample obj1;
    obj1.init(10);
    obj1.display();
    cout<<endl;
    //cout<<"OBJECT 1 :"<<obj1.display()<<endl;
sample obj2;
obj2=obj1;
obj2.display();
cout<<endl;
}