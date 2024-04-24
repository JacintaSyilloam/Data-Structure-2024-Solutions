/*

Sorted Wall of Shame
- Easy
- Objective: Sort integers using binary search tree

Solution:
1. Create a node with value (create_node function)
2. Insert node to the tree (insert_node function)
3. Traverse the tree using inorder (inorder_traversal function)
4. Print the values of the nodes (main function)

*/

#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *left, *right;
};

Node *create_node(int nrp);
Node *insert_node(Node *root, int nrp);
void inorder_traversal(Node *root);

int main()
{
    Node *root = NULL;
    int input;

    while (true)
    {
        cin >> input;
        if (input == 0)
        {
            break;
        }

        root = insert_node(root, input);
    }

    cout << "Plagiarism Detected pada NRP:\n";
    inorder_traversal(root);
}

Node *create_node(int nrp)
{
    Node *new_node = new Node;
    new_node->value = nrp;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *insert_node(Node *root, int nrp)
{
    if (root == NULL)
        return create_node(nrp);

    if (nrp < root->value)
        root->left = insert_node(root->left, nrp);
    else if (nrp > root->value)
        root->right = insert_node(root->right, nrp);

    return root;
}

void inorder_traversal(Node *root)
{
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    cout << root->value << " ";
    inorder_traversal(root->right);
}