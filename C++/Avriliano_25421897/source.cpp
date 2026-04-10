#include "header.h"

CircularQueue Q;

void Create(){
    Q.head = -1;
    Q.tail = -1;
}

int isEmpty(){
    if(Q.head == -1 && Q.tail == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    if((Q.tail + 1) % MAX == Q.head)
        return 1;
    else
        return 0;
}

void Enqueue(int data){
    if(isFull() == 1){
        cout << "Queue penuh, data " << data << " gagal disimpan" << endl;
    } else if(isEmpty() == 1){
        Q.head = 0;
        Q.tail = 0;
        Q.data[Q.tail] = data;
        cout << Q.data[Q.tail] << " berhasil disimpan" << endl;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
        Q.data[Q.tail] = data;
        cout << Q.data[Q.tail] << " berhasil disimpan" << endl;
    }
}

int Dequeue(){
    int e;
    if(isEmpty() == 1){
        cout << "Queue kosong, tidak ada data yang diambil" << endl;
        return -1;
    }
    e = Q.data[Q.head];
    cout << "Data diambil: " << Q.data[Q.head] << endl;
    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }
    return e;
}

void clear(){
    Q.head = -1;
    Q.tail = -1;
    cout << "Antrian berhasil dibubarkan" << endl;
}

void Tampil(){
    if(isEmpty() == 1){
        cout << "Data kosong" << endl;
    } else {
        int i = Q.head;
        cout << "Isi antrian: ";
        while(true){
            cout << Q.data[i] << " - ";
            if(i == Q.tail) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

void TampilFrontRear(){
    cout << "Front = " << Q.head << endl;
    cout << "Rear  = " << Q.tail << endl;
    if(isEmpty() == 0){
        cout << "Nilai Front = " << Q.data[Q.head] << " di indeks ke-" << Q.head << endl;
        cout << "Nilai Rear  = " << Q.data[Q.tail] << " di indeks ke-" << Q.tail << endl;
    }
}

void menu(){
    int choose, data;
    Create();
    do{
        system("CLS");
        cout<<"Program Circular Queue"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Tampil Semua Antrian"<<endl;
        cout<<"4. Tampil Head dan Tail"<<endl;
        cout<<"5. Clear"<<endl;
        cout<<"0. Keluar"<<endl;
        cout<<"Masukkan pilihan Anda: ";
        cin>>choose;
        switch(choose){
            case 1:
                cout<<"Masukkan data: ";cin>>data;
                Enqueue(data);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Tampil();
                break;
            case 4:
                TampilFrontRear();
                break;
            case 5:
                clear();
                break;
            case 0:
                cout<<"Sayonara...."<<endl;
                break;
            default:
                cout<<"Pilihan tidak tersedia";
                break;
        }
        if(choose!=0){
            cout<<"\n";
            system("pause");
        }
    }while(choose!=0);
}