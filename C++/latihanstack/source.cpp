#include "header.h"

Stack stack;

void init()
{
    stack.top = -1;
    cout << "Tumpukan sudah siap diisi" << endl;
}

bool isFull()
{
    if(stack.top == MAX - 1)
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
        system("cls");
        cout<<endl<<endl;
        cout << "\nMenu:" << endl;
        cout << "1. Inisialisasi stack" << endl;
        cout << "2. Push" << endl;
        cout << "3. Pop" << endl;
        cout << "4. Print" << endl;
        cout << "5. Clear" << endl;
        cout << "0. Exit" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice)
        {
            case 1:                     
                init();
                break;
            case 2:                     
                cout << "Masukkan data: ";
                cin >> data;
                push(data);
                break;
            case 3:                     
                nilai = pop();
                if (nilai != -1)
                    cout << "Data yang dihapus: " << nilai << endl;
                break;
            case 4:                     
                print();
                break;
            case 5:                    
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
