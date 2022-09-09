#include <iostream>
#include "split.h"
#include <cstddef>
using namespace std;

int main() { 
  Node* p7 = new Node(31, NULL); // Odd
  Node* p6 = new Node(20, p7);
  Node* p5 = new Node(17, p6); // Odd
  Node* p4 = new Node(13, p5); // Odd
  Node* p3 = new Node(12, p4);
  Node* p2 = new Node(11, p3); // Odd
  Node* in = new Node(10, p2);

  Node* evens = NULL;
  Node* odds = NULL;

  split(in, odds, evens);

  while (odds != NULL) {
    cout << odds->value << " ";
    odds = odds->next;
  }
  cout << endl;
  while (evens != NULL) {
    cout << evens->value << " ";
    evens = evens->next;
  }
  cout << endl;

  delete in;
  delete p2;
  delete p3;
  delete p4;
  delete p5;
  delete p6;
  delete p7;
  delete evens;
  delete odds;
}
