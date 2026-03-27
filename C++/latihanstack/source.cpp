#include "header.h"

Stack stack;

void init()
{
    stack.top = -1;
    cout << "Tumpukan sudah siap diisi" << endl;
}

bool isFull()
{
    if(stack.top == MAX)
        return true;
    else
        return false;
}

bool isEmpty()
{
    if(stack.top == -1)
        return true;
    else
        return false;
}

void push(int data)
{
    if (isFull()==true)
        cout << "Tumpukan sudah penuh" << endl;
    else
    {
        stack.top++;
        stack.data[stack.top] = data;
        cout << "Data " << data << " berhasil ditambahkan" << endl;
    }
}

int pop()
{
    if (isEmpty()==true)
    {
        cout << "Tumpukan sudah kosong" << endl;
        return -1;
    }
    else
    {
        int data = stack.data[stack.top];
        stack.top--;
        cout << "Data " << data << " berhasil dihapus" << endl;
        return data;
    }
}

void print()
{
    if (isEmpty())
        cout << "Tumpukan sudah kosong" << endl;
    else
    {
        for (int i = 0; i <= stack.top; i++)
            cout << stack.data[i] << " ";
        cout << endl; 
    }
}  

void clear()
{
    stack.top = -1;
    cout << "Tumpukan kosong" << endl;
}

void menu()
{
    int choice, data;
    int nilai; 

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print" << endl;
        cout << "4. Clear" << endl;
        cout << "0. Exit" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice)
        {
            case 1:                     
                cout << "Masukkan data: ";
                cin >> data;
                push(data);
                break;
            case 2:                     
                nilai = pop();
                if (nilai != -1)
                    cout << "Data yang dihapus: " << nilai << endl;
                break;
            case 3:                     
                print();
                break;
            case 4:                    
                clear();
                break;
            case 0:                     
                cout << "Terima kasih telah menggunakan program ini" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
        if (choice != 0)
        {
            cout << "\n";
            system("pause");
        } 
    } while (choice != 0);
}
