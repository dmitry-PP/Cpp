#include<iostream>
#include <Windows.h>

using namespace std;

//Класс для реализации банковского аккаунта
class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance), interestRate(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
            std::cout << "Deposit successful. New balance: " << this->balance << std::endl;
        }
        else {
            std::cout << "Invalid deposit amount" << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= this->balance) {
            this->balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << this->balance << std::endl;
        }
        else {
            std::cout << "Invalid withdrawal amount" << std::endl;
        }
    }

    double getBalance() {
        return this->balance;
    }

    double getInterest() {
        return this->balance * interestRate * (1.0 / 12);
    }

    void setInterestRate(double newRate) {
        this->interestRate = newRate;
    }

    int getAccountNumber() {
        return this->accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

//Freind-функция для перевода денег между счетами
bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;
        std::cout << "Transfer successful" << std::endl;
        return true;
    }
    else {
        std::cout << "Transfer failed. Invalid amount" << std::endl;
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

    BankAccount acc1(12345, 1000.0);
    BankAccount acc2(54321, 500.0);

    acc1.deposit(200.0);
    acc1.withdraw(50.0);

    acc1.setInterestRate(0.02);
    std::cout << "Account 1: " << acc1.getInterest() << std::endl;

    transfer(acc1, acc2, 300.0);

    return 0;
}

