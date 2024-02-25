//
//  main.cpp
//  AddTwoNumbers
//
//  Created by Jaime Cuartas Granada on 25/2/2024.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * dummy = new ListNode();
    ListNode * current = dummy;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr){
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        
        int digit = x+y+carry;
        carry = digit/10;
        current->next = new ListNode(digit%10);
        current = current->next;
        if(l1 != nullptr) l1 = l1->next;
        if(l2 != nullptr) l2 = l2->next;
    }
    if(carry>0) current->next = new ListNode(carry);
    return dummy;
}

int main(int argc, const char * argv[]) {
    ListNode * l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode * l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode * result = addTwoNumbers(l1, l2)->next;
    
    while(result!=nullptr){
        std::cout << result->val;
        result = result->next;
    }
    std::cout << "\n";
    return 0;
}
