//Header Files
#include <iostream>
using namespace std;

// Function declarations.
void quiz_avg(int arr[][5]);
void stu_avg(int arr[][5]);

// Main function.
int main() {
    const int students = 40;
    const int quiz = 5;
    int array[students][quiz];

    // Input for student array.
    for (int i = 0; i < students; i++) {
        cout <<endl<<"ENTER MARKS OF STUDENT - " << i + 1 << " :" << endl << endl;
        for (int j = 0; j < quiz; j++) {
            cout << "QUIZ - " << j + 1 << " :";
            cin >> array[i][j];
        }
    }

    // Calling functions.
    quiz_avg(array);
    stu_avg(array);

    return 0;
}

// Calculating Quiz Average.
void quiz_avg(int arr[][5]) {
    //Declaring the two arrays to store min and max quiz numbers.
    int max_quiz[5];
    int min_quiz[5];
    double average[5];
    int sum;

    // Initialize max_quiz and min_quiz arrays.
    for (int i = 0; i < 5; i++) {
        max_quiz[i] = arr[0][i];
        min_quiz[i] = arr[0][i];
    }

    for (int j = 0; j < 5; j++) {
        sum = 0;
        for (int i = 0; i < 40; i++) {
            sum += arr[i][j];
            if (arr[i][j] > max_quiz[j]) {
                max_quiz[j] = arr[i][j];
            }
            if (arr[i][j] < min_quiz[j]) {
                min_quiz[j] = arr[i][j];
            }
        }
        //calculting average
        average[j] = sum / 40.0;
    }
    cout<<endl<<endl;
    // Printing the values.
    for (int i = 0; i < 5; i++) {
        cout <<"THE MAXIMUM MARKS IN QUIZ : " << i + 1 << " are : " << max_quiz[i] << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout <<"THE MINIMUM MARKS IN QUIZ : " << i + 1 << " are : " << min_quiz[i] << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << "THE AVERAGE MARKS IN QUIZ : " << i + 1 << " are : " << average[i] << endl;
    }
}

// Calculating Student Average.
void stu_avg(int arr[][5]) {
    //Declaring the two arrays to store min and max student numbers.
    int max_stu[40];
    int min_stu[40];
    double average[40];
    int sum;

    // Initialize max_stu and min_stu arrays.
    for (int i = 0; i < 40; i++) {
        max_stu[i] = arr[i][0];
        min_stu[i] = arr[i][0];
    }

    for (int i = 0; i < 40; i++) {
        sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += arr[i][j];
            if (arr[i][j] > max_stu[i]) {
                max_stu[i] = arr[i][j];
            }
            if (arr[i][j] < min_stu[i]) {
                min_stu[i] = arr[i][j];
            }
        }
        //calculating the average.
        average[i] = sum / 5.0;
    }
    cout<<endl<<endl;
    // Printing the values.
    for (int i = 0; i < 40; i++) {
        cout << "THE MAXIMUM MARKS OF STUDENT : " << i + 1 << " are : " << max_stu[i] << endl;
    }
    for (int i = 0; i < 40; i++) {
        cout << "THE MINIMUM MARKS OF STUDENT : " << i + 1 << " are : " << min_stu[i] << endl;
    }
    for (int i = 0; i < 40; i++) {
        cout << "THE AVERAGE MARKS OF STUDENT : " << i + 1 << " are : " << average[i] << endl;
    }
}
