#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260817_Prac1_header.h"

using namespace std;

//定数宣言
//球種の最大、最小
const int PITING_MIN = 0;
const int PITING_MAX = 3;

//乱数用定数
const int PROBABILITY = 4;

//ストライク、ボール、アウト、ヒットの最大数
const int STRIKE_COUNT = 3;
const int BALL_COUNT = 4;
const int OUT_COUNT = 3;
const int HIT_COUNT = 4;

//メイン関数
int main(void)
{
	//変数宣言
    //プレイヤー、CPUの球種入力
    int ply, emy;
	//乱数生成用変数
    int prod;
	//ストライク、ボール、アウト、ヒットのカウント
    int Strike = 0;
    int Ball = 0;
    int Out = 0;
    int Hit = 0;

    //乱数初期化
    srand((unsigned int)time(NULL));

    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;

	//ゲームループ
    while (Out < OUT_COUNT && Hit < HIT_COUNT)
    {
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート "
            << "1:カーブ "
            << "2:スライダー "
            << "3:シンカー"
            << endl;

        //入力チェック
        while (true)
        {
            cin >> ply;

            if (PITING_MIN > ply || PITING_MAX < ply)
            {
                cout << "入力に誤りがあります。"
                    << "再度入力してください。"
                    << endl;
            }
            else
            {
                break;
            }
        }

        //球種表示の関数呼び出し
        PitingType(ply);

		//CPUの球種を乱数で決定
        emy = rand() % PROBABILITY;

		//判定用の乱数を生成
        prod = rand() % PROBABILITY;

		//判定
        if (ply != emy)
        {
            if (prod == 0)
            {
                cout << "ボール！" << endl;
                Ball++;
            }
            else
            {
                cout << "ストライク！！" << endl;
                Strike++;
            }
        }

        else
        {
            Strike = 0;
            Ball = 0;

            if (prod == 1)
            {
                cout << "OUT!!!" << endl;
                Out++;
            }
            else
            {
                cout << "HIT!!" << endl;
                Hit++;
            }
        }

		//ストライク、ボールのカウントが最大数になったとき、out、hitのカウントを増やす
        if (Strike >= STRIKE_COUNT || Ball >= BALL_COUNT)
        {
            if (Strike >= STRIKE_COUNT)
            {
                Out++;
            }
            else
            {
                Hit++;
            }

			//ストライク、ボールのカウント初期化
            Strike = 0;
            Ball = 0;
        }

		//現在のカウントを表示
        cout << "B:" << Ball << endl;
        cout << "S:" << Strike << endl;
        cout << "O:" << Out << endl;
        cout << "Runner:" << Hit << endl;

    } 

	//リザルト表示の関数呼び出し
    Result(Out);

    return 0;
}