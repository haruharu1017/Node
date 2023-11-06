// Driver program for CSCI 60 Homework 9; due Tuesday 3/12/23
//
// The littleDriverProgram partially tests the Parity member functions.
// Note that the class allows clients to insert 0, but this program doesn't
// because 0 is used as a sentinal value. Also note that the program assumes
// the user doesn't enter any non-ints and will throw an uncaught exception if
// the user provides the wrong input. (Test programs don't have to be robust!)
// You don't have to turn this file in, so use it in any way helpful to you!

#include <iostream>
#include "parity.h"

using namespace std;

void littleDriverProgram();

int main() {
  littleDriverProgram();
  return 0;
}

void littleDriverProgram() {
  Parity lists;
  cout << "Enter a list of ints, one per line, 0 to end:\n";
  int val;
  while (true) {
    cin >> val;
    if (val==0) break;
    lists.insert(val);
  }
  cout << lists << endl; 
  cout << "The max value you entered is " << lists.max() << endl;
  cout << "The min value you entered is " << lists.min() << endl;
  // TODO: write your own code for additional testing

  Parity l;
  l = lists;
  cout << "new lists: \n" << lists << endl;
}
