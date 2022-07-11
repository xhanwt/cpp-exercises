/*
Calculate the average of tests - requests 6 test scores, drops lowest score and calculates average
*/
#include <iostream>
#include <iomanip>
using namespace std;

void getScore(int &);
void calcAverage(int, int, int, int, int, int);
int findLowest(int, int, int, int, int, int);

int main() {
	int testScore1,
		testScore2,
		testScore3,
		testScore4,
		testScore5,
		testScore6;

	// get the score of 6 tests
	for (int i = 0; i < 6; i++){
		if (i == 0) {
			getScore(testScore1);
		}
		else if (i == 1) {
			getScore(testScore2);
		}
		else if (i == 2) {
			getScore(testScore3);
		}
		else if (i == 3) {
			getScore(testScore4);
		}
		else if (i == 4) {
			getScore(testScore5);
		}
		else if (i == 5) {
			getScore(testScore6);
		}
	} // end of for loop

	calcAverage(testScore1, testScore2, testScore3, testScore4, testScore5, testScore6);


	return 0;
}

void getScore(int &score) {
	int validScore;
	cout << "Enter the score of the test: ";
	cin >> validScore;
	// validate user entry
	while ((validScore < 0) || (validScore > 100)) {
		cout << "Test scores values can only be between 0 and 100." << endl
			<< "Please reenter the test score: ";
		cin >> validScore;
	}
	score = validScore;
}

void calcAverage(int score1, int score2, int score3, int score4, int score5, int score6) {

	int dropScore = findLowest(score1, score2, score3, score4, score5, score6);
	int sum = score1 + score2 + score3 + score4 + score5 + score6 - dropScore;
	double average = sum / 5.0;

	cout << setprecision(2) << fixed << showpoint;
	cout << "The average score of your tests is: " << average << endl;
}

int findLowest(int score1, int score2, int score3, int score4, int score5, int score6) {
	int lowestScore;
	
		lowestScore = score1;
	
	if (score2 < lowestScore) {
		lowestScore = score2;
	}
	if (score3 < lowestScore) {
		lowestScore = score3;
	}
	if (score4 < lowestScore) {
		lowestScore = score4;
	}
	if (score5 < lowestScore) {
		lowestScore = score5;
	}
	if (score6 < lowestScore) {
		lowestScore = score6;
	}
	return lowestScore;
}
