#pragma once
#include <iostream>
using namespace std;

class BankAccount
{
private:
    std::string accountHolder; // 口座名義人
    double balance;            // 残高

public:

    //初期設定
    BankAccount(const string& holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance) {
    }

    //現在の残高を取得する関数
    double getBalance() const {
        return balance;
    }

    //入金額判定
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\n";
        }
        else {
            cout << "Invalid deposit amount.\n";
        }
    }

    //出金額判定（出金額表示、不足時失敗）
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        }
        else
        {
            cout << "Invalid withdraw amount or insufficient funds.\n";
        }
    }

    //アカウント名、現在の残高表示
    void displayAccountInfo() const
    {
        cout << "Account Holder: " << accountHolder << "\n"
            << "Current Balance: " << balance << "\n";
    }
};