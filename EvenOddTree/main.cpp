//
//  main.cpp
//  EvenOddTree
//
//  Created by Jaime Cuartas Granada on 29/2/2024.
//

#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool isEvenOddTree(TreeNode* root) {
    if(root == nullptr) return 0;
    std::vector<TreeNode*> preRow;
    std::vector<TreeNode*> lastRow;
    lastRow.push_back(root);
    //if it is odd , the value is 1, otherwise (even) it is 0
    int odd = 1;
    int nPreRow;
    int currentValue = 0;
    int previousValue = 0;
    do{
        preRow.clear();
        preRow = lastRow;
        lastRow.clear();
        nPreRow = static_cast<int>(preRow.size());
        for(int i=0; i<nPreRow; i++){
            currentValue = preRow[i]->val;
            
            if(currentValue%2 != odd) return false;
            if(odd==1){
                if(previousValue >= currentValue) return false;
            } else{
                if(previousValue <= currentValue) return false;
            }
            TreeNode * left = preRow[i]->left;
            if(left !=nullptr) lastRow.push_back(left);
            TreeNode * right = preRow[i]->right;
            if(right !=nullptr) lastRow.push_back(right);
            previousValue = currentValue;
        }
        odd = (odd==1)? 0: 1;
        previousValue = (odd==0)? INT_MAX : 0;
    }while(!lastRow.empty());
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << isEvenOddTree(
                               new TreeNode(1, 
                                            new TreeNode(10,
                                                         new TreeNode(3, new TreeNode(12), new TreeNode(8)),
                                                         nullptr),
                                            new TreeNode(4,
                                                         new TreeNode(7, new TreeNode(6), nullptr),
                                                         new TreeNode(9, nullptr, new TreeNode(2)))));
    return 0;
}
