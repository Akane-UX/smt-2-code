#include <iostream>
using namespace std;

// 1. Struktur Node masih sama persis
struct Node {
    int data;
    Node* next;
};

// 2. Class untuk Circular Linked List
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Fungsi untuk menambahkan node di akhir list
    void insertAkhir(int nilaiBaru) {
        Node* nodeBaru = new Node();
        nodeBaru->data = nilaiBaru;

        // Jika list masih kosong
        if (head == NULL) {
            head = nodeBaru;
            nodeBaru->next = head; // Menunjuk ke dirinya sendiri!
        } 
        // Jika list sudah ada isinya
        else {
            Node* temp = head;
            // Cari node terakhir (yang 'next'-nya menunjuk ke head)
            while (temp->next != head) {
                temp = temp->next;
            }
            // Sambungkan node terakhir ke node baru
            temp->next = nodeBaru;
            // Sambungkan node baru kembali ke head
            nodeBaru->next = head;
        }
    }

    // Fungsi untuk mencetak semua elemen
    void tampilkan() {
        if (head == NULL) {
            cout << "List kosong." << endl;
            return;
        }

        Node* temp = head;
        // Kita menggunakan do-while agar node pertama tetap tercetak 
        // sebelum mengecek kondisi putarannya.
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head); // Berhenti jika kembali ke awal
        
        cout << "(Kembali ke Head: " << head->data << ")" << endl;
    }
};

int main() {
    CircularLinkedList listLingkaran;

    listLingkaran.insertAkhir(10);
    listLingkaran.insertAkhir(20);
    listLingkaran.insertAkhir(30);

    // Output: 10 -> 20 -> 30 -> (Kembali ke Head: 10)
    listLingkaran.tampilkan();

    return 0;
}