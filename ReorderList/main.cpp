//
//  main.cpp
//  ReorderList
//
//  Created by Jaime Cuartas Granada on 26/3/2024.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    ListNode * slow = head;
    ListNode * curr = head;
    while(curr!=nullptr && curr->next != nullptr){
        curr = curr->next->next;
        slow = slow->next;
    }
    if(curr!=nullptr) slow = slow->next;
    ListNode * reverse = nullptr;
    while(slow != nullptr){
        curr = slow->next;
        slow->next = reverse;
        reverse = slow;
        slow = curr;
    }
    curr = head;
    ListNode* tempCurr;
    ListNode* tempReverse;
    while(reverse != nullptr){
        tempCurr = curr->next;
        curr->next = reverse;
        tempReverse = reverse->next;
        reverse->next = tempCurr;
        reverse = tempReverse;
        curr = tempCurr;
    }
    curr->next = nullptr;
}

int main(int argc, const char * argv[]) {
    ListNode * ln = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode * ln1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode * ln2 = new ListNode(1);
    reorderList(ln1);
    return 0;
}
