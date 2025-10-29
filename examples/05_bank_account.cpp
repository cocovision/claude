// Object-oriented programming - Bank Account
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:
    // Constructor
    BankAccount(std::string accNum, std::string owner, double initialBalance = 0.0)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {
        std::cout << "Account created for " << ownerName << std::endl;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid withdrawal amount!" << std::endl;
        } else if (amount > balance) {
            std::cout << "Insufficient funds! Current balance: $" << balance << std::endl;
        } else {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
        }
    }

    // Display account info
    void displayInfo() const {
        std::cout << "\n=== Account Information ===" << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Owner: " << ownerName << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    // Get balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    // Create account
    BankAccount account("ACC001", "Alice Johnson", 1000.0);
    account.displayInfo();

    // Perform transactions
    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(2000.0);  // Should fail

    account.displayInfo();

    return 0;
}

// Compile: g++ -std=c++17 05_bank_account.cpp -o bank
// Run: ./bank
