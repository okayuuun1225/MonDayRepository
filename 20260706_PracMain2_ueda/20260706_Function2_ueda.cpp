#include <iostream>
#include <ctime>
#include <cstdlib>
#include "20260706_Header2_ueda.h"
using namespace std;

//関数プロトタイプ宣言
int InputCheck(int min, int max);
void Game();
void HandSignPrint(int handChoice);
int Judge(int player, int cpu);

//入力チェック
int InputCheck(int min, int max)
{
	int num;
	while (true)
	{
		cin >> num;
		if (min > num || max < num)
		{
			cout << "正しい数値を入力してください" << endl;
		}
		else
		{
			break;
		}
	}
	return num;
}

//じゃんけんの手生成
void HandSignPrint(int handChoice)
{

	enum Hand
	{
		g,
		c,
		p
	};

	switch (handChoice)
	{
	case Hand::g:
		cout << "ぐー";
		break;
	case Hand::c:
		cout << "ちょき";
		break;
	case Hand::p:
		cout << "ぱー";
		break;
	}
}

//じゃんけん勝敗
int Judge(int player, int cpu)
{
	int point = 0;
	int jug = player - cpu;
	if (jug == -1 || jug == 2)
	{
		cout << " あなたの勝ち！\n";

		point = rand() % ConstNumber::EXP_RAND_MAX;
		
	}
	else if (jug == 0)
	{
		cout << " 引き分け！\n";
	}
	else
	{
		cout << " 相手の勝ち\n";
	}

	cout << " 経験値を" << point;
	cout << "獲得しました！" << endl;

	return point;
}

//ゲーム
void Game()
{
	//変数宣言
	int level = 1,exp = 0;
	int player;

	//ゲームループ
	while (true)
	{
		//ゲーム開始
		cout << "====================\nLv：" << level << "\nEXP：" << exp << "\n====================" << endl;

		cout << "０：ぐー １：ちょき ２：ぱー\n入力：";

		//入力チェック呼び出し
		player = InputCheck(ConstNumber::HAND_MIN, ConstNumber::HAND_MAX);
		//CPUじゃんけん生成
		int cpu = rand() % (ConstNumber::HAND_MAX + 1);

		//勝負表示
		cout << "\n CPU：";
		HandSignPrint(cpu);

		cout << "\n";

		//経験値加算
		exp += Judge(player, cpu);

		//レベルアップ
		if (exp >= ConstNumber::EXP_MAX)
		{
			exp -= ConstNumber::EXP_MAX;
			level++;
			cout << "レベルアップ！Lv" << level << "になりました！" << endl;
		}

		//レベルMAX時終了
		if (level == ConstNumber::LEVEL_MAX)
		{
			break;
		}

		//経験値表示
		cout << " 現在EXP：" << exp << endl;
		cout << "\n";
	}
}