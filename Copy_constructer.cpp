//  ==> NAME : EHTASHAM ARIF
//  ==> ROLL NO : 23P-0567
//  ==> SECTION : BCS-2A

//Header file
#include <iostream>
using namespace std;

class dynamic_array {
private:
//data members
    int *arr;
    int array_size;

public:
    // Constructor
    dynamic_array(int size) {
        //allocating memory dynamically
        array_size = size;
        arr = new int[array_size];
    }

    // Copy Constructor
    dynamic_array(const dynamic_array &obj) {
        cout << "COPY CONSTRUCTOR IS CALLED" << endl;
        array_size = obj.get_size();
        arr = new int[array_size];

        //performing the deep copy
        for (int i = 0; i < array_size; i++) {
            arr[i] = obj.arr[i];
        }
    }

    // Destructor
    ~dynamic_array() {
        cout << "DESTRUCTOR IS CALLED" << endl<<endl;

        //Deallocating the memory
        delete[] arr;
    }

    // Print array function
    void print_array() const {
        for (int i = 0; i < array_size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Setter
    void set_value(int index, int value) {
        arr[index] = value;
    }

    // Getter for size
    int get_size() const {
        return array_size;
    }

    // Getter for value at index
    int get_value(int index) const {
        return arr[index];
    }
};//end of the class

int main() {
    
cout<<"\n///////////////**** WELCOME ****///////////////"<<endl;
//creating the array of object and setting the values
    dynamic_array arr1(6);
    for (int i = 0; i < 6; i++) {
        arr1.set_value(i, i);
    }

    cout << "\nARRAY - 1 : " << endl;

//printnig array
    arr1.print_array();

    cout << endl;

//passing theorigional array for deep copy
    dynamic_array arr2(arr1);

    cout << "\n\nARRAY - 2 : " << endl;

//printnig array
    arr2.print_array();
    cout<<endl<<endl;

    //program Ended.
cout<<"\n///////////////**** PROGRAM ENDED ****///////////////\n"<<endl;
    return 0;
}
