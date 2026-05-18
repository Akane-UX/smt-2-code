#include "header.h"

void tambah(Node **root, int databaru){
    if(*root == NULL){
        Node *baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *root = baru;
    } else if(databaru < (*root)->data){
        tambah(&(*root)->kiri, databaru);
    } else if(databaru > (*root)->data){
        tambah(&(*root)->kanan, databaru);
    } else if(databaru == (*root)->data){
        cout << "Data sudah ada dalam pohon." << endl;
    }
}
void preOrder(Node *root){
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}
void inOrder(Node *root){
    if(root != NULL){
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}
void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}