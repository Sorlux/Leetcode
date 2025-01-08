#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next; // Pointer to a ListNode
    ListNode(): val(0), next(nullptr) {} // Default constructor
    ListNode(int x): val(x), next(nullptr) {} // Constructor with given value
    ListNode(int x, ListNode* next): val(x), next(next) {} // Constructor with given value and pointer to next node

};

// Strategy: Use two pointers, one keeping track of our current node and one keeping track of our previous node.
// If we set the next value of our current node to the previous node, and then update prev to curr and curr to next,
// Then we can traverse the entire linked list and flip the arrows as we go along. 
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nextNode = NULL; // Used to keep track of the next node so that we can set the current pointer to the next pointer.
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
    
}


int main() {


    return 0;
}