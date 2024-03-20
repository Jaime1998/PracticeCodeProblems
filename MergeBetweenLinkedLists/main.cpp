//
//  main.cpp
//  MergeBetweenLinkedLists
//
//  Created by Jaime Cuartas Granada on 20/3/2024.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* listA = list1;
    int i=0;
    while(a>++i) listA = listA->next;
    ListNode* listB = listA->next;
    listA->next = list2;
    while(b>=i++) listB = listB->next;
    while(list2->next != nullptr)list2 = list2->next;
    list2->next = listB;
    return list1;
}

int main(int argc, const char * argv[]) {
    ListNode* list1 = new ListNode(10, new ListNode(1, new ListNode(13, new ListNode(6, new ListNode(9, new ListNode(5))))));
    ListNode* list2 = new ListNode(1000000, new ListNode(1000001, new ListNode(1000002)));
    ListNode* list3 = mergeInBetween(list1, 3, 4, list2);
    return 0;
}
