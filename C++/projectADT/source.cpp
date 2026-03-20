#include "header.h"

void inputAlamat(Alamat &a)
{
    cout<<"Masukkan Alamat Pegawai"<<endl;
    cout<<"Masukkan jalan: ";
    getline(cin, a.jalan);

    cout<<"Masukkan nomor rumah: ";
    getline(cin, a.nomor_rumah);

    cout<<"Masukkan kota: ";
    getline(cin, a.kota);
}

void tampilAlamat(Alamat &a)
{
    cout<<"Alamat Pegawai:"<<endl;
    cout<<"Jalan: "<<a.jalan<<endl;
    cout<<"Nomor Rumah: "<<a.nomor_rumah<<endl;
    cout<<"Kota: "<<a.kota<<endl;
}

void inputPegawai(Pegawai &p)
{
    cout<<"Input Data Pegawai\n";
    cout<<"NIP: ";
    getline(cin, p.nip);

    cout<<"Nama: ";
    getline(cin, p.nama);

    cout<<"Instansi: ";
    getline(cin, p.instansi);

    cout<<"Alamat";
    inputAlamat(p.alamat);
}

void tampilPegawai(Pegawai &p)
{
    cout<<"Data Pegawai\n";
    cout<<"NIP: "<<p.nip<<endl;
    cout<<"Nama: "<<p.nama<<endl;
    cout<<"Instansi: "<<p.instansi<<endl;
    tampilAlamat(p.alamat);
}