//
//  main.cpp
//  RemoveNodesFromLinkedList
//
//  Created by Jaime Cuartas Granada on 6/5/2024.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNodes(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode * curr = head;
    ListNode * prev = nullptr;
    while(curr!=nullptr){
        ListNode * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr = prev->next;
    prev->next = nullptr;
    while(curr!=nullptr){
        ListNode * next = curr->next;
        if(curr->val>=prev->val){
            curr->next = prev;
            prev = curr;
        }
        curr = next;
    }
    return prev;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    removeNodes(new ListNode(5, new ListNode(2, new ListNode(13, new ListNode(3, new ListNode(8))))));
    return 0;
}
