#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val)
// Add to the back
{
  // If it's empty 
  if (empty()) {
    Item* temp = new Item();
    head_ = temp;
    tail_ = temp;
    // Since it's empty the first index is the val
    temp->val[0] = val;
    temp->last++;
  }
  // else if there's space and space is at the back
  else if (tail_->last != ARRSIZE) { // Filled, not full
  // Add to the back 
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else { // If not full
  // Create new Item and the prev one was our original
    Item* temp = new Item();
    // Reassign the next and prev
    tail_->next = temp;
    temp->prev = tail_;
    tail_ = temp;
    temp->val[0] = val;
    temp->last++;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val)
{
  // If empty
  if (empty()) {
    Item* temp = new Item;
    head_ = temp;
    tail_ = temp;
    temp->val[0] = val;
    temp->last++;
  }
  // else if there's space & space is in front
  else if (head_->first != 0) { // Filled, not full
    head_->val[head_->first - 1] = val;
    head_->first--;
  }
  else { // If full
    // Create new Item that goes before the curr Item
    Item* temp = new Item;
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
    temp->val[ARRSIZE-1] = val;
    temp->first = ARRSIZE - 1;
    temp->last = ARRSIZE;
  }
  size_++;
}

void ULListStr::pop_back() // Remove last one
{
  // If empty
  if (empty()) {
    return;
  }
  else if (tail_->last - tail_->first == 1) { // first = 0, last = 1
    // If there's only 1 item in the list
    // We have to delete the entire node
    // Then move first to the other one
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->next = NULL;
  }
  else {
    tail_->last--;
  }
  size_--;
}

void ULListStr::pop_front()
{
  if (empty()) {
    return;
  }
  else if (head_->last - head_->first == 1) {
    head_ = head_->next;
    delete head_->prev;
    head_->prev = NULL;
  }
  else {
    head_->first++;
  }
  size_--;
}

string const &ULListStr::back() const // Return (last - 1) value
{
  return tail_->val[(tail_->last)-1];
}

string const &ULListStr::front() const // Return first value
{
  return head_->val[head_->first];
}

// while triggers when loc isnt in the node
string* ULListStr::getValAtLoc(size_t loc) const
{
  // Check if loc is in our array size
  if (loc > (size_ - 1) || loc < 0) {
    return NULL;
  }
  else {
    // Create a variable that will point to 
    // the variable that we want
    int initial = 0;
    Item* temp = head_;
    // 1. Make sure we're on the right node
    // 2. Otherwise, go to the next node
    // 3. Once on the right node, use a while loop
    // to iterate through the array in the right node
    // once loc is right, return it

    // Make sure we're on the right node first
    // Use >= not just > because loc starts on 0th node and
    // last is always +1

    while (loc >= ((temp->last - temp->first) + initial)) {
      initial += (temp->last - temp->first);
      temp = temp->next; // Go to next node
    }
    return &(temp->val[temp->first+(loc-initial)]);
  }
}
