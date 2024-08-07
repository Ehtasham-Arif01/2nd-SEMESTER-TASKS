#include <iostream>
using namespace std;

struct student {
    string name;
    int marks[3];
};

void display_data(student arr[], int size);
float calculate_average(student s);
void change_marks(student arr[], int size);
void menu(int &choice);

int main() {
    student students[2];
    int choice;

    for (int i = 0; i < 2; i++) {
        cout << "ENTER THE NAME OF STUDENT " << i + 1 << ": ";
        cin >> ws; 
        getline(cin, students[i].name);
        for (int j = 0; j < 3; j++) {
            cout << "ENTER MARKS OF SUBJECT " << j + 1 << " FOR " << students[i].name << ": ";
            cin >> students[i].marks[j];
        }
    }
    
    do {
        menu(choice);
        switch (choice) {
            case 1:
                display_data(students, 2);
                break;
            case 2:
                for (int i = 0; i < 2; i++) {
                    float average = calculate_average(students[i]);
                    cout << "Student " << (i + 1) << ": " << students[i].name
                         << " - Average: " << average << endl;
                }
                break;
            case 3:
                change_marks(students, 2);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}

void display_data(student arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "STUDENT NAME: " << arr[i].name << endl;
        for (int j = 0; j < 3; j++) {
            cout << "MARKS OF SUBJECT " << j + 1 << ": " << arr[i].marks[j] << endl;
        }
        cout << endl;
    }
}

void menu(int &choice) {
    cout << "MENU:" << endl;
    cout << "1) DISPLAY STUDENT DATA" << endl;
    cout << "2) CALCULATE AVG MARKS" << endl;
    cout << "3) CHANGE THE MARKS " << endl;
    cout << "0) EXIT" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
}

float calculate_average(student s) {
    float totalMarks = 0;
    for (int i = 0; i < 3; i++) {
        totalMarks += s.marks[i];
    }
    return totalMarks / 3;
}

void change_marks(student arr[], int size) {
    int studentIndex;
    cout << "Enter the student number (1-" << size << ") to change marks: ";
    cin >> studentIndex;

    if (studentIndex >= 1 && studentIndex <= size) {
        int subject;
        cout << "Enter the subject number (1-3) to change marks for " << arr[studentIndex - 1].name << ": ";
        cin >> subject;

        
        if (subject >= 1 && subject <= 3) {
            cout << "Enter new marks for subject " << subject << ": ";
            cin >> arr[studentIndex - 1].marks[subject - 1];
            cout << "Marks updated successfully." << endl;
        } else {
            cout << "Invalid subject number!" << endl;
        }
    } else {
        cout << "Invalid student number!" << endl;
    }
}