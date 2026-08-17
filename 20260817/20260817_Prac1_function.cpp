#include <iostream>
using namespace std;

#include "20260817_Prac1_header.h"

//球種の表示関数
void PitingType(int piting)
{
    
    switch (piting)
    {
	case 0:
		cout << "ストレートを投げました" << endl;
		break;
	case 1:
		cout << "カーブを投げました" << endl;
		break;
	case 2:
		cout << "スライダーを投げました" << endl;
		break;
	case 3:
		cout << "シンカーを投げました" << endl;
		break;

    }
}

//リザルト関数
void Result(int out)
{
    if (out >= 3)
    {
        cout << "PLAYER WINNER!!" << endl;
    }
    else
    {
        cout << "CPU WINNER!!" << endl;
    }
}