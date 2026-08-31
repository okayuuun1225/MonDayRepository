#pragma once
class ScoreManager
{
private:
	int currentScore = 0;
	int highScore = 0;
public:
	int addPoints(int points);
	int resetScore();
	int updateHighScore();
	void displayScores();
};

