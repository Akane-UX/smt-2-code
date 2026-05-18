#include "header.h"

// Fungsi untuk menambahkan node baru
void tambah(Node **root, int databaru)
{
    // Jika root masih kosong
    if((*root) == NULL)
    {
        // Pembuatan node baru
        Node *baru;
        // Pengalokasian memori dari node yang telah dibuat
        baru = new Node;
        // Inisialisasi awal node yang baru dibuat
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
        cout<<"Data bertambah!";
    }
    // Jika data yang akan dimasukkan lebih kecil daripada elemen root, diletakkan di node sebelah kiri.
    else if(databaru < (*root)->data)
        tambah(&(*root)->kiri, databaru);
    // Jika data yang akan dimasukkan lebih besar daripada elemen root, diletakkan di node sebelah kanan
    else if(databaru > (*root)->data)
        tambah(&(*root)->kanan, databaru);
    // Jika saat dicek data yang akan dimasukkan memiliki nilai yang sama dengan data pada root
    else if(databaru == (*root)->data)
        cout<<"Data sudah ada!";
}

// Fungsi yang digunakan untuk mencetak tree secara preOrder
void preOrder(Node *root)
{
    if(root != NULL){
        cout<<root->data<<" ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

// Fungsi yang digunakan untuk mencetak tree secara inOrder
void inOrder(Node *root)
{
    if(root != NULL){
        inOrder(root->kiri);
        cout<<root->data<<" ";
        inOrder(root->kanan);
    }
}

// Fungsi yang digunakan untuk mencetak tree secara postOrder
void postOrder(Node *root)
{
    if(root != NULL){
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout<<root->data<<" ";
    }
}