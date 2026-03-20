#include <iostream>
#include <string>

using namespace std;

typedef struct{
    string jalan;
    string nomor_rumah;
    string kota;
} Alamat;

typedef struct{
    string nip;
    string nama;
    string instansi;
    Alamat alamat;
} Pegawai;

void inputAlamat(Alamat &a);
void tampilAlamat(Alamat &a);
void inputPegawai(Pegawai &p);
void tampilPegawai(Pegawai &p);