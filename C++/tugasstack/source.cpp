#include "header.h"

Stack stack;
Stack stackGenap;

// ===================== STACK UTAMA =====================

void init()
{
    stack.top=-1;
    cout<<"Tumpukan sudah siap diisi";
}

bool IsFull()
{
    if(stack.top==MAX)
        return true;
    else
        return false;
}

bool IsEmpty()
{
    if(stack.top==-1)
        return true;
    else
        return false;
}

void Push(int data)
{
    if(IsFull()==true)
    {
        cout<<"Tumpukan sudah penuh";
    }else{
        stack.top++;
        stack.data[stack.top]=data;
    }
}

int pop()
{
    if(IsEmpty() == true)
    {
        cout << "Data Telah Kosong" << endl;
        return -1;
    }
    else
    {
        int dataTerambil = stack.data[stack.top];
        stack.top--;
        return dataTerambil;
    }
}

void print()
{
    int i;
    if(IsEmpty()==true)
    {
        cout<<"Tumpukan kosong";
    }else{
        for(i=0;i<=stack.top;i++)
        {
            cout<<stack.data[i]<<", ";
        }
    }
}

void clear()
{
    stack.top=-1;
    cout<<"Tumpukan sudah kosong";
}

// ===================== TAMBAHAN 1: REVERSE STACK =====================

void reverseStack()
{
    if(IsEmpty())
    {
        cout << "Stack kosong, tidak bisa dibalik!" << endl;
        return;
    }

    Stack tempStack;
    tempStack.top = -1;

    // Pop semua dari stack utama ke tempStack (urutan jadi terbalik)
    while(stack.top != -1)
    {
        int x = stack.data[stack.top];
        stack.top--;
        tempStack.top++;
        tempStack.data[tempStack.top] = x;
    }

    // Salin tempStack ke stack utama (bukan pop, tapi copy langsung)
    stack = tempStack;

    cout << "Stack berhasil dibalik!" << endl;
}

// ===================== TAMBAHAN 2: STACK GENAP =====================

bool IsFullGenap()
{
    if(stackGenap.top==MAX)
        return true;
    else
        return false;
}

bool IsEmptyGenap()
{
    if(stackGenap.top==-1)
        return true;
    else
        return false;
}

void PushGenap(int data)
{
    if(IsFullGenap())
    {
        cout << "Stack genap sudah penuh!" << endl;
    }
    else
    {
        stackGenap.top++;
        stackGenap.data[stackGenap.top] = data;
    }
}

int PopGenap()
{
    if(IsEmptyGenap())
    {
        cout << "Stack genap kosong!" << endl;
        return -1;
    }
    else
    {
        int dataTerambil = stackGenap.data[stackGenap.top];
        stackGenap.top--;
        return dataTerambil;
    }
}

void printGenap()
{
    int i;
    if(IsEmptyGenap())
    {
        cout << "Stack genap kosong";
    }
    else
    {
        for(i=0; i<=stackGenap.top; i++)
        {
            cout << stackGenap.data[i] << ", ";
        }
    }
}

void clearGenap()
{
    stackGenap.top = -1;
    cout << "Stack genap sudah dikosongkan";
}

// Ambil elemen genap dari stack utama (dari atas/top) dan push ke stack genap
void pushGenapDariStack()
{
    if(IsEmpty())
    {
        cout << "Stack utama kosong!" << endl;
        return;
    }

    // Buat salinan sementara untuk iterasi dari top ke bawah
    Stack tempStack;
    tempStack.top = -1;

    // Pop dari stack utama, cek genap, push ke stackGenap jika genap
    // Simpan semua ke tempStack dulu
    while(stack.top != -1)
    {
        int x = stack.data[stack.top];
        stack.top--;
        tempStack.top++;
        tempStack.data[tempStack.top] = x;
    }

    // Sekarang tempStack berurutan dari bawah ke atas (elemen terakhir stack = top tempStack)
    // Push ke stack genap jika nilai genap, sambil kembalikan ke stack utama
    while(tempStack.top != -1)
    {
        int x = tempStack.data[tempStack.top];
        tempStack.top--;
        stack.top++;
        stack.data[stack.top] = x;

        if(x % 2 == 0)
        {
            PushGenap(x);
            cout << "Nilai " << x << " dipush ke stack genap" << endl;
        }
    }
}

// Menu untuk stack genap
void menuGenap()
{
    int choose, data, nilai;
    do
    {
        system("CLS");
        cout << endl << endl;
        cout << "--------------------\n"
             << "   Menu Stack Genap\n"
             << "--------------------\n"
             << " [1] Push Stack \n"
             << " [2] Pop Stack\n"
             << " [3] Print Data\n"
             << " [4] Kosongkan Stack \n"
             << " [0] Kembali Ke Menu Utama \n\n"
             << "--------------------\n"
             << "Masukkan pilihan : "; cin >> choose;

        switch(choose)
        {
            case 1:
                cout << "Masukkan data yang disimpan : ";
                cin >> data;
                PushGenap(data);
                break;
            case 2:
                nilai = PopGenap();
                if(nilai != -1)
                    cout << "Nilai yang terambil: " << nilai << endl;
                break;
            case 3:
                printGenap();
                break;
            case 4:
                clearGenap();
                break;
            case 0:
                cout << "Kembali ke menu utama...";
                break;
            default:
                cout << "Pilihan tidak tersedia";
                break;
        }
        if(choose != 0)
        {
            cout << "\n";
            system("pause");
        }
    } while(choose != 0);
}

// ===================== MENU UTAMA =====================

void menu()
{
    int choose, data, nilai;

    // Inisialisasi stack genap
    stackGenap.top = -1;

    do
    {
        //Tampilan menu
        system("CLS");
        cout<<endl<<endl;
        cout << "--------------------\n"
             << "    Menu Stack\n"
             << "--------------------\n"
             << " [1] Inisialisasi Stack \n"
             << " [2] Push Stack \n"
             << " [3] Pop Stack\n"
             << " [4] Print Data\n"
             << " [5] Kosongkan Stack \n"
             << " [6] Balik Stack \n"
             << " [7] Stack Genap \n"
             << "\n"
             << " [0] Keluar \n\n"
             << "--------------------\n"
             << "Masukkan pilihan : "; cin >> choose;

        switch (choose)
        {
            case 1:
                init();
                break;
            case 2:
                cout<<"Masukkan data yang disimpan : ";
                cin>>data;
                Push(data);
                break;
            case 3:
                nilai = pop();
                if (nilai != -1) {
                    cout << "Nilai yang terambil: " << nilai << endl;
                }
                break;
            case 4:
                print();
                break;
            case 5:
                clear();
                break;
            case 6:
                reverseStack();
                break;
            case 7:
                // Push nilai genap dari stack utama ke stack genap dulu
                pushGenapDariStack();
                cout << "\n";
                system("pause");
                menuGenap();
                break;
            case 0:
                cout << "Terima Kasih";
                break;
            default:
                cout << "Pilihan tidak tersedia";
                break;
        }
        if(choose != 0)
        {
            cout << "\n";
            system("pause");
        }
    } while (choose !=0);
}