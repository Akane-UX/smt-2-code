#include "header.h" 
using namespace std; 

int main() { 
    struct Barang barang[100]; 
    int pilihan, jumlah = 0; 


    while(true) { 
        cout << "\n== Aplikasi Manajemen Stok Barang ==" << endl;
        cout << "1. Input Barang" << endl; 
        cout << "2. Tampil Barang" << endl;  
        cout << "0. Keluar" << endl; 
        cout << "masukan pilihan : "; 
        cin >> pilihan; 
        cin.ignore(); 

        if(pilihan == 1) { 
            cout << "Masukkan jumlah barang: "; 
            cin >> jumlah; 
            if (jumlah <=0){
                cout << "input tidak valid!" ;
            }
            else if( jumlah!=0-99999){
                cout << "input bilangan tidak valid!";
            }
            cin.ignore(); 
            inputBarang(barang, jumlah); 
        } else if(pilihan == 2) { 
            tampilBarang(barang, jumlah); 
        } else if(pilihan == 0) { 
            cout << "Keluar program!" << endl; 
            break; 
        } else { 
            cout << "Pilihan salah!" << endl; 
        } 
    } 

    return 0; 
}