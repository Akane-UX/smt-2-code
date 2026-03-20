#include "header.h"

using namespace std;

float inputNilaiValid(string namaKomponen) {
    float nilai;
    while (true){
        cout<<"Masukkan nilai "<<namaKomponen<<" (0-100): ";//input nilai
        cin>>nilai;

        if (cin.fail()) {//kalo input bukan angka
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "INPUT HARUS ANGKA!"<<endl;
            continue;
        }

        else if (nilai>=0 && nilai<=100) {
            return nilai;
        } else {//jika input nilai selain dari 1-100
            cout<<"INPUT INVALID! Silakan masukkan ulang"<<endl;
        }
    }
}

float hitungNilaiAkhir(Nilai n) { //hitung nilai hasil
    return (n.Kehadiran*0.1)+(n.Tugas*0.2)+(n.UTS*0.3)+(n.UAS*0.4);
}

char convHuruf(float nilaiAkhir) {//conv nikai ke huruf
    if (nilaiAkhir >= 80 && nilaiAkhir <= 100) return 'A';
    else if (nilaiAkhir >= 70 && nilaiAkhir < 80) return 'B';
    else if (nilaiAkhir >= 50 && nilaiAkhir < 70) return 'C';
    else if (nilaiAkhir >= 40 && nilaiAkhir < 50) return 'D';
    else return 'E';
}

void tampilkanDetail(Mahasiswa mhs) {//hasil akhir perhitungan+data mahasiswa
    float nilaiAkhir = hitungNilaiAkhir(mhs.nilai);
    char hurufMutu = convHuruf(nilaiAkhir);

    cout<<"\n========================================="<<endl;
    cout<<"=         NILAI AKHIR MAHASISWA           ="<<endl;
    cout<<"========================================="<<endl;
    cout<<"NPM      : "<<mhs.NPM<<endl;
    cout<<"Nama     : "<<mhs.Nama<<endl;
    cout<<"Prodi    : "<<mhs.Prodi<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Rincian Nilai:"<<endl;
    cout<<fixed<<setprecision(2); //biar cuma 2 digit
    cout<<"- Nilai Kehadiran : "<<mhs.nilai.Kehadiran<<endl;
    cout<<"- Nilai Tugas     : "<<mhs.nilai.Tugas<<endl;
    cout<<"- Nilai UTS       : "<<mhs.nilai.UTS<<endl;
    cout<<"- Nilai UAS       : "<<mhs.nilai.UAS<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"NILAI AKHIR (Angka) : "<<nilaiAkhir<<endl; //total nilai dalam angka
    cout<<"NILAI AKHIR (Huruf) : "<<hurufMutu<<endl;//nilai yg dikonver ke hurif
    cout<<"=========================================\n"<<endl;
}