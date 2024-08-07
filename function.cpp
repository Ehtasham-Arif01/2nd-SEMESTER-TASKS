#include<iostream>
using namespace std;

class test {
    private:
    int a;
    int b;

    public:
//defult constructer
    test()
    {
         a=0;
         b=0;
    
    }
//parmeterrized constructer
    test(int x,int y)
    {
        a=x;
        b=y;

    }

int geta()
{
    return a;
}

int getb()
{
    return b;
}


void seta(int x)
{
a=x;
}

void setb(int y)
{
    b=y;
}

int addition()
{
    int total=a+b;
    return total;
}

int subtraction()
{
    int total=a-b;
    return total;
}

};
int main()
{
int a,b;
cout<<"ENTER A:";
cin>>a;
cout<<"ENTR B :";
cin>>b;

test r1(a,b);

cout<<"ADDITIONI S"<<r1.addition()<<endl;
cout<<"SUBTRACTION IS "<<r1.subtraction()<<endl;

return 0;
}