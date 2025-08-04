#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

int accountNumbers[MAX_ACCOUNTS];
string accountNames[MAX_ACCOUNTS];
double accountBalances[MAX_ACCOUNTS];
int totalAccounts = 0;

int findAccountIndex(int accountNumber) {
    for (int i = 0; i < totalAccounts; ++i) {
        if (accountNumbers[i] == accountNumber) {
            return i;
        }
    }
    return -1;
}

void addAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        cout << "Maximum account limit reached." << endl;
        return;
    }

    int accNum;
    string accName;
    double initialBalance;

    cout << "\n[Add Account]" << endl;

    // Safe input for account number
    cout << "Account number: ";
    while (!(cin >> accNum)) {
        cin.clear();
        cin.ignore(10000, '\n'); // Using a fixed value (10000)
        cout << "Invalid input. Try again: ";
    }

    if (findAccountIndex(accNum) != -1) {
        cout << "Account already exists!" << endl;
        return;
    }

    // Name input (no spaces)
    cout << "Account holder name (no spaces): ";
    cin >> accName;

    // Safe input for initial balance
    cout << "Initial deposit amount: ";
    while (!(cin >> initialBalance)) {
        cin.clear();
        cin.ignore(10000, '\n'); // Using a fixed value (10000)
        cout << "Invalid input. Try again: ";
    }

    accountNumbers[totalAccounts] = accNum;
    accountNames[totalAccounts] = accName;
    accountBalances[totalAccounts] = initialBalance;
    totalAccounts++;

    cout << "Account added successfully!" << endl;
}

void viewAccounts() {
    if (totalAccounts == 0) {
        cout << "No accounts to display." << endl;
        return;
    }

    cout << "\n[All Accounts]" << endl;
    for (int i = 0; i < totalAccounts; ++i) {
        cout << "Account Number: " << accountNumbers[i]
             << ", Name: " << accountNames[i]
             << ", Balance: $" << accountBalances[i] << endl;
    }
}

void depositMoney() {
    int accNum;
    double amount;

    cout << "\n[Deposit]" << endl;

    // Safe input for account number
    cout << "Enter account number: ";
    while (!(cin >> accNum)) {
        cin.clear();
        cin.ignore(10000, '\n'); // Using a fixed value (10000)
        cout << "Invalid input. Try again: ";
    }

    int idx = findAccountIndex(accNum);
    if (idx == -1) {
        cout << "Account not found." << endl;
        return;
    }

    // Safe input for deposit amount
    cout << "Enter amount to deposit: ";
    while (!(cin >> amount)) {
        cin.clear();
        cin.ignore(10000, '\n'); // Using a fixed value (10000)
        cout << "Invalid input. Try again: ";
    }

    if (amount < 0) {
        cout << "Invalid amount." << endl;
        return;
    }

    accountBalances[idx] += amount;
    cout << "Deposit successful. New balance: $" << accountBalances[idx] << endl;
}

void withdrawMoney() {
    int accNum;
    double amount;

    cout << "\n[Withdraw]" << endl;

    // Safe input for account number
    cout << "Enter account number: ";
    while (!(cin >> accNum)) {
        cin.clear();
        cin.ignore(10000, '\n'); // Using a fixed value (10000)
        cout << "Invalid input. Try again: ";
    }

    int idx = findAccountIndex(accNum);
    if (idx == -1) {
        cout << "Account not found." << endl;
        return;
    }

    // Safe input for withdrawal amount
    cout << "Enter amount to withdraw: ";
    while (!(cin >> amount)) {
        cin.clear();
        cin.ignore(10000, '\n'); // Using a fixed value (10000)
        cout << "Invalid input. Try again: ";
    }

    if (amount < 0 || amount > accountBalances[idx]) {
        cout << "Invalid or insufficient amount." << endl;
        return;
    }

    accountBalances[idx] -= amount;
    cout << "Withdrawal successful. New balance: $" << accountBalances[idx] << endl;
}

void searchAccount() {
    int accNum;

    cout << "\n[Search Account]" << endl;

    // Safe input for account number
    cout << "Enter account number: ";
    while (!(cin >> accNum)) {
        cin.clear();
        cin.ignore(10000, '\n'); // Using a fixed value (10000)
        cout << "Invalid input. Try again: ";
    }

    int idx = findAccountIndex(accNum);
    if (idx == -1) {
        cout << "Account not found." << endl;
        return;
    }

    cout << "Account Number: " << accountNumbers[idx]
         << ", Name: " << accountNames[idx]
         << ", Balance: $" << accountBalances[idx] << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- Bank System Menu ---" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. View All Accounts" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Search Account" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        // Safe input for menu choice
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n'); // Using a fixed value (10000)
            cout << "Invalid input. Try again: ";
        }

        switch (choice) {
            case 1: addAccount(); break;
            case 2: viewAccounts(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: searchAccount(); break;
            case 6: cout << "Goodbye!" << endl; return 0;
            default: cout << "Invalid choice. Try again." << endl;
        }
    }
}