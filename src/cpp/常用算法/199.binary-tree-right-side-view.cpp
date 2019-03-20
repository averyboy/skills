/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (46.56%)
 * Total Accepted:    154.4K
 * Total Submissions: 329.6K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
      	    return ans;
        queue<pair<TreeNode*,int> > qe;
        qe.push(make_pair(root,0));
        pair<TreeNode*,int> p;
        while(!qe.empty())
        {
            p=qe.front();
            qe.pop();
            if((p.first)->left)
                qe.push(make_pair((p.first)->left,p.second+1));
            if((p.first)->right)
                qe.push(make_pair((p.first)->right,p.second+1));
            if(qe.front().second==p.second+1)
                ans.push_back((p.first)->val);
        }
        ans.push_back((p.first)->val);
        return ans;
    }
};

