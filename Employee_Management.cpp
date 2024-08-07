#include<iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string job_title;
    int hours_worked;

public:
    // Default constructor.
    Employee() {

    }

    // Parametrized constructor.
    Employee(int id, string name, string job_title, int hours_worked) {
        this->id = id;
        this->name = name;
        this->job_title = job_title;
        this->hours_worked = hours_worked;
    }

    // Getters.
    int getid() {
        return id;
    }

    string getname() {
        return name;
    }

    string getjob_title() {
        return job_title;
    }

    // Setters.
    void setid(int id) {
        this->id =id;
    }

    void setname(string name) {
        this->name =name;
    }

    void setjob_title(string job_title) {
        this->job_title = job_title;
    }

    void sethours_worked(int hours_worked) {
        this->hours_worked =hours_worked;
    }

    // Member function.
    float calculate_salary() {
        float hour_rate = 15.0;
        float salary = 0.0;
        float count = 0.0;
        if (hours_worked <= 40) {
            salary =(hours_worked * hour_rate);
        } else {
            count =(hours_worked - 40.0);
            salary =((hour_rate * 2.0) * count);
            salary =salary + (40.0 * hour_rate);
        }
        return salary;
    }
};

void display(Employee emp[], int num_of_Employes) {
    for (int i = 0; i < num_of_Employes; i++) {
        cout << "EMPLOYEE " << i + 1 << " NAME :" << emp[i].getname() << endl;
        cout << "SALARY OF EMPLOYEE " << i + 1 << " is : " << emp[i].calculate_salary() << endl;
    }
}

int main() {
    int num_of_Employes;
    cout << "ENTER THE NUMBER OF EMPLOYEES : ";
    cin >> num_of_Employes;

    Employee emp[num_of_Employes];
    int id;
    string name;
    string job_title;
    int hours_worked;

    for (int i = 0; i < num_of_Employes; i++) {
        cout << "ENTER THE ID OF THE EMPLOYEE " << i + 1 << ": ";
        cin >> id;
        emp[i].setid(id);

        cout << "ENTER THE NAME OF THE EMPLOYEE " << i + 1 << ": ";
        cin >> name;
        emp[i].setname(name);

        cout<< "ENTER THE JOB TITLE OF THE EMPLOYEE " << i + 1 << ": ";
        cin>>job_title;
        emp[i].setjob_title(job_title);

        cout<<"ENTER THE NUMBER OF HOURS WORKED FOR EMPLOYEE " << i + 1 << ": ";
        cin >> hours_worked;
        emp[i].sethours_worked(hours_worked);
    }

    display(emp, num_of_Employes);

    return 0;
}