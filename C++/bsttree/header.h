#ifndef BST_H
#define BST_H
#include <iostream>
#include <stdlib.h>

using namespace std;

// Deklarasi Struct
struct Node{
    int data;
    Node *kiri;
    Node *kanan;
};

// Deklarasi Fungsi (Prototypes)
void tambah(Node **root, int databaru);
void preOrder(Node *root);
void inOrder(Node *root);
void postOrder(Node *root);

#endif