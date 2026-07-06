#include "20260706_Header1_ueda.h"
#include "20260706_Config1_ueda.h"
#include <iostream>;
using namespace std;

void Heal(int& hp)
{
	//HP回復
	hp += 20;

	cout << "回復しました。" << endl;
}

//入力チェック
int InputCheck(int min,int max)
{
	int num;

	while (true)
	{
		cin >> num;
		if (min > num || max < num)
		{
			cout << "正しい数字を入力してください" << endl;
		}
		else
		{
			break;
		}
	}
	return num;
}

void Run()
{
	//変数宣言
	int playerHp = ConstNumber::PLAYER_HP;
	int select;

	cout << "HPを回復させますか？\nYES：１、NO：２" << endl;
	
	select = InputCheck(ConstNumber::SELECT_MIN,ConstNumber::SELECT_MAX);

	//1のとき回復
	if (select == 1)
	{
		Heal(playerHp);
	}
	else
	{
		cout << "HPそのままま" << endl;
	}

	cout << "現在のHPは" << playerHp << "です";
}