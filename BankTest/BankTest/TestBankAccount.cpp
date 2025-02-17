#include "BankAccount.h"
#include <gtest/gtest.h>

TEST(BankAccountTest, InitialBalance) {
    BankAccount account("12345", 1000.0);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(BankAccountTest, Deposit) {
    BankAccount account("12345", 1000.0);
    account.deposit(500.0);
    EXPECT_EQ(account.getBalance(), 1500.0);
}

/*
* Brief: ��������� ������, ���� ����� ������� �����
* � ������ �������� ������ ������ ���������� ������
*/ 
TEST(BankAccountTest, BigDeposit) {
    BankAccount account("12345", 1000.0);
    account.deposit(100000.0);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(BankAccountTest, Withdraw) {
    BankAccount account("12345", 1000.0);
    account.withdraw(300.0);
    EXPECT_EQ(account.getBalance(), 700.0);
}

TEST(BankAccountTest, Overdraw) {
    BankAccount account("12345", 1000.0);
    account.withdraw(1500.0);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(BankAccountTest, NegativeDeposit) {
    BankAccount account("12345", 1000.0);
    account.deposit(-100.0);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(BankAccountTest, NegativeWithdraw) {
    BankAccount account("12345", 1000.0);
    account.withdraw(-100.0);
    EXPECT_EQ(account.getBalance(), 1000.0);
}
/*
* Brief: �������� �� ��������� ������� ��������,
* ���� ��� �� ��������� ������� ������ � ��
* ���������� �������� ������
*/
TEST(BankAccountTest, Overdraw) {
    BankAccount account("12345", 1000.0);
    std::string AccountNumber = account.getAccountNumber();
    EXPECT_EQ(account.getAccountNumber(), AccountNumber);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}