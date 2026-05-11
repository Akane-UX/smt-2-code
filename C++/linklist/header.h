#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
typedef struct Node *simpul;
struct Node
{
    char isi;
    simpul Next;
};
void Sisip_Depan(simpul &L, char elemen);
void Hapus_Depan(simpul &L);
void Hapus_Belakang(simpul &L);
void Cetak(simpul L);
