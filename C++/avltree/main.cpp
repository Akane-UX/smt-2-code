#include "header.h"

int main (){
    int pil, data;
    AVLNode *root = nullptr;
    do
    {
            cout <<"\n---------------------------------\n"
            <<"options for AVL Tree\n"
            <<"1. tambah \n"
            <<"2. lihat pre-order \n"
            <<"3. keluar \n"
            <<"----------------------------------\n"
            <<"masukan pilihan : "; cin >> pil;
            switch (pil)
            {
            case 1:
                cout << "----------------------------\n";
                cout << "masukan data : "; 
                cin >> data;
                root = insert(root, data);
                break;
            case 2:
                cout << "----------------------------\n";
                cout << "Output Pre-order : ";
                printPreOrder(root);
                cout << "\n";
                if(root != nullptr){
                    printPreOrder(root);
                    cout << "AVL Tree kosong\n";
                }
                break;
            default:
                cout << "pilihan tidak valid\n";
                break;
            }
            
    } while (pil != 0);
return 0;
    
}