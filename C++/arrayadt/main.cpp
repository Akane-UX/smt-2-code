#include "header.h"

int main(){
    TabInt T;
    int pil;

    MakeEmpty(&T);
    do{
        system("cls");
        cout<<"=======Menu=======\n";
        cout<<"1. Make Empty\n";
        cout<<"2. Input elmt tabel\n";
        cout<<"3. Lihat Tabel\n";
        cout<<"4. Keluar\n";
        cout<<"\nMasukan Pilihan Menu : ";
        cin>>pil;
        switch(pil)
        {
            case 1:
                MakeEmpty(&T);
                cout<<"Tabel Sudah Dikosongkan";
                break;
            case 2:
                BacaIsi(&T);
                break;
            case 3:
                cout<<"\nIsi Tabel : ";
                TulisIsi(T);
                getch();
                break;
        }
    }while (pil !=4);

    return 0;
}