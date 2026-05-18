#include "header.h"

AVLNode *creatNode( int data) {
    AVLNode *node = new AVLNode();
    node->data = data;
    node->height = 1; // New node is initially added at leaf position
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int getHeight(AVLNode *node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalanceFactor(AVLNode *node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    // Return new root
    return x;
}

AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    // Return new root
    return y;
}

AVLNode* insert(AVLNode* node, int data) {
    // Perform the normal BST insert
    if (node == nullptr)
        return creatNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Equal keys are not allowed in BST
        return node;

    // Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalanceFactor(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

void printPreOrder(AVLNode *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}