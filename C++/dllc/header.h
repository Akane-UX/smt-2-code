#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct TNode *head;

struct TNode{
    int data;
    TNode *next;
    TNode *prev;
};

void insertDepan(head &L, int databaru);
void insertBelakang(head &L, int databaru);
void hapusDepan(head &L);
void hapusBelakang(head &L);
void clear(head &L);
void tampil(head &L);
void cekLinked(head &L);