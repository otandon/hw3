#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (!head) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    Node* curr = head;
    Node* remaining = head -> next;
    curr -> next = nullptr;

    llpivot(remaining, smaller, larger, pivot);

    if (curr -> val <= pivot) {
        curr -> next = smaller;
        smaller = curr;
    } else {
        curr -> next = larger;
        larger = curr;
    }

    head = nullptr;
}



