#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node *simpul;
struct node
{
    char Isi;
    simpul Next;
};
void Sisip_Depan(simpul &L, char elemen);
void Hapus_Depan(simpul &L);
void Hapus_Belakang(simpul &L);
void Cetak(simpul L);