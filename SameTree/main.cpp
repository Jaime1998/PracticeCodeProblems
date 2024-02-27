//
//  main.cpp
//  SameTree
//
//  Created by Jaime Cuartas Granada on 26/2/2024.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr) return false;
    if(q == nullptr) return false;
    if(p->val != q->val) return false;
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, const char * argv[]) {
    TreeNode * tn1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode * tn2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    
    std::cout <<"son iguales " << isSameTree(tn1, tn2) << "\n";
    return 0;
}
