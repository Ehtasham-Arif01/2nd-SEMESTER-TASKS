//Haader Files
#include <iostream>
using namespace std;

//Main Function
int main() {
    cout << endl << "///////////////// ** WELCOME ** ///////////////// " << endl << endl;

    int rows, cols;
    cout << "ENTER THE NUMBER OF ROWS FOR MARIX : ";
    cin >> rows;

    // Stricting input for number of rows.
    while (rows <= 0) {
        cout << "ERROR!\t Number of rows should be positive. Enter again: ";
        cin >> rows;
    }

    // Dynamically allocating memory for the array.
    int **array = new int*[rows];
    
    // Declaring array for number of colums in each row.
    int column[rows];
    for (int i = 0; i < rows; i++) {
        cout << "ENTER THE NUMBER OF COLUMS IN ROW " << i + 1 << ": ";
        cin >> column[i];

        //Stricting the input for the number of colums
        while (column[i] <= 0) {
            cout << "Number of columns should be positive. Enter again: ";
            cin >> column[i];
        }
        //Dynamically Allocating the memory for the each row.
        array[i] = new int[column[i]];
    }

    // Inputing elements in array.
    for (int i = 0; i < rows; i++) {
        cout <<endl<<"ENTER THE ELEMENTS FOR ROW "<< i + 1<<": ";
        for (int j = 0; j < column[i]; j++) {
            cin >> array[i][j];
        }
    }

    // Printing Elements of the array.
    cout << endl << "PRINTING THE ELEMENTS OF ARRAY :" << endl<<endl;
    for (int i = 0; i < rows; i++) {
        cout << "ROW " << i + 1 << ": ";
        for (int j = 0; j < column[i]; j++) {
            cout <<" | "<<array[i][j];
        }
        cout <<" |"<<endl;
    }

    // Deallocating the memory for the array.
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

    cout << endl << "///////////////// ** PROGRAM ENDED ** ///////////////// " << endl << endl;
    return 0;
}

