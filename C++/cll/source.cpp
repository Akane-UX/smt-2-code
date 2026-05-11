#include "header.h"
void Sisip_Depan(simpul &L, char elemen)
{
    simpul baru; 
    baru = (simpul) malloc(sizeof(simpul));
    baru->Isi = elemen;
    baru->Next = NULL;
    if(L == NULL)
        L=baru;
    else
    {
        baru->Next = L;
        L=baru;
    }
}

void Cetak(simpul L)
{
    simpul bantu;
    if(L==NULL)
        cout<<"Linked List Kosong ......"<<endl;
    else
    {
        bantu=L;
        cout<<"Isi Linked List : ";
        while (bantu->Next != NULL)
        {
            cout<<bantu->Isi<<"-->";
            bantu=bantu->Next;
        }
        cout<<bantu->Isi;
    }
}

void Hapus_Depan(simpul &L)
{
    simpul Hapus;
    if(L==NULL)
        cout<<"Linked List Kosong ........";
    else
    {
        Hapus = L;
        L = L->Next;
        Hapus->Next = NULL;
        free(Hapus);
    }
}

void Hapus_Belakang(simpul &L)
{
    simpul bantu, hapus;
    if(L==NULL)
        cout<<"Linked List Kosong ........";
    else
    {
        bantu = L;
        while(bantu->Next->Next != NULL) bantu=bantu->Next;
        hapus = bantu->Next;
        bantu->Next = NULL;
        free(hapus);
    }
}