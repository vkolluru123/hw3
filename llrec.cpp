#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  
  // base step: empty list, done with all nodes
  if (head == nullptr) {
    smaller=nullptr;
    larger=nullptr;
    return;
  }

  llpivot(head->next, smaller, larger, pivot);

  // recursive step: checking against the given number
  // value is less than or equal to the pivot
  if ((head -> val) <= pivot) {
    // put it in the smaller list and update the head
    head -> next = smaller;
    smaller = head;
  }
  // value is greater than the pivot
  else if ((head -> val) > pivot) {
    // put it in larger list and update the head
    head -> next = larger;
    larger = head;
  }

  // disconnect node
  head=nullptr;

  
  
}