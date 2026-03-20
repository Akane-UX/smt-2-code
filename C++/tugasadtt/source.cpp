#include "header.h"
using namespace std;

void inputBarang(struct Barang brg[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Input barang ke-" << (i+1) << endl;
        cout << "Nama: ";
        cin.getline(brg[i].nama, 50);
        cout << "Harga: ";
        cin >> brg[i].harga;
        cout << "Stok: ";
        cin >> brg[i].stok;
        cin.ignore(); 
        cout << endl;
    }
}

void tampilBarang(struct Barang brg[], int n) {
    cout << "Daftar Barang:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Nama: " << brg[i].nama << endl;
        cout << "Harga: " << brg[i].harga << endl;
        cout << "Stok: " << brg[i].stok << endl;
        cout << "----------------" << endl;
    }
}

void cariBarang(struct Barang brg[], int n, char cariNama[]) {
    int ketemu = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp(brg[i].nama, cariNama) == 0) {
            cout << "Ditemukan!" << endl;
            cout << "Harga: " << brg[i].harga << endl;
            cout << "Stok: " << brg[i].stok << endl;
            ketemu = 1;
            break;
        }
    }
    if(ketemu == 0) {
        cout << "Tidak ditemukan!" << endl;
    }
}
