#include<iostream>
using namespace std;

class base{
public:
int age;
string name;
public:
base(int a,string n):age(a),name(n){}

int geta()
{
    return age;
}
string getn()
{
    return name;
}


};

class derived{
    int year;
    base arr;
    public:
    derived(int a,string n,int y):arr(a,n),year(y){}
    void display()
{
    cout<<"NAME IS : "<<geta()<<endl;
    cout<<"AGE IS  : "<<getn()<<endl;
}

};

int main()
{
derived d(2,"HAMZZA",3004);
d.display();
}