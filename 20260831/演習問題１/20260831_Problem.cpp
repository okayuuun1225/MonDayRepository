#include <iostream>
#include <string>
#include "20260831_Problem.h"
using namespace std;

int main() {
    //BankAccountをオブジェクト
    BankAccount account("Alice", 5000.0);

    //初期状態
    account.displayAccountInfo();

    //1000円入金
    account.deposit(1000.0);
    
    //2000円出金
    account.withdraw(2000.0);
    //5000円出金
    account.withdraw(5000.0); // 残高不足で失敗
    //最終的な情報を表示
    account.displayAccountInfo();

    return 0;
}