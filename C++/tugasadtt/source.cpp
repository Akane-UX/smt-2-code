#include "header.h" 
using namespace std; 

void inputBarang(struct Barang brg[], int n) { 
    for(int i = 0; i < n; i++) { 
        cout << "Input barang ke-" << (i+1) << endl; 
        cout << "Masukan nama : "; 
        cin.getline(brg[i].nama, 50); 
        cout << "Kode : "; 
        cin.getline(brg[i].kode, 20); 
        cout << "Masukan unit : "; 
        cin >> brg[i].stok; 
        cout << "Masukan harga: "; 
        cin >> brg[i].harga; 
        cin.ignore();  
        cout << endl; 
    } 
} 

void tampilBarang(struct Barang brg[], int n) { 
    cout << left
        << setw(8)  << "Kode"
        << setw(8)  << "Unit"
        << setw(20) << "Nama"
        << setw(15) << "Harga"
        << endl;
    cout << string(51, '-') << endl;
    for(int i = 0; i < n; i++) { 
        cout << left
            << setw(8)  << brg[i].kode
            << setw(8)  << brg[i].stok
            << setw(20) << brg[i].nama
            << fixed << setprecision(2) << brg[i].harga
            << endl;
    } 
} 