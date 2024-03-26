//
//  main.cpp
//  ReverseLinkedList
//
//  Created by Jaime Cuartas Granada on 21/3/2024.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if(head==nullptr) return nullptr;
    ListNode* prev = nullptr;
    ListNode* post = head->next;
    while(head!=nullptr){
        post = head->next;
        head->next = prev;
        prev = head;
        head = post;
    }
    return prev;
}

int main(int argc, const char * argv[]) {
    ListNode* a = new ListNode(1, new ListNode(2, new ListNode(3)));
    reverseList(a);
    return 0;
}
