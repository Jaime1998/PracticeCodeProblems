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
    std::set<ListNode*> setNodes;
    if(head==nullptr) return false;
    while(head!=nullptr){
        if(setNodes.contains(head)) return true;
        setNodes.insert(head);
        head = head->next;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    return 0;
}
