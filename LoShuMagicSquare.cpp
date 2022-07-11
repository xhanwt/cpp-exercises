// Lo Shu Magic Square
#include<iostream>
using namespace std;

// Global constants
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
void showResult(int[][COLS]);
void showArray(int[][COLS]);
bool isMagicSquare(int[][COLS]);
bool checkRange(int[][COLS]);
bool checkUnique(int[][COLS]);
bool checkRowSum(int[][COLS]);
bool checkColSum(int[][COLS]);
bool checkDiagSum(int[][COLS]);


int main()
{
    // Create a magic two-dimensional array.
    int magicArray[ROWS][COLS] = { {4, 9, 2},
                                   {3, 5, 7},
                                   {8, 1, 6} };

    // Create a normal two-dimensional array.
    int normalArray[ROWS][COLS] = { {10, 2, 3},
                                    {4, 15, 6},
                                    {7, 8, -8} };

    // Display the normal array.
    showArray(normalArray);

    // Test the normal array and display the result.
    showResult(normalArray);

    // Display the magic array.
    showArray(magicArray);

    // Test the magic array and display the result.
    showResult(magicArray);

    return 0;
}

// The showResult function accepts a two-dimensional int  *
// array as an argument, tests to determine if it is a    *
// Lo Shu Magic Square and displays the result.           *
// ********************************************************
void showResult(int values[][COLS])
{
  // Determine magic square
    if(isMagicSquare(values)) {
        cout << "This is a Lo Shu Magic Square.\n";
    }
    else cout << "This is NOT a Lo Shu Magic Square.\n";
}

// ********************************************************
// The showArray function accepts a two-dimensional int   *
// array as an argument and displays its contents.        *
// ********************************************************
void showArray(int values[][COLS])
{
// Show each row
    for(int row = 0; row < ROWS; row++){
        // Show each colum in row
        for(int col = 0; col < COLS; col++){
            cout << values[row][col] << "  ";
                }
        // Separate line for next row
        cout << endl;
    }
}

// ********************************************************
// The isMagicSquare function accepts a two-dimensional   *
// int array as an argument, and returns true if the      *
// array meets all the requirements of a magic square.    *
// Otherwise, it returns false.                           *
// ********************************************************
bool isMagicSquare(int values[][COLS])
{
    // Initialize the status to false.
    bool status = false;

    // Call the functions to check the array.
    bool isInRange = checkRange(values);
    bool isUnique = checkUnique(values);
    bool isEqualRows = checkRowSum(values);
    bool isEqualCols = checkColSum(values);
    bool isEqualDiag = checkDiagSum(values);

    // Determine if the array meets all the requirments.
    if (isInRange &&
        isUnique &&
        isEqualRows &&
        isEqualCols &&
        isEqualDiag)
    {
        // If so, set the status to true.
        status = true;
    }

    // Return the status.
    return status;
}

// ********************************************************
// The checkRange function accepts a two-dimensional int  *
// array as an argument, and returns true if the values   *
// are within the specified range. Otherwise, it returns  *
// false.                                                 *
// ********************************************************
bool checkRange(int values[][COLS])
{
    // Get each row
  for(int r = 0; r < ROWS; r++){
      // Get each column in a row
      for(int c = 0; c < COLS; c++){
          if (values[r][c] < MIN || values[r][c] > MAX){
              return false;
          } 
      }
  }
    return true;
}

// ********************************************************
// The checkUnique function accepts a two-dimensional int *
// array as an argument, and returns true if the values   *
// in the array are unique. Otherwise, it returns false.  *
// ********************************************************
bool checkUnique(int values[][COLS])
{
// Get each element from array
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            // Compare to elements in the same row and next row
            int count = 0;
            
            for(int nr = r; nr < ROWS; nr++){
                for(int nc = 0; nc < COLS; nc++){
                   if(values[r][c] == values[nr][nc]){
                       count++;
                     }
                    }  
                   if(count > 1) return false;
                  }        
        }
    }
    return true;
}

// ********************************************************
// The checkRowSum function accepts a two-dimensional     *
// int array as an argument, and returns true if the sum  *
// of the values in each of the array's rows are equal.   *
// Otherwise, it returns false.                           *
// ********************************************************
bool checkRowSum(int values[][COLS])
{
   // First row sum
    int RowSumInit = 0;
    for(int i = 0; i < COLS; i++){
        RowSumInit += values[0][i];
    }
    // Sum next rows
    // Each row
    for(int r = 1; r < ROWS; r++){
        int RowSum = 0; // Sum of each row
        // Each element in a row
        for(int e = 0; e < COLS; e++){
            RowSum += values[r][e];
        }
        if (RowSum != RowSumInit){
            return false;
        }
    }
    return true;
}

// ********************************************************
// The checkColSum function accepts a two-dimensional     *
// int array as an argument, and returns true if the sum  *
// of the values in each of the array's columns are       *
// equal. Otherwise, it returns false.                    *
// ********************************************************
bool checkColSum(int values[][COLS])
{ 
    // First col sum
    int ColSumInit = 0;
    for(int i = 0; i < ROWS; i++){
        ColSumInit += values[i][0];
    }
    // Sum next columns
    // Each col
    for(int c = 0; c < COLS; c++){
        int ColSum = 0; // Sum of each row
        // Each element in a column
        for(int e = 0; e < ROWS; e++){
            ColSum += values[e][c];
        }
        if (ColSum != ColSumInit){
            return false;
        }
    }
    return true;
}

// ********************************************************
// The checkDiagSum function accepts a two-dimensional    *
// int array as an argument, and returns true if the sum  *
// of the values in each of the array's diagonals are     *
// equal. Otherwise, it returns false.                    *
// ********************************************************
bool checkDiagSum(int values[][COLS])
{
 
    // Sum from upper left to bottom right diagonal
    int DiagSumULBR = 0;
    for(int x = 0; x < COLS;x++){
        DiagSumULBR += values[x][x];
    }

    // Sum from bottom left to upper right diagonal
    int DiagSumBLUR = 0;
    int y = ROWS - 1;
    for(int x = 0; x < COLS; x++, y--){
        DiagSumBLUR += values[x][y];
    }
    // Return true/ false
    return DiagSumULBR == DiagSumBLUR;
}
