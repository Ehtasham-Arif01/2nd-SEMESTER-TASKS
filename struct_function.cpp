#include<iostream>
using namespace std;
struct employe{
int age;
string name;
int salary;
};

void diaplay(employe);

int main()
{
employe emp={1,"khan",20000};
diaplay(emp);
return 0;
}

void diaplay(employe e)
{
    cout<<"THE NAME IS :"<<e.name<<endl;
    cout<<"THE AGE IS :"<<e.age<<endl;
    cout<<"THE SALRY is :"<<e.salary<<endl;
}
