#include<iostream>
using namespace std;


class Test{

    public:
    Test(){
        cout<<"Constructer calling :"<<endl;
    }

    ~Test(){
        cout<<"DESTRUCTER IS CALLING :"<<endl;
    }
};
int main()
{
Test t1;

return 0;
}