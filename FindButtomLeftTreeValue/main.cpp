//
//  main.cpp
//  FindButtomLeftTreeValue
//
//  Created by Jaime Cuartas Granada on 28/2/2024.
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
    return (a>b)? a: b;
}
int findBottomLeftValue(TreeNode* root) {
    if(root == nullptr) return 0;
    std::vector<TreeNode*> preRow;
    std::vector<TreeNode*> lastRow;
    lastRow.push_back(root);
    do{
        preRow.clear();
        preRow = lastRow;
        lastRow.clear();
        int nPreRow = static_cast<int>(preRow.size());
        for(int i=0; i<nPreRow; i++){
            TreeNode * left = preRow[i]->left;
            if(left !=nullptr) lastRow.push_back(left);
            TreeNode * right = preRow[i]->right;
            if(right !=nullptr) lastRow.push_back(right);
        }
    }while(!lastRow.empty());
    return preRow.front()->val;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << findBottomLeftValue(new TreeNode(0)) ;
    std::cout << findBottomLeftValue(new TreeNode(2, new TreeNode(1), new TreeNode(3, new TreeNode(5, new TreeNode(7), nullptr), new TreeNode(6)))) ;
    return 0;
}
