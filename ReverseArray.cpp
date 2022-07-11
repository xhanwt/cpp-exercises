// This program reverse an array

#include<iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
int* reverseArray(int[], int);
void showArray(int[], int);


int main() {
  const int SIZE = 10;
  int values[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  // Display the contents of the array.
  cout << "The contents of the original array are:\n";
  showArray(values, SIZE);
  // Make a reverse copy of the array.
  int* arrCopy = reverseArray(values, SIZE); 
  // Display the contents of the new array.
  cout << "The contents of the copy are:\n";
  showArray(arrCopy, SIZE);
  return 0; 
  }

void showArray(int arr[], int size){
  // Show each element in array
  for(int i = 0; i < size; i++){
    cout << setw(3) << arr[i];
  }
  cout << endl;
}

int* reverseArray(int arr[], int size){
  
  int begin = 0, // First position
  end = size - 1; // Last position

  // Swap elements in reverse
  while(begin < end) {

    int temp = arr[begin];
        arr[begin] = arr[end];
        arr[end] = temp;
    
    begin++;
    end--;
  }

  return arr;
}
