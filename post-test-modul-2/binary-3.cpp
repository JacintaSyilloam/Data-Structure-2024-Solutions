/*

Binary 3
- Easy
- Objective: Find the height of a binary tree

*/

#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *left, *right;
};

Node *insert_node(Node *root, int data);
int tree_height(Node *root);

int main()
{
    Node *root = NULL;
    int n;

    cin >> n;
    while (n--)
    {
        int data;
        cin >> data;
        root = insert_node(root, data);
    }

    cout << tree_height(root) << endl;
}

Node *create_node(int nrp)
{
    Node *new_node = new Node;
    new_node->value = nrp;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *insert_node(Node *root, int data)
{
    if (root == NULL)
        return create_node(data);

    if (data < root->value)
        root->left = insert_node(root->left, data);
    else if (data > root->value)
        root->right = insert_node(root->right, data);

    return root;
}

int tree_height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);

        if (left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}