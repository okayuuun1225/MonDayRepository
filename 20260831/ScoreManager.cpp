#include "ScoreManager.h"
#include <iostream>
using namespace std;

int ScoreManager::addPoints(int points)
{
	currentScore += points;
	cout << points << "点加算" << endl;
}

int ScoreManager::resetScore()
{
	currentScore == 0;
	cout << "点数をリセットしました。" << endl;
}

int ScoreManager::updateHighScore()
{
	if (highScore < currentScore)
	{
		highScore = currentScore;
		cout << "ハイスコアを更新しました。" << endl;
	}
	
}

void ScoreManager::displayScores()
{
	cout << "現在のスコア：" << currentScore << endl;
	cout << "ハイスコア：" << highScore << endl;
}