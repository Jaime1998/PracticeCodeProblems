//
//  main.cpp
//  RemoveNthNodeEndList
//
//  Created by Jaime Cuartas Granada on 3/3/2024.
//

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(n==0) return head;
    std::vector<ListNode*> memory;
    ListNode * currentNode = head;
    while(currentNode!=nullptr){
        memory.push_back(currentNode);
        currentNode = currentNode->next;
    }
    size_t sizeMemory = memory.size();
    if((sizeMemory-n)==0) return head->next;
    memory[sizeMemory-n-1]->next = memory[sizeMemory-n]->next;
    return head;
}

int main(int argc, const char * argv[]) {
    ListNode * head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    ListNode * head1 = new ListNode(1, new ListNode(2, nullptr));
    ListNode * head2  = removeNthFromEnd(head1, 1);
    
    while(head2!=nullptr){
        std::cout << head2->val << "\n";
        head2 = head2->next;
    }
    return 0;
}
