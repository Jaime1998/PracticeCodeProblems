//
//  main.cpp
//  PalindromeLinkedList
//
//  Created by Jaime Cuartas Granada on 22/3/2024.
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

bool isPalindromeVector(std::vector<int> vector){
    int n = static_cast<int>(vector.size())-1;
    int i=0;
    while(i<=n/2 && vector[i] == vector[n-i]){
        i++;
    }
    return i=n/2;
}

bool isPalindrome(ListNode* head) {
    std::vector<int> v;
    while(head!=nullptr){
        v.push_back(head->val);
        head = head->next;
    }
    return isPalindromeVector(v);
}

int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1, new ListNode(2));
    ListNode* head1 = new ListNode(1);
    isPalindrome(head1);
    return 0;
}
