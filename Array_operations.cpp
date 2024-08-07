//Header Files.
#include <iostream>
#include <cstdlib>// used for random function.
#include <ctime> // used for random function.
#include <unistd.h>// Used for sleep function.
using namespace std;

// Function Declarations.
// Passing array and array_size by reference.
void ResizeArray_Addition(int *&array, int &array_size);  
void ResizeArray_Subtraction(int *&array, int &array_size);
void print_array(int *array, int array_size);
void sum_of_array(int *array, int array_size);

//Main Function.
int main() {
    cout << endl << "///////////////// ** WELCOME ** ///////////////// " << endl;

    int array_size = 5;
    //Declaring an Array using DMA.
    int *array = new int[array_size];

    cout<< "WE ARE CREATING THE ARRAY ..." << endl;
    cout<< endl << "PLEASE WAIT ..." << endl;
    cout<<endl<<"\t5 SECONDS WAIT PLEASE.."<<endl;
    cout<<endl<<"\t\tLOADING...."<<endl;

    //USing Srand Function.
    srand(time(NULL)); 
    for (int i = 0; i < array_size; i++) {
        //Restricting the Random Number Between 1 and 10.
        int random_no = (rand() % 10) + 1;
        array[i] = random_no;
        //Using Sleep Function to Sleep for 1 Secoonds.
        sleep(1);
    }

    int choice;
    do {
        cout << endl << "SELECT THE OPERATION YOU WANT TO PERFORM" << endl << endl;
        cout << "1) ADD NEW NUMBER" << endl;
        cout << "2) DELETE A NUMBER" << endl;
        cout << "3) PRINT THE ARRAY" << endl;
        cout << "4) PRINT SUM OF ARRAY" << endl;
        cout << "5) EXIT THE PROGRAM" << endl << endl;
        cin >> choice;

        //Calling the function based on user choice operation.
        switch (choice) {
            case 1:
                ResizeArray_Addition(array, array_size);
                break;

            case 2:
                ResizeArray_Subtraction(array, array_size);
                break;

            case 3:
                print_array(array, array_size);
                break;

            case 4:
                sum_of_array(array, array_size);
                break;

            case 5:
                cout << endl << "EXITING PROGRAM ...." << endl << endl;
                break;

            default:
                cout << endl << "ERROR!\t CHOOSE THE CORRECT OPTION" << endl << endl;
        }
    } while (choice != 5);

    cout << endl << "///////////////// ** PROGRAM ENDED ** ///////////////// " << endl;
    // Freeing dynamically allocated memory.
    delete[] array; 
    return 0;
}

//Defining the function to RESIZE ARRAY for Addition .

void ResizeArray_Addition(int *&array, int &array_size) {
    int number;
    cout << "ENTER THE NUMBER YOU WANT TO ADD IN ARRAY :";
    cin >> number;

    //increasing the size.
    int new_size = array_size + 1;
    //MAking the temporary POinter.
    int *array_temp = new int[new_size];

    //Using loop to copy old values.
    for (int i = 0; i < array_size; i++) {
        array_temp[i] = array[i];
    }
    //Adding the new number at the last of the array.
    array_temp[array_size] = number;

    // Free old array memory
    delete[] array; 
    // Updating pointer to old array.
    array = array_temp; 
    array_size = new_size; //updating the size 
    cout<<endl<<"===>\tNUMBER | "<<number<<" | ADDED SUCCFULLY IN THE ARRAY "<<endl;
}

//Defining the function to RESIZE ARRAY for Subtraction .

void ResizeArray_Subtraction(int *&array, int &array_size) {
    int number;
    cout << "ENTER THE NUMBER YOU WANT TO DELETE FROM THE ARRAY :";
    cin >> number;

    //Searching the elements in the Array.
    int search = 0;
    for (int i = 0; i < array_size; i++) {
        if (number == array[i]) {
            search = 1;
            break; // Exit loop if element is found
        }
    }

    //if seaching was successful then ...
    if (search == 1) {
        
        //Reducing the size of array.
        int new_size = array_size - 1;
        //MAking the teamporary pointer.
        int *array_temp = new int[new_size];
        int j = 0;
        //Deleting the value from the array.
        for (int i = 0; i < array_size; i++) {
            if (number != array[i]) {
                array_temp[j++] = array[i];
            }
        }

        // Free old array memory
        delete[] array; 
        // Updating pointer to old array.
        array = array_temp; 
        array_size = new_size;
        cout<<endl<<"===>\tNUMBER | "<<number<<" | DELETED SUCCESSFULLY FROM ARRAY "<<endl;
    }

    //if searching was not successful then display message.
    else {
        cout<<endl<<"ERROR!\t ELEMENT NOT FOUND .."<<endl<<endl;
    }
}

//Defining the print_array function.
void print_array(int *array, int array_size) {
    cout << endl << "ELEMENTS OF THE ARRAY ARE FOLLOWING :" << endl<<endl;
    cout<<"\t\t===>   ";
    //Printing the current array.
    for (int i = 0; i < array_size; i++) {
        cout <<" | "<< array[i];
    }
    cout <<" | " <<endl;
}

//Defining the Sum_of_Array function.
void sum_of_array(int *array, int array_size) {
    int sum = 0;
    //Adding the Elements of the Array.
    for (int i = 0; i < array_size; i++) {
        sum += array[i];
    }
    cout << "SUM OF THE ARRAY IS : " << sum << endl << endl;

}
