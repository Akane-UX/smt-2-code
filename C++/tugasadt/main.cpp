#include <iostream>
#include "header.h"

using namespace std;

int main() {
    Mahasiswa mhsBaru;
    int pilihan;

    do {
        cout << "\n--- MENU PROGRAM PENILAIAN ---" << endl;
        cout << "1. Input Data Mahasiswa & Nilai" << endl;
        cout << "2. Tampilkan Hasil Penilaian" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu (0-2): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                // Input Data Diri
                cout << "\n[INPUT DATA]" << endl;
                cin.ignore(); // Membersihkan buffer newline
                cout << "Masukkan NPM    : "; getline(cin, mhsBaru.NPM);
                cout << "Masukkan Nama   : "; getline(cin, mhsBaru.Nama);
                cout << "Masukkan Prodi  : "; getline(cin, mhsBaru.Prodi);

                // Input Nilai dengan Validasi
                cout << "\n[INPUT NILAI]" << endl;
                mhsBaru.nilai.Kehadiran = inputNilaiValid("Kehadiran");
                mhsBaru.nilai.Tugas     = inputNilaiValid("Tugas");
                mhsBaru.nilai.UTS       = inputNilaiValid("UTS");
                mhsBaru.nilai.UAS       = inputNilaiValid("UAS");
                
                cout << "\nData berhasil disimpan!" << endl;
                break;

            case 2:
                // Cek apakah data sudah diisi
                if (mhsBaru.Nama.empty()) {
                    cout << "\nBelum ada data mahasiswa yang diinput. Silakan pilih menu 1." << endl;
                } else {
                    tampilkanDetail(mhsBaru);
                }
                break;

            case 0:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}