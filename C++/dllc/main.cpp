#include "header.h"

int main() {
    int databaru;
    head baru=NULL;

    int choose;
    do
    {
        cout << "--------------------------\n"
             << "  OPERASI PADA DOUBLE LINKED LIST CIRCULAR\n"
             << "--------------------------\n"
             << " [1] Tambah data dari depan \n"
             << " [2] Tambah data dari belakang \n"
             << " [3] Hapus data dari depan \n"
             << " [4] Hapus data dari belakang \n"
             << " [5] Cetak Data\n"
             << " [6] Clear\n"
             << " [7] Cek Next dan Prev dari Simpul Depan\n"
             << " [0] Keluar \n\n"
             << "--------------------------\n"
             << "Masukkan pilihan : "; cin >> choose;
             
        switch (choose)
        {
        case 1:
            cout<<"Penyisipan Simpul Di Depan"<<endl<<endl;
            cout<<"Masukkan angka :"; cin>>databaru;
            insertDepan(baru, databaru);
            cout<<endl;
            tampil(baru);
            cout<<endl;
            break;
        case 2:
            cout<<"Penyisipan Simpul Di Depan"<<endl<<endl;
            cout<<"Masukkan angka :"; cin>>databaru;
            insertBelakang(baru, databaru);
            cout<<endl;
            tampil(baru);
            cout<<endl;
            break;
        case 3:
            hapusDepan(baru);
            tampil(baru);
            cout<<endl;
            break;
        case 4 :
            hapusBelakang(baru);
            tampil(baru);
            cout<<endl;
            break;
        case 5:
            tampil(baru);
            cout<<endl;
            break;
        case 6:
            clear(baru);
            cout<<endl;
            break;
        case 7:
            cekLinked(baru);
            cout<<endl;
            break;
        default:
            cout << "Pilihan tidak tersedia";
            break;
        }
    } while (choose !=0);
    return 0;
}