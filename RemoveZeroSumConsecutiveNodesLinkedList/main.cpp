//
//  main.cpp
//  RemoveZeroSumConsecutiveNodesLinkedList
//
//  Created by Jaime Cuartas Granada on 12/3/2024.
//

#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* current = dummy;
    std::unordered_map<int, ListNode*> memory;
    int prefix = 0;
    while(current!=nullptr){
        prefix+=current->val;
        memory.insert_or_assign(prefix, current);
        current=current->next;
    }
    prefix=0;
    current = dummy;
    while(current!=nullptr){
        prefix+=current->val;
        current->next=memory.find(prefix)->second->next;
        current=current->next;
    }
    return dummy->next;
}


int main(int argc, const char * argv[]) {
    ListNode* a = new ListNode(1, new ListNode(-1, new ListNode(-3, new ListNode(3, new ListNode(1, new ListNode(1))))));
    ListNode* b = new ListNode(1, new ListNode(0, new ListNode(1, new ListNode(0, new ListNode(2)))));
    ListNode* c = new ListNode(1, new ListNode(2, new ListNode(-3, new ListNode(3, new ListNode(1)))));
    removeZeroSumSublists(c);
    return 0;
}
