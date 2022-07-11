// This program compares two sorting algorithms in C++
#include <iostream>
#include <random>
using namespace std;

// Function prototypes
int bubbleSort(long[], int); 
int selectionSort(long[], int);
void swap(int&, int&);

// global constants
const int NUM_EXP = 100; // Number of experi
const int SIZE = 100; // Array size


int main(){
  // Sum of counts for each sorting
  int ExcBS = 0;
  int ExcSS = 0;

  // Arrays with randomly generated long ints
  long BSArray[SIZE];
  long SSArray[SIZE];

  // Random engine
  random_device myEngine;
  uniform_int_distribution<long> randomInt(0, 100L);
  
  for(int exp = 0; exp < NUM_EXP; exp++){
    
    // Generate and assign random numbers
    for (int i = 0; i < SIZE; i++) {
    
    long int x = randomInt(myEngine);
      BSArray[i] = x;
      SSArray[i] = x;
    }
     // Record counts
     ExcBS += bubbleSort(BSArray, SIZE);
     ExcSS += selectionSort(SSArray, SIZE);
  }
    // Display averages
    cout << ExcBS / static_cast<double>(NUM_EXP) << " exchanges were made by Bubble Sort on average." << endl;
    cout << ExcSS / static_cast<double>(NUM_EXP) << " exchanges were made by Selection Sort on average." << endl;
    
    return 0;
}


// Bubble sort function
int bubbleSort(long array[], int size) {
  int maxElement;
  int count = 0;
  int index;
  
  for (maxElement = size - 1; maxElement > 0; maxElement--) {
  for (index = 0; index < maxElement; index++) {
  if (array[index] > array[index + 1]) 
   {
   swap(array[index], array[index + 1]);
     // Count swap
     count++;
   }
  } 
  }
  return count;
}


  // Selection sort function
int selectionSort(long array[], int size) {
  int minIndex, minValue;
  int count = 0;
  for (int start = 0; start < (size - 1); start++) {
  minIndex = start;
  minValue = array[start];
  for (int index = start + 1; index < size; index++) {
  if (array[index] < minValue) {
  minValue = array[index];
  minIndex = index; 
    // Count swap
    count++;
    }
  }
  swap(array[minIndex], array[start]); 
    }
  return count;
}


// Swap function
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
