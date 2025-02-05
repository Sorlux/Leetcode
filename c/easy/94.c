/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// At every node, these are the steps to follow:

// First: Travese down the left node until there no longer one left
// Second: Add the current node to the allocated array
// Third: Traverse down the right node
// Once at the right node, you repeat the three steps, which gives us the 3 things to do in the rescurive problem

void rec(struct TreeNode* root, int *arr, int* returnSize) {
    
    // Base case

    if (root == NULL) {
        return;
    }

    rec(root->left, arr, returnSize); // Traverse the left node

    arr[*returnSize] = root->val; // Adding the current node's value to the array to be returned
    (*returnSize)++; //Incrementing the number of items in the array

    rec(root->right, arr, returnSize); // Traversing the right node
    // After this node, the current node is finished and therefore will return the higher up node
}



int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int *arr = (int*) malloc(sizeof(int) * 100); // Max number of nodes is 100, so allocating array of 100 integers for now
    *returnSize = 0; // Accessing value at returnSize and resetting to 0

    if (root != NULL) { // If root is null, then just return the empty array
        rec(root, arr, returnSize);
    }

    arr = realloc(arr, sizeof(int) *  (*returnSize));

    return arr;
}
