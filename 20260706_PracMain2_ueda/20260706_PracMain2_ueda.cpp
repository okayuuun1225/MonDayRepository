#include <iostream>
#include <ctime>
#include <cstdlib>
#include "20260706_Header2_ueda.h"
using namespace std;

int main(void)
{
	//乱数初期化
	srand((unsigned int)time(NULL));
	//ゲーム開始
	Game();

	return 0;
}