#pragma once

#include <string>

class BankAccount {
public:
    BankAccount(const std::string& accountNumber, double initialBalance);

    std::string getAccountNumber() const;
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);

private:
    std::string accountNumber_;
    double balance_;
};
