#include<iostream>
using namespace std;
struct Employe
{
    int salary=1000;
    string name="khan";

    //using function..
void print()
{
    cout<<"name is :"<<name<<endl;
    cout<<"slary is :"<<salary<<endl;
}
};

int main()
{
Employe e1;
e1.print();//Because the function is inside the structure so dot operator is used to fetch the function 
//print();

return 0;
}
