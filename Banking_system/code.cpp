#include <iostream>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accNumber, string accHolder, double bal = 0.0) {
        accountNumber = accNumber;
        accountHolderName = accHolder;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNumber, string accHolder, double bal = 0.0, double rate = 0.02) 
        : BankAccount(accNumber, accHolder, bal), interestRate(rate) {}

    void calculateInterest() {
        double interest = balance * interestRate;
        cout << "Interest Earned: " << interest << endl;
    }
};

int main() {
    BankAccount account1("123456", "John Doe", 500);
    account1.displayAccountInfo();
    account1.deposit(200);
    account1.withdraw(100);
    cout << "Balance: " << account1.getBalance() << endl;

    SavingsAccount savingsAccount("789012", "Alice Smith", 1000, 0.05);
    savingsAccount.displayAccountInfo();
    savingsAccount.calculateInterest();

    return 0;
}