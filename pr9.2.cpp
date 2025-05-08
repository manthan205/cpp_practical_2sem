
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class BankAccount {
private:
    string accountHolderName;
    double balance;

public:
    BankAccount(const string& name, double initialBalance)
        : accountHolderName(name), balance(initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative.");
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient balance.");
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << ", Remaining Balance: " << balance << endl;
    }

    void displayBalance() const {
        cout << "Account Holder: " << accountHolderName << ", Balance: " << balance << endl;
    }
};

int main() {
    try {
        BankAccount account("John Doe", 1000.0);
        account.displayBalance();

        account.deposit(500.0);
        account.withdraw(300.0);
        account.withdraw(1500.0);  // Will throw an exception
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout<<endl<<endl;
    cout << "24CE103_Manthan Rangpariya"<<endl;

    return 0;
}

