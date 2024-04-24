#include <iostream>

// Definisikan node binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// insert node ke BST
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }

    return root;
}

// construct BST
TreeNode* constructBST(int* arr, int n) {
    TreeNode* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = insertNode(root, arr[i]);
    }
    return root;
}

// search node
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) {
        return root;
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

// Print tree pakai Inorder Traversal
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

int main() {
    int n;
    std::cin >> n;

    int* values = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    TreeNode* root = constructBST(values, n);

    int valueToSearch;
    std::cin >> valueToSearch;

    // Search for the node with the given value
    TreeNode* result = searchBST(root, valueToSearch);

    if (result != nullptr) {
        // Print the subtree rooted with the found node
        printTree(result);
        std::cout << std::endl;
    } else {
        std::cout << "womp-womp" << std::endl;
    }

    delete[] values;
    delete root;

    return 0;
}
