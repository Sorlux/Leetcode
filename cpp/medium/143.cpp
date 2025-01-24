#include <iostream>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}};
 
 // Let x represent the start of the linked list and y represent the end
 // Instead of how it originally is, we alternate between x+1 and y-1
 // In order for me to get the last node I must traverse the entire list
 // Maybe have a vector which will hold all the addresses and then loop through that?
 // Or have two pointers where we have one go all the way to the end and then begin to push both closer to each other till LNode = Rnode
 
 // Looks Like I was close to the answer, if we have two pointers go through the linked list, one slow and one fast, then we can split the linked list in half
 // Then we just need to reverse the 2nd half and merge it to the first half by weaving in and out

 

void reorderList(ListNode* head) {
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;

    // Common algorithm you will use whenever you run into something requiring halving a linked list
    while (fastPtr && fastPtr->next) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }

    ListNode* secondHalf = slowPtr->next; // new head for the second half
    slowPtr->next = nullptr; //Will cut off the the first half of the list from the second

    // Now you will take the values inbetween slowptr and fastptr and reverse the order
    ListNode* curr = secondHalf;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    // Remember that this will leave prev as the head of the second half
    while (curr) {
        next = curr->next;
        curr-> next = prev;
        prev = curr;
        curr = next;
    }

    // Now we will use a merging algorithm to merge the two
    ListNode* firstHalf = head;

    while (prev) {
        ListNode* tempFirst = firstHalf->next;
        ListNode* tempSecond = prev->next;
        firstHalf->next = prev;
        prev->next = tempFirst;
        firstHalf = tempFirst;
        prev = tempSecond;
    }


}


int main() {

    // Creating a linked list
    // Remember to never use head directly or else you will lose the start of your linked list
    ListNode* head = new ListNode(1);
    ListNode* current = head;

    for (int i = 2; i < 6; i++) {
        current->next = new ListNode;
        current = current-> next;
        current->val = i;
    }
    current->next = nullptr;

    reorderList(head);

    current = head;
    while (current != NULL) {
        std::cout << current->val << std::endl;
        current = current->next;
    }


    return 0;
}