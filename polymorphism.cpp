#include<iostream>
#include<string>

using namespace std;

class parent{
public:
virtual void show();

};
class child:public parent{
    public:
     void show()
    {
        cout<<"\nBASE CLASS \n";
    }
};
int main()
{
parent p; 
parent *ptr;
child c;
ptr=&c;
ptr->show();

return 0;
}