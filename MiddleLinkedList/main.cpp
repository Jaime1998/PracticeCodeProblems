//
//  main.cpp
//  MiddleLinkedList
//
//  Created by Jaime Cuartas Granada on 7/3/2024.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    while(fast != nullptr && fast->next!=nullptr){
        head = head->next;
        fast = fast->next->next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    ListNode * result = middleNode(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    std::cout << result->val << "\n";
    return 0;
}
