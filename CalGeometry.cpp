// This program calculates geometry
#include <iostream>
using namespace std;

int main()
{
  // Variable for selection
  int choice;

  // Display menu and ask user's choice
  cout << "\t\tGeometry Calculator\n\n1. Calculate the area of a Circle\n2. Calculate the area of a Rectangle\n3. Calculate the area of a Triangle\n4. Quit\n\nEnter your choice (1-4): ";
  cin >> choice;

  // Excute area calculation based on user's choice
  switch (choice) {

    //### Area of a Circle
    case 1: 
    {
      const double pi = 3.14159; // pi value constant
      double r; // variable for radius

      // Ask for the radius of the circle
      cout << "Enter the radius of the circle: ";
      cin >> r;

      // Check if radius entered is a positive numeric value
      if(r && r >= 0) {
        // Formula to calculate area of a circle
        double A = pi * r * r;
        // Display the result area of the circle
        cout << "Area of the Circle: " << A << " square unit" << endl;
      }
      else cout << "The radius must be a positive numeric value." << endl;
    break;
    }

    //### Area of a Rectangle
    case 2: 
    {
      // Variables
      double l, // length
             w; // width

      // Ask for the length of the Rectngle
      cout << "Enter the length of the Rectangle: ";
      cin >> l;

      // Check if length entered is a positive numeric value
      if(l && l >= 0) {
        
        // Ask for the width of the rectangle
        cout << "Enter the width of the Rectangle: ";
        cin >> w;

        // Check if width entered is a positive numeric value
        if(w && w >= 0){
          
          // Formula to calculate area of a rectangle
          double A = l * w;

          // Display the result area of the rectangle
         cout << "Area of the Rectangle: " << A << " square unit" << endl;
        }
        else cout << "The width must be a positive numeric value." << endl;
      }
      else cout << "The length must be a positive numeric value." << endl;
    break;
    }

    //### Area of a Triangle
    case 3: 
    {
      // Variables
      double b, // base
             h; // height
     const double half = 0.5; // constant in the Triangle calculation

      // Ask for the base of the triangle
      cout << "Enter the length of base of the Triangle: ";
      cin >> b;

      // Check if base entered is a positive numeric value
      if(b && b >= 0) {
       // Ask for the height of the triangle
       cout << "Enter the height of the Triangle: ";
       cin >> h;
        // Check if height entered is a positive numeric value
        if(h && h >= 0){
          // Formula to calculate the area of a trianglel
          double A = b * h * half;
          // Display the result area of the triangle
        cout << "Area of the Triangle: " << A << " square unit" << endl;
        }
        else cout << "The height must be a positive numeric value." << endl;
      }
      else cout << "The base must be a positive numeric value." << endl;
    break;
    }

    // Quit program
    case 4: cout << "Program quit! ✅" << endl;
    break;

    // Error message for selections outside of the range
    default: cout << "⚠️ Error: Please choose an option from the range of 1-4." << endl;
  }
  return 0;
}
