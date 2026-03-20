#include <iostream>
#include <string.h>

struct Barang {
    char nama[50];
    int harga;
    int stok;
};

void inputBarang(struct Barang brg[], int n);
void tampilBarang(struct Barang brg[], int n);
void cariBarang(struct Barang brg[], int n, char cariNama[]);