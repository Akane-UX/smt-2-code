#include "header.h"

int main() {
    char huruf, huruf2;
    simpul L = NULL;
    int choose;
    do
    {
        cout << "-----------------------\n"
             << "   OPERASI PADA SINGLE LINKED LIST\n"
             << "-----------------------\n"
             << " [1] Sisip Simpul Depan \n"
             << " [2] Cetak Data\n"
             << " [3] Hapus Simpul Depan\n"
             << " [4] Hapus Simpul Belakang \n\n"
             << " [0] Keluar \n\n"
             << "-----------------------\n"
             << "Masukkan pilihan : "; cin >> choose;
        switch (choose)
        {
            case 1:
                cout<<"Penyisipan Simpul Di Depan"<<endl<<endl;
                cout<<"Masukkan Huruf :"; cin>>huruf;
                Sisip_Depan(L, huruf);
                cout<<"Masukkan Huruf :"; cin>>huruf;
                Sisip_Depan(L, huruf);
                cout<<"Masukkan Huruf :"; cin>>huruf;
                Sisip_Depan(L, huruf);
                cout<<"Masukkan Huruf :"; cin>>huruf;
                Sisip_Depan(L, huruf);
                cout<<"Masukkan Huruf :"; cin>>huruf;
                Sisip_Depan(L, huruf);
                break;
            case 2:
                Cetak(L);
                break;
            case 3:
                cout<<endl<<endl<<"Setelah Hapus Simpul Depan ";
                Hapus_Depan(L);
                Cetak(L);
                break;
            case 4 :
                cout<<endl<<endl<<"Setelah Hapus Simpul Belakang "<<endl;
                Hapus_Belakang(L);
                Cetak(L);
                break;
            default:
                cout << "Pilihan tidak tersedia";
                break;
        }
    } while (choose !=0);

    return 0;
}