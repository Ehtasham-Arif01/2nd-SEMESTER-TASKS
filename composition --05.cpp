#include<iostream>
#include<string>
using namespace std;

//Date of birth class.
class DOB {
private:
    int month;
    int date;
    int year;

public:
//default constructer
    DOB()
    {

    }
//parameterized constructer
    DOB(int m, int d, int y) : month(m), date(d), year(y) {}

    // Getters for month, date, and year
    int getMonth() const { return month; }
    int getDate() const { return date; }
    int getYear() const { return year; }
};

//contact class
class Contact {
private:
    string name;
    int phone_no;
    string email;
//object of DOB class.
    DOB object;

public:
//default constructer
    Contact()
    {

    }
//parameterized constructer
    Contact(string n, int p, string e, int m, int d, int y) : name(n), phone_no(p), email(e), object(m, d, y) {}

    // Getters for name, phone number, email, and DOB
    string getName() const { return name; }
    int getPhone() const { return phone_no; }
    string getEmail() const { return email; }
    DOB getDOB() const { return object; }
};

//contacctbook class
class ContactBook {
private:
//Array of object of contact class..
    Contact contacts[5]; // Assuming a fixed size of 5 contacts.
    int numContacts = 0;

public:
//deault constructer
    ContactBook() {}

    // Add a new contact
    //the object of contact class is used as the parameter to pass the data to contcat class 
    void addContact(Contact newContact) {
        if (numContacts < 5) {
            //here at the specific index the data will be passes to contact class and will be setted.
            contacts[numContacts++] = newContact;
        } 
    }

    // Display all contacts
    //using the araaray with the getfunctions to access the values.
    void displayAllContacts() {
        cout << "Contact Book:\n";
        for (int i = 0; i < numContacts; i++) {
            cout << "Contact " << i + 1 << ":\n";
            cout << "Name: " << contacts[i].getName() << endl;
            cout << "Phone Number: " << contacts[i].getPhone() << endl;
            cout << "Email: " << contacts[i].getEmail() << endl;
            DOB dob = contacts[i].getDOB();
            cout << "Date of Birth: " << dob.getMonth() << "/" << dob.getDate() << "/" << dob.getYear() << endl;
            cout << endl;
        }
    }

    // Print names of contacts with birthday in a specific month
    void printContactsByMonth(int month) {
        cout << "Contacts with birthdays in month " << month << ":\n";
        for (int i = 0; i < numContacts; i++) {
            if (contacts[i].getDOB().getMonth() == month) {
                cout << contacts[i].getName() << endl;
            }
        }
    }
};

int main() {
    //object of the contactbook class.
    ContactBook cBook;

    // Adding sample contacts
    /*passing the sample values to the add_function...with the object of the 
    contact class it will pass the values to the contact class and will set the values */
    
    cBook.addContact(Contact("Ali", 123456789, "Ali.com", 3, 15, 1990));
    cBook.addContact(Contact("HAMZA", 987654321, "Ali.com", 3, 20, 1995));
    cBook.addContact(Contact("AHMED", 555555555, "Ali.com", 7, 10, 1985));
    cBook.addContact(Contact("DAWOOD", 111111111, "Ali.com", 3, 25, 1992));

    // Display all contacts
    cBook.displayAllContacts();

    // Print names of contacts with same month birthdays  (month 3)
    cBook.printContactsByMonth(3);

    return 0;
}
