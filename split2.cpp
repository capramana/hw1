/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  // Sudo:
  // Check if it's a nullptr. If it is, we've gone through the whole linked list
  // Else: check if it's odd or evens
  // Check if odd:
    // If odd then add the value of in to odds linked list
  // Otherwise, it's even:
    // Add value to evens linked list

  temp = nullptr;
  evens = nullptr;
  odds = nullptr;

  if (in == nullptr) {
    return;
  }
  else if (in->value % 2 == 0) { // If even
    evens = temp->value;
    split(in->next, temp->next, odds->next);
  }
  else {
    odds = temp->value;
    split(in->next, evens->next, odds->next);
  }


/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE