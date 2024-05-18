//
//  main.cpp
//  DistributeCoinsBinaryTree
//
//  Created by Jaime Cuartas Granada on 18/5/2024.
//

#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int distributeCoins(TreeNode* root, int valParent = 0) {
    int ans = 0;
    std::stack<TreeNode*> nodeStack;
    std::stack<TreeNode*> postorderStack;
    TreeNode* node = root;
    
    while (node || !nodeStack.empty()) {
        while (node) {
            nodeStack.push(node);
            postorderStack.push(node);
            node = node->left;
        }
        if (!nodeStack.empty()) {
            node = nodeStack.top();
            nodeStack.pop();
            node = node->right;
        }
    }
    
    while (!postorderStack.empty()) {
        node = postorderStack.top();
        postorderStack.pop();
        
        int leftCoins = 0, rightCoins = 0;
        if (node->left) {
            leftCoins = node->left->val;
            node->left->val = 0; // Reset to 0 after processing
        }
        if (node->right) {
            rightCoins = node->right->val;
            node->right->val = 0; // Reset to 0 after processing
        }
        
        // Update the number of steps (ans)
        ans += std::abs(leftCoins) + std::abs(rightCoins);
        node->val = (node->val - 1) + leftCoins + rightCoins;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    distributeCoins(new TreeNode(3, new TreeNode(0), new TreeNode(0)));
    return 0;
}
