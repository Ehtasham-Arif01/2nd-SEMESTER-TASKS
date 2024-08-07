#include<iostream>
using namespace std;

class person{
    protected:
    string name;
    int age;
    string email;

    public:
    void setx()
    {
        cout<<"ENTER NAME : ";
        cin>>name;
        cout<<"EBTER AEG  :";
        cin>>age;
        cout<<"ETER E MAIL   :";
        cin>>email;

    }

void getx()
{
    cout<<"NAME IS :: "<<name<<endl;
    cin.ignore();
    //getline(cin>>ws,name);
    cout<<"AGE IS  :: "<<age<<endl;
    cout<<"EMAIL IS :: "<<email<<endl;
    getline(cin>>ws,email);
}

};

class student:public person{
protected:
float gpa;

public:
void set_gpa()
{
    cout<<"ENTER CgpA ; ";
    cin>>gpa;
    get_gpa();
}

void get_gpa()
{
    cout<<"CGPA IS ::  "<<gpa<<endl;
    }
};

class teacher:public person{
protected:
string qualification;

public:
void set_qualification()
{
    cout<<"ENTER qualification ; ";
    cin>>qualification;
    get_qualification();
}

void get_qualification()
{
    cout<<"qualification IS ::  "<<qualification<<endl;
    }
};

int main()
{
student s;
s.setx();
s.getx();

}