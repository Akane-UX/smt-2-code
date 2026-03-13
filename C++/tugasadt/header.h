#ifndef HEADER_H
#define HEADER_H

#include <string>
using namespace std;

struct Nilai {
    float UTS;
    float Tugas;
    float Kehadiran;
    float UAS;
};

struct Mahasiswa {
    string NPM;
    string Nama;
    string Prodi;
    Nilai nilai; 
};

float inputNilaiValid(string namaKomponen);

float hitungNilaiAkhir(Nilai n);

char konversiHuruf(float nilaiAkhir);

void tampilkanDetail(Mahasiswa mhs);

#endif