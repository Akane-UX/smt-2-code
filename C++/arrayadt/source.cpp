#include "header.h"

void MakeEmpty(TabInt *T)
{
    (*T).Neff=0;
}

int LastIdx(TabInt T)
{
    return (T.Neff);
}

void BacaIsi (TabInt *T)
{
    int i, N;
    cout<<"\nBanyaknya Element yang akan dientry : ";
    cin>>N;
    cout<<endl;
    cout<<"Masukan isi : \n";
    for (i=1 ; i<=N;i++)
    {
        cout<<i<<" - ";
        cin>>((*T).TI[i]);
    }
    (*T).Neff=N;
}

void TulisIsi (TabInt T)
{
    int i;
    cout<<endl;
    if (LastIdx(T)==0)
        cout<<"Tabel Kosong";
    else
    {
        for (i=1;i<=LastIdx(T);i++)
        {
            cout<<(T).TI[i]<< " | ";
        }
    }
    cout<<endl;
}