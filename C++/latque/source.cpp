#include "header.h"
Queue antrian;

void Create(){
    antrian.head=antrian.tail=-1;
}

int IsEmpty(){
    if(antrian.tail==-1)
        return 1;
    else
        return 0;
}

int IsFull(){
    if(antrian.tail==MAX-1)
        return 1;
    else
        return 0;
}

void Enqueue(int data){
    if(IsEmpty()==1){
        antrian.head=antrian.tail=0;
        antrian.data[antrian.tail]=data;
        cout<<antrian.data[antrian.tail]<<" sudah dimasukkan"<<endl;
    } else if(IsFull()==0){
        antrian.tail++;
        antrian.data[antrian.tail]=data;
    }
}

int Dequeue(){
    int i;
    int e = antrian.data[antrian.head];
    cout << "Mengambil data \"" << antrian.data[antrian.head] << "\"..." << endl;
    for(i=antrian.head; i<=antrian.tail-1;i++){
        antrian.data[i]=antrian.data[i+1];
    }
    antrian.tail--;
    return e;
}

void Clear(){
    antrian.head=antrian.tail=-1;
    cout<<"Antrian dikosongkan"<<endl;
}

void Tampil(){
    if(IsEmpty()==0){
        for(int i=antrian.head;i<=antrian.tail;i++){
            cout<<antrian.data[i]<<"-";
        }
    } else cout<<"Data Kosong";
}

void menu(){
    int m;
    int data;
    Queue antrian;
    Create();
    do{
        system("cls");
        cout<<endl<<"=============================="<<endl;
        cout<<" \t  PROGRAM QUEUE        ="<<endl;
        cout<<"=============================="<<endl;
        cout<<"  =  1. ENQUEUE              ="<<endl;
        cout<<"  =  2. DEQUEUE              ="<<endl;
        cout<<"  =  3. TAMPIL               ="<<endl;
        cout<<"  =  4. CLEAR                ="<<endl;
        cout<<"  =  0. EXIT                 ="<<endl;
        cout<<"=============================="<<endl;
        cout<<" Masukan Pilihan : ";cin>>m;
        switch(m){
            case 1:
                cout<<"Masukan Data : ";cin>>data;
                Enqueue(data);
                cout<<"Data "<<data<<" sudah diinputkan.";
                cout<<endl;
                system("pause");
                break;
            case 2:
                Dequeue();
                cout<<endl;
                system("pause");
                break;
            case 3:
                Tampil();
                cout<<endl;
                system("pause");
                break;
            case 4:
                Clear();
                cout<<endl;
                system("pause");
                break;
            default:
                cout << "Pilihan tidak tersedia. Program akan ditutup.";
                break;
        }
    }while(m!=0);
}