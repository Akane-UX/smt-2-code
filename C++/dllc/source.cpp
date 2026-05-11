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
    {
        baru->next = baru;
        baru->prev = baru;
        L = baru;
    }
    else
    {
        head last = L->prev;
        baru->next = L;
        baru->prev = last;
        last->next = baru;
        L->prev = baru;
        L = baru;
    }
}

void insertBelakang(head &L, int databaru)
{
    head baru;
    baru = (head) malloc(sizeof(head));
    baru->data = databaru;
    if (L == NULL) {
        baru->next = baru;
        baru->prev = baru;
        L = baru;
    } else {
        TNode *last = L->prev;
        baru->next = L;
        baru->prev = last;
        last->next = baru;
        L->prev = baru;
    }
}

void tampil(head &L)
{
    if (L == NULL) {
        cout << "List kosong\n";
        return;
    }
    TNode *bantu = L;
    cout<<"List saat ini:"<<endl;
    do {
        cout << bantu->data << "-";
        bantu = bantu->next;
    } while (bantu != L);
}

void hapusDepan(head &L)
{
    if (L == NULL) return;
    if (L->next == L) {
        free(L);
        L = NULL;
    } else {
        TNode *hapus = L;
        TNode *last = L->prev;
        L = L->next;
        L->prev = last;
        last->next = L;
        free(hapus);
    }
}

void hapusBelakang(head &L)
{
    if (L == NULL) return;
    if (L->next == L) {
        free(L);
        L = NULL;
    } else {
        TNode *last = L->prev;
        TNode *beforeLast = last->prev;
        beforeLast->next = L;
        L->prev = beforeLast;
        free(last);
    }
}

void clear(head &L)
{
    while (L != NULL)
        hapusDepan(L);
    cout<<"Semua data berhasil dihapus"<<endl;
}

void cekLinked(head &L) {
    if (L == NULL) {
        cout << "List kosong.\n";
        return;
    }

    cout << "Data di simpul depan           : " << L->data << endl;
    cout << "Data prev dari simpul depan: " << L->prev->data << endl;
    cout << "Data next dari simpul depan : " << L->next->data << endl;
}