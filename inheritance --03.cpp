#include<iostream>
using namespace std;
class student
{
protected:
string name;
int marks;
public:
student(string name_st, int marks)
{
this->name=name_st;
this->marks=marks;
}

void display_st()
{
cout<<"Name: "<<name<<" Marks: "<<marks<<endl;
}
};
class teacher
{
protected:
string name;
int salary;
public:
teacher(string name, int salary)
{
this->name=name;
this->salary=salary;
}

void display_te()
{
    cout<<"Name: "<<name<<" Salary: "<<salary<<endl;
}
};
class TA:public student, public teacher
{
public:
TA(string name,string name_st, int marks, int salary): student(name_st, marks), teacher(name, salary)
{
}
void display()
{
cout<<"Name: "<<student::name<<" Marks: "<<marks<<" Salary: "<<salary<<endl;
}
};

int main()
{
TA t("Ali","HAMZZZZA", 90, 10000);
t.display();
t.display_st();
t.display_te();
}