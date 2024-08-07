#include <iostream>
using namespace std;

const int Max_account = 5;
int Account_number[Max_account];
int Account_balance[Max_account];
string Account_name[Max_account];
int Account_type[Max_account];

// Function prototypes
void openAccount();
void deposit(int accNum, int amount);
void withdraw(int accNum, int amount);
void Display_accounts();
void Display_balance(int accNum);

int main() {
    int choice;
    // Main menu
    cout << "1-Open Account\n2-Deposit Funds\n3-Withdraw Funds\n4-Display All Accounts\n5-View Account Balance\n6-Exit" << endl;

    // Get user choice
    cout << "*-------------*" << endl << endl << "Enter Your Choice: ";
    cin >> choice;

    // Main program loop
    while (choice != 6) {
        switch (choice) {
            case 1: // Open Account
                openAccount();
                break;
            case 2: // Deposit Funds
                int depositAmount, depositAccNum;
                cout << "Enter account number in which you want to deposit funds: ";
                cin >> depositAccNum;
                cout << "Enter the amount you want to deposit: ";
                cin >> depositAmount;
                deposit(depositAccNum, depositAmount);
                break;
            case 3: // Withdraw Funds
                int withdrawAmount, withdrawAccNum;
                cout << "Enter account number from which you want to withdraw amount: ";
                cin >> withdrawAccNum;
                cout << "Enter the amount you want to withdraw: ";
                cin >> withdrawAmount;
                withdraw(withdrawAccNum, withdrawAmount);
                break;
            case 4: // Display All Accounts
                Display_accounts();
                break;
            case 5: // View Account Balance
                int viewAccNum;
                cout << "Enter Account Number for which Balance You want To See: ";
                cin >> viewAccNum;
                Display_balance(viewAccNum);
                break;
            default:
                cout << "Invalid Choice! Please try again." << endl;
        }
        cout << endl << "*----------------*" << endl << endl << "1-Open Account\n2-Deposit Funds\n3-Withdraw Funds\n4-Display All Accounts\n5-View Account Balance\n6-Exit" << endl;
        // Get the next choice
        cout << "*--------------------*" << endl << "Enter Your Choice: ";
        cin >> choice;
    }

    cout << "Exiting..." << endl;

    return 0;
}

// Function to open an account
void openAccount() {
    for (int i = 0; i < Max_account; i++) {
        if (Account_number[i] == 0) {
            cout << "Enter Holder Name: ";
            cin.ignore(); // Ignore newline left in the input buffer
            getline(cin, Account_name[i]);
            cout << "Enter Account Number: ";
            cin >> Account_number[i];
            cout << "Enter Account Type (1 for Savings, 2 for Checking): ";
            cin >> Account_type[i];
            if (Account_type[i] < 1 || Account_type[i] > 2) {
                cout << "Invalid Choice. Please enter 1 for Savings or 2 for Checking." << endl;
                cin >> Account_type[i];
            }
            Account_balance[i] = 0;
            break; // Exit loop after opening one account
        }
    }
}

// Function to deposit funds into an account
void deposit(int accNum, int amount) {
    for (int i = 0; i < Max_account; i++) {
        if (Account_number[i] == accNum) {
            Account_balance[i] += amount; // Update the account balance
            cout << endl << "*----------------*" << endl << "Amount Has Been Deposited to Your Account: " << amount << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}

// Function to withdraw funds from an account
void withdraw(int accNum, int amount) {
    for (int i = 0; i < Max_account; i++) {
        if (Account_number[i] == accNum) {
            if (Account_balance[i] >= amount) {
                Account_balance[i] -= amount; // Subtract the withdrawal amount from the account balance
                cout << endl << "*----------------*" << endl << "Current Amount In Your Account Is: " << Account_balance[i] << endl;
            } else {
                cout << endl << "*----------------*" << endl << "Your Current Balance Is Lower than Your Withdraw Amount" << endl;
            }
            return;
        }
    }
    cout << "Account not found!" << endl;
}

// Function to display all accounts
void Display_accounts() {
    for (int i = 0; i < Max_account; i++) { // Loop through the array of accounts
        if (Account_number[i] != 0) {
            cout << endl << "*-------------------------------*" << endl << endl;
            cout << "Account Number: " << Account_number[i] << endl;
            if (Account_type[i] == 1) {
                cout << "ACCOUNT TYPE : SAVING ACCOUNT" << endl;
            } else {
                cout << "ACCOUNT TYPE : CHECKING ACCOUNT" << endl;
            }
            cout << "Account Holder: " << Account_name[i] << endl;
            cout << "Account Balance: " << Account_balance[i] << endl;
        }
    }
}

// Function to view account balance
void Display_balance(int accNum) {
    for (int i = 0; i < Max_account; i++) {
        if (Account_number[i] == accNum) {
            cout << endl << "*----------------*" << endl << "Your Current Balance is: " << Account_balance[i] << endl;
            return;
        }
    }
    cout << "Account Not Found" << endl;
}