/*
Calculate carrier charges on user input
--------------------------------------------------
Starting time of call      -       Rate per Min
00:00-06:59                -        0.05
07:00-19:00                -        0.45
19:01-23:59                -        0.20
--------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
  // Variables
  double StartT, TMin;
  double RPM = 0.0; // Rate per minute
 
  // Enter starting time
  cout << "Enter starting time (HH.MM): ";
  cin >> StartT;



  while (true) {
    
  // Validate time
  int hour = static_cast<int>(StartT); // hour
  float dec = (StartT - hour) * 100; // Extract decimal part and multiply it by 100 to move first two decimals as int
  int min = static_cast<int>(dec); // Get the int which is the first two decimals for minutes
  float extra = dec - min; // Rest decimals for invalidation if present
    
   if (hour > 23 || hour < 0 || min > 59 || extra > 0 || !cin.good()) {

    cout << "The starting time is invalid. Try again.\n";
    cout << "Enter starting Time (HH.MM): ";
    cin.clear();
    cin.ignore(80, '\n');
    cin >> StartT;
  }

     
 else {
  // Enter minutes
  cout << "Enter the number of minutes of the call: ";
  cin >> TMin;
  // Validation
  while (!cin.good()){
    cout << "Error! Please enter a valid number: ";
    cin.clear();
    cin.ignore(80, '\n');
    cin >> TMin;
  }

  // Pricing
  if (StartT < 7) {
    RPM = 0.05;
  }
  else if (StartT <= 19) {
    RPM = 0.45;
  }
  else if (StartT < 24) {
    RPM = 0.20;
  }
  else {
    cout << "Unknown Error for the input.";
    exit(0);
    }

  // Display rate
  cout << "Rate: " << RPM << "$" << endl;

  // Calculate the charge  
  double charges = TMin * RPM;

  // Display the charges
  cout << "Charges: " << charges << "$" << endl;
    
  return 0;
   }
  }
  
}
