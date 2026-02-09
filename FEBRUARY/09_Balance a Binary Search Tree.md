##### I N T U I T I O N
    A BST’s inorder traversal gives sorted values; rebuilding the tree by always
    picking the middle element as root keeps left and right subtrees nearly equal in height,
    making the BST balanced.
##### C O D E

```cpp
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
class Solution {
public:
    void inorder(TreeNode* root, vector<int>&arr){
        if(!root) return ;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right,arr); 
    }

    TreeNode* buildBST(vector<int>&arr, int l, int r){
        if(l>r) return nullptr;
        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildBST(arr,l,mid-1);
        root->right= buildBST(arr,mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        return buildBST(arr, 0, arr.size()-1);
    }
};
```
