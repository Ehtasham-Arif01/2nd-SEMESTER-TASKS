#include<iostream>
using namespace std;

class a{
public:
void show()
{
    cout<<"HELLO  "<<endl;
}
};

class b:public a{

};

class c:public b{
    public:
void show()
{
    cout<<"HELLO  CCCC "<<endl;
}
};

int main()
{
c obj;
obj.c::show();

return 0;
}