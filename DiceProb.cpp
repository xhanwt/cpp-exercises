// Probability of rolling two dices

#include <iostream>
#include <iomanip>
#include <random> 
using namespace std;

int NUMBER_OF_EXPERIMENTS = 1E5;
const double PERCENT = 100.0;

int rollDice();
double calcProbability(int, int, int);


int main()
{
 

  // Display
    cout << showpoint << fixed << setprecision(2);
    cout << PERCENT * calcProbability(NUMBER_OF_EXPERIMENTS, 6, 6) << "%" << endl;
 
    return 0;
}

double calcProbability(int number, int roll1, int roll2) {
  int count = 0;

  // Roll and count
  for(int i = 0; i <= number; i++) {

    if (rollDice() == roll1 && rollDice() == roll2) {
      count++;
    }
    
  }

  return static_cast<double>(count) / number;
}

int rollDice() {
  // Random number
    random_device myEngine;
    uniform_int_distribution<int> randomInt(1, 6);
    
  int num = randomInt(myEngine);
  return num;
}
