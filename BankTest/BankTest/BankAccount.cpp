#include "BankAccount.h"

BankAccount::BankAccount(const std::string& accountNumber, double initialBalance)
    : accountNumber_(accountNumber), balance_(initialBalance) {
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber_;
}

double BankAccount::getBalance() const {
    return balance_;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance_ += amount;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance_) {
        balance_ -= amount;
    }
}
