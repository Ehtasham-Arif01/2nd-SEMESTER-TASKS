#include<iostream>
using namespace std;

struct student{
    string name;
    int gpa;
    int marks;
};

int main()
{
student s[3];  // it is the array of the structure..

//for in itializaton 
for (int i=0;i<3;i++)
{
    cout<<"ENTER YOUR NAME :"<<endl;
    cin>>s[i].name;
    cout<<"ENTER YOUR GPA  :"<<endl;
    cin>>s[i].gpa;
    cout<<"ENTER YOUR MARKS :"<<endl;
    cin>>s[i].marks;
    cout<<"\n\n";
}

//for printing 

for (int i=0;i<3;i++)
{
    cout<<"THE NAME IS :"<<s[i].name<<endl;
    cout<<"THE GPA IS  :"<<s[i].gpa<<endl;
    cout<<"THE MARKS ARE :"<<s[i].marks<<endl;
    cout<<"\n\n";
}
}