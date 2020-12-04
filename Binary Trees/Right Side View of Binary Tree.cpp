// Problem statemnt Link - https://leetcode.com/problems/binary-tree-right-side-view/submissions/; https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // Time: O(nlogn); Space: O(n)
 
class Solution {
public:
    
    vector<int> res;
    void rightView(TreeNode* root, int level, int *max_level){ 
            if (root==NULL) 
            {
                return; 
            }
        
            if (*max_level < level) 
            { 
                res.push_back(root->val);
                *max_level = level; 
            } 
 
            rightView(root->right, level+1, max_level); // visit right subtree before left subtree
            rightView(root->left, level+1, max_level); 
       }
    
    vector<int> rightSideView(TreeNode* root) {
     
        int max_level = 0; 
        rightView(root, 1, &max_level); 
        return res;
    }
};


