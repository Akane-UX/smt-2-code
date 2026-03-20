#include "header.h"

using namespace std;

int main(){
    Mahasiswa mhsBaru;
    int pilihan;

    do{//menu
        cout<<"\n--- MENU PROGRAM PENILAIAN ---"<<endl;
        cout<<"1. Input Data Mahasiswa & Nilai"<<endl;
        cout<<"2. Tampilkan Hasil Penilaian"<<endl;
        cout<<"0. Keluar" << endl;
        cout<<"Pilih menu (0-2): ";
        cin>>pilihan;//input pilihan

        switch(pilihan){
            case 1://input data
                cout<<"\n[INPUT DATA]"<<endl;//Data mahasiswa
                cin.ignore(); 
                cout<<"Masukkan NPM    : "; getline(cin, mhsBaru.NPM);
                cout<<"Masukkan Nama   : "; getline(cin, mhsBaru.Nama);
                cout<<"Masukkan Prodi  : "; getline(cin, mhsBaru.Prodi);

                cout<<"\n[INPUT NILAI]"<<endl;//Nilai
                mhsBaru.nilai.Kehadiran = inputNilaiValid("Kehadiran");
                mhsBaru.nilai.Tugas     = inputNilaiValid("Tugas");
                mhsBaru.nilai.UTS       = inputNilaiValid("UTS");
                mhsBaru.nilai.UAS       = inputNilaiValid("UAS");
                
                cout<<"\nData berhasil disimpan!"<<endl;//sukses disimpan
                break;

            case 2://menampilkan hasil
                if (mhsBaru.Nama.empty()) {//jika belum ad data yg diinput
                    cout<<"\nBelum ada data mahasiswa yang diinput. Silakan input data terlebih dahulu "<<endl;
                } else {
                    tampilkanDetail(mhsBaru);
                }
                break;

            case 0: //close program
                cout<<"Program selesai, Thanks for using this program ;]."<<endl;
                break;

            default:
                cout<<"Pilihan tidak valid!"<<endl;
        }

    }while(pilihan!=0);//jika input selain dari pilihan

    return 0;
}
