/*
C++ program request inputs to create HTML file
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // Variables
  string name, bio;
  // Ask name
  cout << "Enter your name: ";
  getline(cin, name);
  // Ask description
  cout << "Describe yourself: ";
  getline(cin, bio);

  cout << "Now writng data to the file.\n";

  // Writing HTML file
  ofstream bioFile;
  bioFile.open("bio.html");
  bioFile << "<html>\n<head>\n</head>\n<body>\n\t<center>";
  bioFile << "\n\t\t<h1>" << name << "</h1>";
  bioFile << "\n\t</center>\n\t<hr />\n\t";
  bioFile << bio;
  bioFile << "\n\t<hr />\n</body>\n</html>";

  cout << "Done!";
  
  return 0;
  
}
