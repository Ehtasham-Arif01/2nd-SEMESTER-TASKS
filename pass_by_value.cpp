#include<iostream>
using namespace std;

int add(int x);

int main()
{
    int data =10;
    data = add(data);
    cout<<"VALUE IS :"<<data;

    return 0;
    
}

int add(int x)
{
    int input;
    cout<<"enter valyre :";
    cin>>input;
    x=x+input;
    return x;
}