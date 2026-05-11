#include "header.h"
void Sisip_Depan(simpul &L, char elemen)
{
    simpul baru;
    baru = (simpul)malloc(sizeof(simpul));
    baru->isi = elemen;
    baru->Next = NULL;
    if (L == NULL)
      L = baru;
    else    {
        baru->Next = L;
        L = baru;   
    }
}
void Cetak(simpul L)
{
    simpul bantu;
    if(L == NULL)
        cout << "List Kosong" << endl;
    else    {
        bantu = L;
        while (bantu != NULL)        {
            cout << bantu->isi << " ";
            bantu = bantu->Next;
        }
    }
}
    
void Hapus_Depan(simpul &L)
{
    simpul hapus;
    if(L == NULL)
        cout << "List Kosong" << endl;
    else    
    {
        hapus = L;
        L = L->Next;
        free(hapus);
    }
}
void Hapus_Belakang(simpul &L)
{
    simpul hapus, bantu;
    if(L == NULL)
        cout << "List Kosong" << endl;
    
    else    
    {
        bantu = L;
        while (bantu->Next->Next != NULL)        {
            bantu = bantu->Next;
        }
        hapus = bantu->Next;
        bantu->Next = NULL;
        free(hapus);
    }
}
