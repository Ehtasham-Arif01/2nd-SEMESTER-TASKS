#include<iostream>
#include<string>
using namespace std;

class student {
    string name;
    int age;
    int roll;
    float gpa;

public:
    void display_gpa() {
        cout << "Name: " << getname() << endl; // Using getname() function
        cout << "GPA is : " << gpa << endl;
    }
        student()
    {
        cout<<"HELLO I AM CONSTRUCTER\n\n";
    }

    void setname(string name_in) {
        name = name_in;
    }

    string getname() {
        return name;
    }
};

class ug_stu : public student {
public:
    string title;
    string supervisor;
    ug_stu()
    {
        cout<<"HELLO I AM UG _ STU   CONSTRUCTER\n\n";
    }
    ug_stu(string title_in = "", string supervisor_in = "") : title(title_in), supervisor(supervisor_in) {

    }
    

    void display_title() {
        cout << "NAME IS : " << getname() << endl;
        cout << "title   : " << title << endl;
        cout << "supervisor : " << supervisor << endl;
    }
};

class ms_stu : public student {
public:
    string thesis;
    ms_stu(){
        cout<<"I M MS _STU\n\n";
    }

 
    ms_stu(string thesis_in = "") : thesis(thesis_in) {

    }

    void display_thesis() {
        cout << "thesis : " << thesis << endl;
    }
};

int main() {
    student s1;
    student s7;
    s1.setname("SHEIKH");
    s1.display_gpa();

    ug_stu s2;
    s2.title = "UG_STUDENT TILE";
    s2.supervisor = "UG_STUDENT";
    s2.setname("Another Name");
    s2.display_title();

    ms_stu s3;
    s3.thesis = "MS STUDENT";
    s3.setname("Yet Another Name");
    s3.display_thesis();

    return 0;
}
