#include <iostream>
#include <string>
using namespace std;

// Base class: Student
class Student {
protected:
    string name;
    int age;
    int rollNumber;
    float CGPA;

public:
    Student(string n_name, int n_age, int n_rollNumber, float n_CGPA) : name(n_name), age(n_age), rollNumber(n_rollNumber), CGPA(n_CGPA) {
        cout<<"\nBASE ClaSS CONSTRUCTER CALLED\n\n";
    }

     //destruvter.
    ~Student(){
            cout<<"\nSTUDENT DESTRUVTER IS CALLAED...\n\n";
    }

    void ShowCGPA() {
        cout << "CGPA: " << CGPA << endl;
    }
};

// Derived class: UGStudent
class UGStudent : public Student {
private:
    string FYPtitle;
    string supervisorName;

public:
    UGStudent(string n_name, int n_age, int n_rollNumber, float n_CGPA, string n_FYPtitle, string n_supervisorName) : Student(n_name, n_age, n_rollNumber, n_CGPA), FYPtitle(n_FYPtitle), supervisorName(n_supervisorName) {
        cout<<"\nUG STUDENT CONSTRUCTER CALLED\n\n";
    }

 //destruvter.
    ~UGStudent(){
            cout<<"\nUUG DESTRUVTER IS CALLAED...\n\n";
    }

    void ShowFYPtitle() {
        cout << "FYP Title: " << FYPtitle << endl;
    }
};

// Derived class: PGStudent
class PGStudent : public Student {
private:
    string thesisTitle;
    string supervisorName;

public:
    PGStudent(string n_name, int n_age, int n_rollNumber, float n_CGPA, string n_thesisTitle, string n_supervisorName) : Student(n_name, n_age, n_rollNumber, n_CGPA), thesisTitle(n_thesisTitle), supervisorName(n_supervisorName) {
        cout<<"\nPPPG STUDENT CONSTRUCTER CALLED\n\n";
    }

    //destruvter.
    ~PGStudent(){
            cout<<"\nPG DESTRUVTER IS CALLAED...\n\n";
    }

    void ShowThesisTitle() {
        cout << "Thesis Title: " << thesisTitle << endl;
    }
};

int main() {
    // Creating objects of UGStudent and PGStudent classes
    UGStudent ug("John Doe", 20, 12345, 3.8, "Research on Renewable Energy", "Dr. Smith");
    PGStudent pg("Alice Smith", 25, 54321, 4.0, "Advancements in Artificial Intelligence", "Prof. Johnson");

    // Displaying information for UGStudent
    cout << "UG Student Info:" << endl;

    ug.ShowCGPA();
    ug.ShowFYPtitle();


    cout << endl;


    pg.ShowCGPA();
    pg.ShowThesisTitle();

    cout << endl;
     ug.ShowCGPA();
    
    cout << endl;
    return 0;
}
