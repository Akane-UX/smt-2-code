#include "header.h"

int main() {
    Pegawai p;
    int pilihan;

    do
    {
        cout<<"\n===== MENU KELOLA DATA PEGAWAI =====\n";
        cout<<"1. Input Data Pegawai\n";
        cout<<"2. Tampil Data Pegawai\n";
        cout<<"0. Keluar Aplikasi\n";
        cout<<"Tentukan pilihan Anda dari sekarang --> ";
        cin>>pilihan;
        cin.ignore();

        switch(pilihan)
        {
            case 1:
                inputPegawai(p);
                break;

            case 2:
                tampilPegawai(p);
                break;

            case 0:
                cout<<"Terima kasih atas kunjungan Anda. Sayonara XOXO ^_^\n";
                break;

            default:
                cout<<"Pilihan Anda tidak ada di menu\n";
        }

    }while(pilihan!=0);

    return 0;
}