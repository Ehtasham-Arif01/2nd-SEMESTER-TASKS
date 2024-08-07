#include <iostream>
using namespace std;

class base {
public:
    string name;
    int age;
    base(string n_name, int n_age) : name(n_name), age(n_age) {}

    void setname(string n_name)
    {
        this->name=n_name;
    }
    void setage(int n_age)
    {
        this->age=n_age;
    }



    string getname() {
        return name;
    }

    int getage() {
        return age;
    }
};

class derive : public base {
public:
    int num;
    string grade;
    derive(int n_num, string n_grade, string n_name, int n_age) : base(n_name, n_age), num(n_num), grade(n_grade) {}

void setgrade(string n_grade)
{
    this->grade=n_grade;
}
    //the members of the base class are inherited into the derived class so it does not matter whwe to write the set function
//

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    // Creating an object of the derived class
    //setting the vales in derived class.
    derive obj(99, "A+", "ALI", 78);
    
    // Displaying information using the display function
    //we call set the value of the member of base class with the object of derived class even if set function is
    //in base class
    obj.display();

    cout<<endl<<endl;
    obj.setage(23);
    obj.setname("MALIOOOK");
    obj.setgrade("D+");
obj.display();
    return 0;
}
