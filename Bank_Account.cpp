#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_ACCOUNTS = 100;
int accountNumbers[MAX_ACCOUNTS];
string accountHolderNames[MAX_ACCOUNTS];
double balances[MAX_ACCOUNTS];
int totalAccounts = 0;

void addAccount();
void checkBalance();
void depositMoney();
void withdrawMoney();
void showMenu();
void saveAccounts();
void loadAccounts();

int main() {
    loadAccounts(); // Load accounts from file at the start

    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: addAccount(); break;
            case 2: checkBalance(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: 
                saveAccounts(); // Save accounts to file before exiting
                cout << "Exiting..." << endl; 
                break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
    return 0;
}

void showMenu() {
    cout << "\n1. Add Account\n2. Check Balance\n3. Deposit Money\n4. Withdraw Money\n5. Exit\nEnter choice: ";
}

void addAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        cout << "Max accounts reached!" << endl;
        return;
    }
    accountNumbers[totalAccounts] = totalAccounts + 1;
    cout << "Enter account holder's name: ";
    cin >> accountHolderNames[totalAccounts]; // Reads only single word names
    balances[totalAccounts] = 0.0;
    cout << "Account created! Account Number: " << accountNumbers[totalAccounts] << endl;
    totalAccounts++;
}

void checkBalance() {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;
    for (int i = 0; i < totalAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            cout << "Account Holder: " << accountHolderNames[i] << endl;
            cout << "Balance: $" << balances[i] << endl;
            return;
        }
    }
    cout << "Invalid account number!" << endl;
}

void depositMoney() {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;
    for (int i = 0; i < totalAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            if (amount <= 0) {
                cout << "Invalid amount!" << endl;
                return;
            }
            balances[i] += amount;
            cout << "Deposited! New Balance: $" << balances[i] << endl;
            return;
        }
    }
    cout << "Invalid account number!" << endl;
}

void withdrawMoney() {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;
    for (int i = 0; i < totalAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount <= 0 || amount > balances[i]) {
                cout << "Invalid amount!" << endl;
                return;
            }
            balances[i] -= amount;
            cout << "Withdrawn! New Balance: $" << balances[i] << endl;
            return;
        }
    }
    cout << "Invalid account number!" << endl;
}

void saveAccounts() {
    ofstream outFile("accounts.txt");
    outFile << totalAccounts << endl;
    for (int i = 0; i < totalAccounts; i++) {
        outFile << accountNumbers[i] << " "
                << accountHolderNames[i] << " "
                << balances[i] << endl;
    }
    outFile.close();
}

void loadAccounts() {
    ifstream inFile("accounts.txt");
    if (!inFile) {
        return; // If file doesn't exist, return
    }
    inFile >> totalAccounts;
    for (int i = 0; i < totalAccounts; i++) {
        inFile >> accountNumbers[i]
               >> accountHolderNames[i]
               >> balances[i];
    }
    inFile.close();
}
