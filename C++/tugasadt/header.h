#ifndef HEADER_H
#define HEADER_H

#include <string>
using namespace std;

// --- Definisi ADT (Abstract Data Type) ---

// ADT Nilai
struct Nilai {
    float UTS;
    float Tugas;
    float Kehadiran;
    float UAS;
};

// ADT Mahasiswa
struct Mahasiswa {
    string NPM;
    string Nama;
    string Prodi;
    Nilai nilai; // Komposisi ADT Nilai di dalam Mahasiswa
};

// --- Deklarasi Fungsi ---

// Fungsi untuk menginput nilai dengan validasi (harus antara 0-100)
float inputNilaiValid(string namaKomponen);

// Fungsi untuk menghitung nilai akhir berdasarkan rumus
float hitungNilaiAkhir(Nilai n);

// Fungsi untuk mengkonversi nilai angka ke huruf
char konversiHuruf(float nilaiAkhir);

// Fungsi untuk menampilkan detail mahasiswa
void tampilkanDetail(Mahasiswa mhs);

#endif