# include <iostream>
# include <cstdlib>
# include <cmath>
using namespace std;

struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
};

AVLNode *creatNode( int data);
int getHeight(AVLNode *node);
int getBalanceFactor(AVLNode *node);
AVLNode* rightRotate(AVLNode *y);
AVLNode* leftRotate(AVLNode *x);
AVLNode* insert(AVLNode* node, int data);
void printPreOrder(AVLNode *root);
