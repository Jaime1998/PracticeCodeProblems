//
//  main.cpp
//  LinkedListCycle
//
//  Created by Jaime Cuartas Granada on 6/3/2024.
//

#include <iostream>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(head==nullptr) return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    return 0;
}
