#include <iostream>
#include <ctime>
#include "20260706_Header2_ueda.h"
using namespace std;

//関数プロトタイプ宣言
int InputCheck;
void Game();

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


void Game()
{
	int level,exp = 0;
	int player;
	while (level == ConstNumber::LEVEL_MAX)
	{
		cout << "====================\nLv：" << level << "\nEXP：" << exp << "\n====================" << endl;
	}
	cout << "０：ぐー １：ちょき ２：ぱー\n入力：";

	player = InputCheck(ConstNumber::HAND_MIN,ConstNumber::HAND_MAX);

	int cpu = rand() % (ConstNumber::HAND_MAX+1);

	cout << "\n CPU：" << cpu << endl;

	HandSignPrint(cpu);
	cout << "vs";
	HandSignPrint(cpu);
	cout << "\n";

	int jug = player - cpu;
	if (jug == -1 || jug == 2)
	{
		cout << "WIN\n";
	}
	else if (jug == 0)
	{
		cout << "DRAW\n";
	}
	else
	{
		cout << "LOSE\n";
	}
}