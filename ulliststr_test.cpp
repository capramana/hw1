/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  // Create a new list
  // Call push_front and print list if it's 
  // what u expected it to be
  // Run while loop through values (cout)
  // Then go to next node
  // Change node to node->next

  /*
  Same thing as front() and back() on empty list so no need:
  ULListStr thing;
  cout << thing.get(0) << endl;
  */

  cout << "Next test:" << endl;
  // Push back and front
  ULListStr dat;
  dat.push_back("1"); // 1
  dat.push_front("4"); // 2
  dat.push_back("8"); // 3
  dat.push_front("10"); // 4
  dat.push_back("12"); // 5
  dat.push_front("9"); // 6
  dat.push_back("56"); // 7
  dat.push_front("32"); // 8
  dat.push_back("51"); // 9
  dat.push_back("38"); // 10
  dat.push_back("91"); // 11
  dat.push_back("0"); // 12
  dat.push_front("2"); // 13

  for (int i = 0; i < 13; i++) {
    cout << dat.get(i) << endl;
  }

  cout << "Next test:" << endl;
  ULListStr test;
  test.push_back("1"); // 1
  test.push_front("4"); // 2
  test.push_back("8"); // 3
  test.pop_front(); // pops 4
  test.pop_back(); // pops 8
  test.push_front("9"); // 4
  test.push_back("56"); // 5
  test.pop_front(); // pops 9
  test.push_back("51"); // 6
  test.push_back("38"); // 7
  test.push_back("91"); // 8
  test.pop_back(); // pops 91
  test.push_front("2"); // 9
  // 9 - 4 = 5 things

  for (int i = 0; i < 5; i++) {
    cout << test.get(i) << endl;
  }

  cout << "Next test:" << endl;
  cout << test.back() << endl; // 38
  cout << test.front() << endl; // 2

  /*
  ULListStr dat;
  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");
  cout << "0: " << dat.get(0) << endl;
  cout << "1: " << dat.get(1) << endl;
  cout << "2: " << dat.get(2) << endl;
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  // prints: 8 7 9
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
  */
  return 0;
}
