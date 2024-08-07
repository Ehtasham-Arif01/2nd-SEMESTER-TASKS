//Header Files
#include<iostream>
using namespace std;

// Function Declarations

void matrix_creation(int **&matrix1, int **&matrix2, int &rows1, int &cols1, int &rows2, int &cols2);
void input_matrix(int **matrix, int rows, int cols);
void addition(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int **&addition_matrix);
void subtraction(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int **&subtraction_matrix);
void multiplication(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int **&multiplication_matrix);
void transpose(int **matrix, int rows, int cols, int **&transposeof);
void print_matrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int **addition_matrix, int **subtraction_matrix, int **multiplication_matrix, int **transposeof_1, int **transposeof_2);

// Main Function
int main()
{

    cout<<endl<<endl<<"/////////////////////////** WELCOME **/////////////////////////"<<endl<<endl;
    int rows1, cols1, rows2, cols2;
    //Declaring the pointer array using DMA.
    int **matrix1;
    int **matrix2;
    int **addition_matrix = nullptr;
    int **subtraction_matrix = nullptr;
    int **multiplication_matrix = nullptr;
    int **transposeof_1;
    int **transposeof_2;

    //CAlling functions in main().
    matrix_creation(matrix1, matrix2, rows1, cols1, rows2, cols2);
    //calling input function 2 times for 2 matrixes .
    input_matrix(matrix1, rows1, cols1);
    input_matrix(matrix2, rows2, cols2);

    //calling the opertional  functions..
    addition(matrix1, matrix2, rows1, cols1, rows2, cols2, addition_matrix);
    subtraction(matrix1, matrix2, rows1, cols1, rows2, cols2, subtraction_matrix);
    multiplication(matrix1, matrix2, rows1, cols1, rows2, cols2, multiplication_matrix);

    transpose(matrix1, rows1, cols1, transposeof_1);
    transpose(matrix2, rows2, cols2, transposeof_2);

    //printing the all of the matrixes...
    print_matrix(matrix1, matrix2, rows1, cols1, rows2, cols2, addition_matrix, subtraction_matrix, multiplication_matrix, transposeof_1, transposeof_2);

    // Freeing dynamically allocated memory.
    for (int i = 0; i < rows1; i++) {
        delete[] matrix1[i];
        delete[] transposeof_1[i];
    }
    delete[] matrix1;
    delete[] transposeof_1;

    for (int i = 0; i < rows2; i++) {
        delete[] matrix2[i];
        delete[] transposeof_2[i];
    }
    delete[] matrix2;
    delete[] transposeof_2;

    if (addition_matrix != nullptr) {
        for (int i = 0; i < rows1; i++) {
            delete[] addition_matrix[i];
        }
        delete[] addition_matrix;
    }

    if (subtraction_matrix != nullptr) {
        for (int i = 0; i < rows1; i++) {
            delete[] subtraction_matrix[i];
        }
        delete[] subtraction_matrix;
    }

    if (multiplication_matrix != nullptr) {
        for (int i = 0; i < rows1; i++) {
            delete[] multiplication_matrix[i];
        }
        delete[] multiplication_matrix;
    }

    return 0;
}

// Function Definitions

//Defining the function MAtrix_creation.
void matrix_creation(int **&matrix1, int **&matrix2, int &rows1, int &cols1, int &rows2, int &cols2)
{
    cout << "Enter the number of rows for matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns for matrix 1: ";
    cin >> cols1;

    //using DMA.
    matrix1 = new int *[rows1];
    for (int i = 0; i < rows1; i++) {
        //Allocating memory using DMA.
        matrix1[i] = new int[cols1];
    }

    cout << "Enter the number of rows for matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns for matrix 2: ";
    cin >> cols2;

    //using DMA.
    matrix2 = new int *[rows2];
    for (int i = 0; i < rows2; i++) {
        //Allocating memory using DMA.
        matrix2[i] = new int[cols2];
    }
}

///Defining input_matrix Function.

void input_matrix(int **matrix, int rows, int cols)
{
    //inputting values.
    cout <<endl<<"Enter values for the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        cout <<endl<<"ROW - " << i + 1 << ":" <<endl<<endl;
        for (int j = 0; j < cols; j++) {
            cout << "COLUM -" << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }
}

//Defining the function Addition.

void addition(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int **&addition_matrix)
{
    //Cheaking Addition Rule.
    if (rows1 != rows2 || cols1 != cols2) {
        cout <<endl<<"ERROR!\tAddition is not possible. Matrices should have the same dimensions." <<endl<<endl;
        return;
    }

    //performing matrix addition.
    addition_matrix = new int *[rows1];
    for (int i = 0; i < rows1; i++) {
        addition_matrix[i] = new int[cols1];
        for (int j = 0; j < cols1; j++) {
            addition_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

//Defining the function subtraction.
void subtraction(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int **&subtraction_matrix)
{
    //Cheaking subtraction Rule.
    if (rows1 != rows2 || cols1 != cols2) {
        cout <<endl<<"Subtraction is not possible. Matrices should have the same dimensions." <<endl<<endl;
        return;
    }

    //performing matrix subtraction.
    subtraction_matrix = new int *[rows1];
    for (int i = 0; i < rows1; i++) {
        subtraction_matrix[i] = new int[cols1];
        for (int j = 0; j < cols1; j++) {
            subtraction_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

//Defining the function multiplication.
void multiplication(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int **&multiplication_matrix)
{
    //Cheaking multilication Rule.
    if (cols1 != rows2) {
        cout <<endl<<"Multiplication is not possible. Number of columns of matrix 1 should be equal to the number of rows of matrix 2." <<endl<<endl;
        return;
    }

    //performing matrix multiplication.
    multiplication_matrix = new int *[rows1];
    for (int i = 0; i < rows1; i++) {
        multiplication_matrix[i] = new int[cols2];
        for (int j = 0; j < cols2; j++) {
            multiplication_matrix[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                multiplication_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

//Defining the function TRanspose of matrix...
void transpose(int **matrix, int rows, int cols, int **&transposeof)
{
    //performing transpose of matrix.
    transposeof = new int *[cols];
    for (int i = 0; i < cols; i++) {
        transposeof[i] = new int[rows];
        for (int j = 0; j < rows; j++) {
            transposeof[i][j] = matrix[j][i];
        }
    }
}

//Defining the function print_matrixes.
void print_matrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int **addition_matrix, int **subtraction_matrix, int **multiplication_matrix, int **transposeof_1, int **transposeof_2)
{
    cout <<endl<<"\tMATRIX - 01 ELEMENTS : " <<endl<< endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout <<endl<<"\tMATRIX - 02 ELEMENTS :" <<endl<< endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    if (addition_matrix != nullptr) {
        cout <<endl<<"ADDITION OF MATRIXES IS : " <<endl<<endl;
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                cout << addition_matrix[i][j] << " ";
            }
            cout << endl;
        }
    } 

    if (subtraction_matrix != nullptr) {
        cout <<endl<<"SUBTRACTION OF MATRIXES IS :" <<endl<<endl;
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                cout << subtraction_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    if (multiplication_matrix != nullptr) {
        cout <<endl<<"MULTIPLICATION OF MATRIXES IS :" <<endl<<endl;
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                cout << multiplication_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    cout <<endl<<"TRANSPOSE OF MATRIX - 01 IS :" <<endl<< endl;
    for (int i = 0; i < cols1; i++) {
        for (int j = 0; j < rows1; j++) {
            cout << transposeof_1[i][j] << " ";
        }
        cout << endl;
    }

    cout <<endl<<"TRANSPOSE OF MATRIX - 02 IS :" <<endl;
    for (int i = 0; i < cols2; i++) {
        for (int j = 0; j < rows2; j++) {
            cout << transposeof_2[i][j] << " ";
        }
        cout << endl;
    }

    cout<<endl<<endl<<"/////////////////////////**PROGRAM ENDED**/////////////////////////"<<endl<<endl;
}
