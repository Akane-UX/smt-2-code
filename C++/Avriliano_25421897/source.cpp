#include "header.h"

CircularQueue Genap, Ganjil;

void Create(){
    Genap.head = Genap.tail = -1;
    Ganjil.head = Ganjil.tail = -1;
}

int isEmpty(CircularQueue Q){ return (Q.head==-1 && Q.tail==-1) ? 1 : 0; }
int isFull(CircularQueue Q){ return ((Q.tail+1)%MAX == Q.head) ? 1 : 0; }

void Enqueue(int data){
    if(data % 2 == 0){
        if(isFull(Genap)){ cout<<"Queue Genap penuh!"<<endl; return; }
        if(isEmpty(Genap)) Genap.head = Genap.tail = 0;
        else Genap.tail = (Genap.tail+1)%MAX;
        Genap.data[Genap.tail] = data;
        cout<<"Data ditambahkan ke Antrian Genap"<<endl;
        cout<<"QUEUE : "<<data<<endl;
    } else {
        if(isFull(Ganjil)){ cout<<"Queue Ganjil penuh!"<<endl; return; }
        if(isEmpty(Ganjil)) Ganjil.head = Ganjil.tail = 0;
        else Ganjil.tail = (Ganjil.tail+1)%MAX;
        Ganjil.data[Ganjil.tail] = data;
        cout<<"Data ditambahkan ke Antrian Ganjil"<<endl;
        cout<<"QUEUE Ganjil: "<<data<<endl;
    }
}

void DequeueGenap(){
    if(isEmpty(Genap)){ cout<<"Antrian Genap kosong!"<<endl; return; }
    cout<<"Data diambil: "<<Genap.data[Genap.head]<<endl;
    if(Genap.head==Genap.tail) Genap.head=Genap.tail=-1;
    else Genap.head=(Genap.head+1)%MAX;
}

void DequeueGanjil(){
    if(isEmpty(Ganjil)){ cout<<"Antrian Ganjil kosong!"<<endl; return; }
    cout<<"Data diambil: "<<Ganjil.data[Ganjil.head]<<endl;
    if(Ganjil.head==Ganjil.tail) Ganjil.head=Ganjil.tail=-1;
    else Ganjil.head=(Ganjil.head+1)%MAX;
}

void TampilGenap(){
    if(isEmpty(Genap)){ cout<<"Antrian Genap kosong!"<<endl; return; }
    int i=Genap.head;
    cout<<"Antrian Genap: ";
    while(true){
        cout<<Genap.data[i]<<" - ";
        if(i==Genap.tail) break;
        i=(i+1)%MAX;
    }
    cout<<endl;
}

void TampilGanjil(){
    if(isEmpty(Ganjil)){ cout<<"Antrian Ganjil kosong!"<<endl; return; }
    int i=Ganjil.head;
    cout<<"Antrian Ganjil: ";
    while(true){
        cout<<Ganjil.data[i]<<" - ";
        if(i==Ganjil.tail) break;
        i=(i+1)%MAX;
    }
    cout<<endl;
}

void BubarkanGenap(){ Genap.head=Genap.tail=-1; cout<<"Antrian Genap dibubarkan"<<endl; }
void BubarkanGanjil(){ Ganjil.head=Ganjil.tail=-1; cout<<"Antrian Ganjil dibubarkan"<<endl; }

void TampilPertama(){
    if(!isEmpty(Genap)) cout<<"Elemen paling pertama di Antrian Genap : "<<Genap.data[Genap.head]<<endl;
    else cout<<"Antrian Genap kosong!"<<endl;
    if(!isEmpty(Ganjil)) cout<<"Elemen paling pertama di Antrian Ganjil : "<<Ganjil.data[Ganjil.head]<<endl;
    else cout<<"Antrian Ganjil kosong!"<<endl;
}

void TampilTerbesar(){
    if(!isEmpty(Genap)){
        int max=Genap.data[Genap.head], i=Genap.head;
        while(true){
            if(Genap.data[i]>max) max=Genap.data[i];
            if(i==Genap.tail) break;
            i=(i+1)%MAX;
        }
        cout<<"Nilai terbesar di Antrian Genap: "<<max<<endl;
    } else cout<<"Antrian Genap kosong!"<<endl;

    if(!isEmpty(Ganjil)){
        int max=Ganjil.data[Ganjil.head], i=Ganjil.head;
        while(true){
            if(Ganjil.data[i]>max) max=Ganjil.data[i];
            if(i==Ganjil.tail) break;
            i=(i+1)%MAX;
        }
        cout<<"Nilai terbesar di Antrian Ganjil: "<<max<<endl;
    } else cout<<"Antrian Ganjil kosong!"<<endl;
}

void menu(){
    int choose, data;
    Create();
    do{
        system("CLS");
        cout<<"--------------------"<<endl;
        cout<<"   Menu Pilihan"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"[1] ENQUEUE"<<endl;
        cout<<"[2] DEQUEUE ANTRIAN GENAP"<<endl;
        cout<<"[3] DEQUEUE ANTRIAN GANJIL"<<endl;
        cout<<"[4] TAMPIL ANTRIAN GENAP"<<endl;
        cout<<"[5] BUBARKAN ANTRIAN GENAP"<<endl;
        cout<<"[6] TAMPIL ANTRIAN GANJIL"<<endl;
        cout<<"[7] BUBARKAN ANTRIAN GANJIL"<<endl;
        cout<<"[8] TAMPILKAN ELEMEN PERTAMA ANTRIAN GANJIL DAN GENAP"<<endl;
        cout<<"[9] TAMPILKAN NILAI TERBESAR DI TIAP ANTRIAN"<<endl;
        cout<<"[0] Keluar"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Masukkan pilihan : ";
        cin>>choose;
        switch(choose){
            case 1:
                cout<<"Masukkan sebuah elemen baru (angka): ";
                cin>>data;
                Enqueue(data);
                break;
            case 2: DequeueGenap(); break;
            case 3: DequeueGanjil(); break;
            case 4: TampilGenap(); break;
            case 5: BubarkanGenap(); break;
            case 6: TampilGanjil(); break;
            case 7: BubarkanGanjil(); break;
            case 8: TampilPertama(); break;
            case 9: TampilTerbesar(); break;
            case 0: cout<<"Keluar..."<<endl; break;
            default: cout<<"Pilihan tidak tersedia"<<endl;
        }
        if(choose!=0){ cout<<"\n"; system("pause"); }
    }while(choose!=0);
}