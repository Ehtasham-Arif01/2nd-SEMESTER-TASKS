#include<iostream>
using namespace std;

// Function Declarations.
void matrix_creation(int **&matrix1, int **&matrix2, int &rows1, int &cols1, int &rows2, int &cols2);
void input_matrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2);
void addition(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int addition_matrix[][10]);
void subtraction(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int subtraction_matrix[][10]);
void multiplication(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int multiplication_matrix[][10]);
void transpose(int **matrix, int rows, int cols, int transposeof[][10]);
void print_matrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int addition_matrix[][10], int subtraction_matrix[][10], int multiplication_matrix[][10], int transposeof_1[][10], int transposeof_2[][10]);

// Main Function.
int main()
{
    int rows1, cols1, rows2, cols2;
    int **matrix1;
    int **matrix2;
    int addition_matrix[10][10];
    int subtraction_matrix[10][10];
    int multiplication_matrix[10][10];
    int transposeof_1[10][10];
    int transposeof_2[10][10];

    matrix_creation(matrix1, matrix2, rows1, cols1, rows2, cols2);
    input_matrix(matrix1, matrix2, rows1, cols1, rows2, cols2);
    addition(matrix1, matrix2, rows1, cols1, rows2, cols2, addition_matrix);
    subtraction(matrix1, matrix2, rows1, cols1, rows2, cols2, subtraction_matrix);
    multiplication(matrix1, matrix2, rows1, cols1, rows2, cols2, multiplication_matrix);
    transpose(matrix1, rows1, cols1, transposeof_1);
    transpose(matrix2, rows2, cols2, transposeof_2);
    print_matrix(matrix1, matrix2, rows1, cols1, rows2, cols2, addition_matrix, subtraction_matrix, multiplication_matrix, transposeof_1, transposeof_2);

    for (int i = 0; i < rows1; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < rows2; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    return 0;
}

// Function Definitions.
void matrix_creation(int **&matrix1, int **&matrix2, int &rows1, int &cols1, int &rows2, int &cols2)
{
    cout << "ENTER THE NUMBER OF ROWS FOR MATRIX -01 :";
    cin >> rows1;
    cout << "ENTER THE NUMBER OF COLUMNS FOR MATRIX -01 :";
    cin >> cols1;

    matrix1 = new int *[rows1];
    for (int i = 0; i < rows1; i++)
    {
        matrix1[i] = new int[cols1];
    }

    cout << "ENTER THE NUMBER OF ROWS FOR MATRIX -02 :";
    cin >> rows2;
    cout << "ENTER THE NUMBER OF COLUMNS FOR MATRIX -02 :";
    cin >> cols2;

    matrix2 = new int *[rows2];
    for (int i = 0; i < rows2; i++)
    {
        matrix2[i] = new int[cols2];
    }
}

void input_matrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2)
{
    cout << "ENTER VALUES IN MATRIX - 01 :" << endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "ENTER VALUES IN MATRIX - 02 :" << endl;
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cin >> matrix2[i][j];
        }
    }
}

void addition(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int addition_matrix[][10])
{
    if (rows1 != rows2 || cols1 != cols2)
    {
        cout << "ADDITION IS NOT POSSIBLE" << endl;
        return;
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            addition_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtraction(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int subtraction[10][10])
{
    if (rows1 != rows2 || cols1 != cols2)
    {
        cout << "SUBTRACTION IS NOT POSSIBLE" << endl;
        return;
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            subtraction[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplication(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int multiplication[10][10])
{
    if (cols1 != rows2 || cols2 != rows1)
    {
        cout << "MULTIPLICATION IS NOT POSSIBLE" << endl;
        return;
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            multiplication[i][j] = 0;
            for (int k = 0; k < rows1; k++)
            {
                multiplication[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transpose(int **matrix, int rows, int cols, int transposeof[][10])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transposeof[j][i] = matrix[i][j];
        }
    }
}

void print_matrix(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2, int addition_matrix[][10], int subtraction_matrix[][10], int multiplication_matrix[][10], int transposeof_1[][10], int transposeof_2[][10])
{
    cout << "MATRIX - 01 :" << endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "MATRIX - 02 :" << endl;
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "ADDITION OF MATRICES IS : " << endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cout << addition_matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "SUBTRACTION OF MATRICES IS : " << endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cout << subtraction_matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "MULTIPLICATION OF MATRICES IS : " << endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cout << multiplication_matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "TRANSPOSE OF MATRIX 1 IS : " << endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cout << transposeof_1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "TRANSPOSE OF MATRIX 2 IS : " << endl;
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cout << transposeof_2[i][j] << " ";
        }
        cout << endl;
    }
}
