#include <iostream>
#include <iomanip>
#include "header.h"

using namespace std;

float inputNilaiValid(string namaKomponen) {
    float nilai;
    while (true) {
        cout << "Masukkan nilai " << namaKomponen << " (0-100): ";
        cin >> nilai;

        if (nilai >= 0 && nilai <= 100) {
            return nilai;
        } else {
            cout << ">> PERINGATAN: Nilai di luar jangkauan! Silakan masukkan ulang." << endl;
        }
    }
}

float hitungNilaiAkhir(Nilai n) {
    return (n.Kehadiran * 0.1) + (n.Tugas * 0.2) + (n.UTS * 0.3) + (n.UAS * 0.4);
}

char konversiHuruf(float nilaiAkhir) {
    if (nilaiAkhir >= 80 && nilaiAkhir <= 100) return 'A';
    else if (nilaiAkhir >= 70 && nilaiAkhir < 80) return 'B';
    else if (nilaiAkhir >= 50 && nilaiAkhir < 70) return 'C';
    else if (nilaiAkhir >= 40 && nilaiAkhir < 50) return 'D';
    else return 'E'; // < 40
}

void tampilkanDetail(Mahasiswa mhs) {
    float nilaiAkhir = hitungNilaiAkhir(mhs.nilai);
    char hurufMutu = konversiHuruf(nilaiAkhir);

    cout << "\n=========================================" << endl;
    cout << "         HASIL NILAI MAHASISWA           " << endl;
    cout << "=========================================" << endl;
    cout << "NPM      : " << mhs.NPM << endl;
    cout << "Nama     : " << mhs.Nama << endl;
    cout << "Prodi    : " << mhs.Prodi << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Rincian Nilai:" << endl;
    cout << fixed << setprecision(2); // Format angka 2 desimal
    cout << "- Nilai Kehadiran : " << mhs.nilai.Kehadiran << endl;
    cout << "- Nilai Tugas     : " << mhs.nilai.Tugas << endl;
    cout << "- Nilai UTS       : " << mhs.nilai.UTS << endl;
    cout << "- Nilai UAS       : " << mhs.nilai.UAS << endl;
    cout << "-----------------------------------------" << endl;
    cout << "NILAI AKHIR (Angka) : " << nilaiAkhir << endl;
    cout << "NILAI AKHIR (Huruf) : " << hurufMutu << endl;
    cout << "=========================================\n" << endl;
}