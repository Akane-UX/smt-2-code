#include <iostream>
#include <iomanip>
#include <cstring>

struct Barang {
    char kode[20];
    char nama[50];
    int stok;
    double harga;
};

void inputBarang(struct Barang brg[], int n);
void tampilBarang(struct Barang brg[], int n);
void cariBarang(struct Barang brg[], int n, char cariNama[]);