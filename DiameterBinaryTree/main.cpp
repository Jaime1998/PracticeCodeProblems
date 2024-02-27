//
//  main.cpp
//  DiameterBinaryTree
//
//  Created by Jaime Cuartas Granada on 27/2/2024.
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

int max(int a, int b){
    return (a>b)? a:b;
}

int deepVertical(TreeNode * root) {
    if(root==nullptr) return 0;
    return 1+max(deepVertical(root->left), deepVertical(root->right));
}

int diameterOfBinaryTree(TreeNode* root) {
    
    if(root==nullptr) return 0;
    int deepLeft = deepVertical(root->left);
    int deepRight = deepVertical(root->right);
    int diameterLeft = diameterOfBinaryTree(root->left);
    int diameterRight = diameterOfBinaryTree(root->right);
    return max(deepLeft + deepRight + 1, max(diameterLeft, diameterRight));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << deepVertical(new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3))) << "\n";
    
    std::cout << diameterOfBinaryTree(new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3))) << "\n";

    return 0;
}
