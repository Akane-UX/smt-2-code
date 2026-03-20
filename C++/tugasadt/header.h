#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Nilai{
    float UTS;
    float Tugas;
    float Kehadiran;
    float UAS;
};

struct Mahasiswa{
    string NPM;
    string Nama;
    string Prodi;
    Nilai nilai; 
};

float inputNilaiValid(string namaKomponen);//untuk input nilai
float hitungNilaiAkhir(Nilai n);//tempat menyimpan nilai akhir
char convHuruf(float nilaiAkhir);//untuk konversi nilai
void tampilkanDetail(Mahasiswa mhs);//tempat detail keseluruhan disimpan


