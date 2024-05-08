//
//  main.cpp
//  DoubleNumberRepresentedLinkedList
//
//  Created by Jaime Cuartas Granada on 7/5/2024.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* doubleIt(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while(curr!=nullptr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    curr = prev;
    prev = nullptr;
    int quotient = 0;
    int remainder = 0;
    while(curr!=nullptr){
        ListNode* temp = curr->next;
        int doubleIt = curr->val*2;
        curr->val = doubleIt%10 + remainder;
        remainder = doubleIt/10;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    if(remainder>0) prev = new ListNode(remainder, prev);
    return prev;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    doubleIt(new ListNode(3));
    doubleIt(new ListNode(9, new ListNode(9, new ListNode(9))));
    return 0;
}
