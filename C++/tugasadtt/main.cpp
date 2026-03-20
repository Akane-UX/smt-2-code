#include "header.h"
using namespace std;

int main() {
    struct Barang barang[100];
    int pilihan, jumlah;

    cout << "Program Manajemen Stok Barang Sederhana" << endl;
    cout << "========================================" << endl;

    cout << "Masukkan jumlah barang: ";
    cin >> jumlah;
    cin.ignore(); 

    while(true) {
        cout << "\n1. Input Barang" << endl;
        cout << "2. Tampil Barang" << endl;
        cout << "3. Cari Barang" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if(pilihan == 1) {
            inputBarang(barang, jumlah);
        } else if(pilihan == 2) {
            tampilBarang(barang, jumlah);
        } else if(pilihan == 3) {
            char cari[50];
            cout << "Nama yang dicari: ";
            cin.getline(cari, 50);
            cariBarang(barang, jumlah, cari);
        } else if(pilihan == 4) {
            cout << "Keluar program!" << endl;
            break;
        } else {
            cout << "Pilihan salah!" << endl;
        }
    }

    return 0;
}
