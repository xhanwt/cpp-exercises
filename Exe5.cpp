// This program calculate the total sum of prime numbers between 1 and the user-provided value that end with the digit 7

#include <iostream>
#include <fstream>
using namespace std;

// Function Prototypes
bool is_prime(int);
bool endsWith7(int);
bool input_is_invalid(int&);


int main() {
  // Variables
  int num;
  int sum = 0;

  // Ask for user input
  cout << "Please enter an integer value greater than one: ";
  cin >> num;
  
  // Validate input
  while (input_is_invalid(num)) {
    cout << "ERROR: Please enter an integer value greater than one: ";
    cin >> num;
  }

  // Write data to a text file
  ofstream textFile;
  textFile.open("prime.txt");
  // Can't open the file
  if (!textFile) {
    cout << "ERROR: Can't to access text file.";
    exit(0);
  }

  // Start writing
  cout << "Writing data to the text file." << endl;

  // Check the numbers between 2 and the user provided value
  for (int i = 2; i < num; i++) {

    // Check the conditions
    if (is_prime(i) && endsWith7(i)) {

      // Write if the number is the first to output
      if (sum == 0) {
        textFile << "All prime numbers between 2 and " << num << " that end with digit 7 "
                    "are: ";
      }

      // Write if the number is not the first one
      if (sum > 0) {
        textFile << ", ";
      }

      // Add the number to the sum
      sum += i;

      // Write to the file
      textFile << i;
    }
  }

  // If no number is found
  if (sum == 0) {
    textFile
        << "There is no prime numbers between 2 and 100 that end with digit 7.";
    exit(0); // exit the program
  }

  // Write the sum result
  textFile << "\nThe sum of all prime numbers between 2 and 100 that end with "
              "digit 7 is: "
           << sum;

  // Writing done
  cout << "The text file is ready!" << endl;

  //Close the text file
  textFile.close();
  return 0;
}

// Function to validate input
bool input_is_invalid(int& num) {
  if (num <= 1 || !cin.good()) {
    cin.clear();
    cin.ignore(80, '\n');
    return true;
  } else
    return false;
}

// Function to check if the number ends with 7
bool endsWith7(int num) {
  if (num % 10 == 7) {
    return true;
  } else
    return false;
}

// Function to check if the number is prime
bool is_prime(int num) {
  bool flag = true;
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
