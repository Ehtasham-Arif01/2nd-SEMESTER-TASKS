#include<iostream>
using namespace std;
class person{
    private:
    string name;
    int age;
    public:

    void setname()
    {
        cout<<"ENTER NAME :";
        cin>>name;
        cout<<"ENTER AGE  :";
        cin>>age;
    }

    void getname()
    {
        cout<<"NAME IS : "<<name<<endl;
        cout<<"AGE IS  : "<<age<<endl;
    }

};


class student:public person{
private:
int semester;
float gpa;
public:
void setgpa()
{
    person::setname();
    cout<<"ENTER SEMESTER : ";
    cin>>semester;
    cout<<"ENTER GPA : ";
    cin>>gpa;

}

void getgpa()
{
    person::getname();
    cout<<"SEMESTER IS : "<<semester<<endl;
    cout<<"GPA IS :  "<<gpa<<endl;
}

};
class Employe:public person{
int grade;
float salary;
public:
void setsal()
{
    person::setname();
    cout<<"ENTER grade : ";
    cin>>grade;
    cout<<"ENTER salary : ";
    cin>>salary;

}

void getsal()
{
    person::getname();
    cout<<"grade IS : "<<grade<<endl;
    cout<<"salary IS :  "<<salary<<endl;
}
};

int main()
{
cout<<"\n\n ////////////  SCHOOL RECORD MANAGEMENT SYSTEM  ////////////\n\n";
int choice;

student s1;
Employe e1;

do{

    cout<<"\n\n1) ADD STUDENT INFORMATION "<<endl;
    cout<<"2) ADD TEACHER INFORMATION "<<endl;
    cout<<"3) DISPLAY STUDENT INFORMATION "<<endl;
    cout<<"4) DISPLAY TEACHER INFORMATION "<<endl;
    cout<<"5) EXIT "<<endl;
    cin>>choice;
switch(choice)
{
    case 1:
    {
      s1.setgpa();

        break;
    }
    case 2:
    {
        e1.setsal();

          break;
    }
    case 3:
    {
        s1.getgpa();

          break;
    }
    case 4:
    {
        e1.getsal();

          break;
    }
    case 5:
    {
      break;
    }
    default:
    {
        cout<<"ERROR!\nPLEASE ENTER VALID CHOICE \n"<<endl;

    }
}
}while(choice!=5);

return 0;
}