#include "header.h"

int isEmpty(head &L)
{
    if(L==NULL)
        return 1;
    else
        return 0;
}

void insertDepan(head &L, int databaru)
{
    head baru;
    baru = (head) malloc(sizeof(head));
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;
    if(L == NULL)
        L=baru;
    else
    {
        baru->next = L;
        L->prev = baru;
        L=baru;
    }
}

void insertBelakang(head &L, int databaru)
{
    head baru, bantu;
    baru = (head) malloc(sizeof(head));
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;
    if(L == NULL)
        L=baru;
    else
    {
        bantu = L;
        while (bantu->next!=NULL) bantu=bantu->next;
        bantu->next = baru;
        baru->prev = bantu;
    }
}

void tampil(head &L)
{
    head bantu;
    bantu = L;
    if(L !=NULL){
        while(bantu!=NULL){
            cout<<bantu->data<<" - ";
            bantu = bantu->next;
        }
    }else{
        cout<<"Data masih kosong"<<endl;
    }
}

void hapusDepan(head &L)
{
    head hapus;
    int d;

    if(L !=0){
        if(L->next !=NULL){
            hapus = L;
            d = hapus->data;
            L = L->next;
            L->prev = NULL;
            delete hapus;
        }else{
            d= L->data;
            L = NULL;
        }
        cout<<"Data terhapus"<<endl;
    }else{
        cout<<"Data masih kosong";
    }
}

void hapusBelakang(head &L)
{
    head bantu, hapus;
    if(L==NULL)
        cout<<"Linked List Kosong .............";
    else
    {
        bantu = L;
        while(bantu->next->next != NULL)
            bantu=bantu->next;
        hapus = bantu->next;
        bantu->next = NULL;
        hapus->prev = NULL;
        free(hapus);
    }
}

void clear(head &L)
{
    head hapus, bantu;
    bantu = L;

    while(bantu !=NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    L=NULL;
    cout<<"Semua data berhasil dihapus"<<endl;
}