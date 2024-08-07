#include <iostream>
using namespace std;
//array of object.
class Student{
    private:
    //data members.
    int marks;
    string name;
    float gpa;

    public:
    //default constructer.
    Student(){

    }
    //parameterized constructer.
    Student(int marks_stu,string name_stu,float gpa_stu)
    {
        this->marks=marks_stu;
        this->name=name_stu;
        this->gpa=gpa_stu;

    }
    //getter
    int getmarks()
    {
        return marks;

    }
string getname(){
    return name;

}

float getgpa()
{
    return gpa;
}

//setters.
void setmarks(int marks_stu)
{
    this->marks=marks_stu;
}

void setname(string name_stu)
{
    this->name=name_stu;
}

void setgpa(float gpa_stu)
{
    this->gpa=gpa_stu;
}
};//end of the class.

void display(Student s[])
{
    for(int i=0;i<3;i++)
    {
      cout<<"name  "<<i+1<<" ==> : "<<s[i].getname()<<endl;
      cout<<"marks "<<i+1<<" ==> : "<<s[i].getmarks()<<endl;
      cout<<"Gpa   "<<i+1<<" ==> : "<<s[i].getgpa()<<endl;

      cout<<"\n\n";
    }

}
int main()
{
Student s[3];
string name_stu;
int marks_stu;
float gpa_stu;

for(int i=0;i<3;i++)
{
cout<<"ENTER NAME OF STUDNET "<<i+1<<" : ";
cin>>name_stu;
s[i].setname(name_stu);
cout<<"ENTER MARKS : "<<i+1<<" : ";
cin>>marks_stu;
s[i].setmarks(marks_stu);
cout<<"ENTER GPA  : "<<i+1<<" : ";
cin>>gpa_stu;
s[i].setgpa(gpa_stu);
}

display(s);
return 0;
}