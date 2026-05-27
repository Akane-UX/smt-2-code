#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #define CLEAR "cls"
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    #define CLEAR "clear"
#endif

using namespace std;

// ============================================================
// KONSTANTA GAME
// ============================================================
const int LEBAR  = 30;   // lebar area bermain
const int TINGGI = 15;   // tinggi area bermain
const int MAKS_SKOR_HISTORY = 5;  // maksimum skor yang disimpan di stack

// ============================================================
// ADT: ARAH GERAK ULAR
// (Abstract Data Type sederhana menggunakan enum)
// ============================================================
enum Arah {
    ATAS,
    BAWAH,
    KIRI,
    KANAN
};

// ============================================================
// ADT: NODE UNTUK LINKED LIST (TUBUH ULAR)
// Setiap bagian tubuh ular adalah satu Node
// ============================================================
struct NodeTubuh {
    int x;              // posisi kolom
    int y;              // posisi baris
    NodeTubuh* next;    // pointer ke bagian tubuh berikutnya
};

// ============================================================
// LINKED LIST: TUBUH ULAR
// Tubuh ular direpresentasikan sebagai Linked List
// - Kepala = node pertama
// - Ekor   = node terakhir
// ============================================================
struct LinkedListUlar {
    NodeTubuh* kepala;  // node pertama (kepala ular)
    NodeTubuh* ekor;    // node terakhir (ekor ular)
    int panjang;        // jumlah bagian tubuh
};

// ============================================================
// QUEUE: ANTRIAN MAKANAN
// Makanan yang akan muncul disimpan dalam antrian (FIFO)
// - Makanan pertama masuk = makanan pertama keluar
// ============================================================
struct NodeMakanan {
    int x;
    int y;
    NodeMakanan* next;
};

struct QueueMakanan {
    NodeMakanan* depan; // elemen pertama (akan diambil duluan)
    NodeMakanan* belakang; // elemen terakhir (tempat menambah)
    int jumlah;
};

// ============================================================
// STACK: RIWAYAT SKOR
// Skor setiap permainan disimpan di stack (LIFO)
// - Skor terbaru selalu di atas (top)
// ============================================================
struct NodeSkor {
    int skor;
    NodeSkor* next;
};

struct StackSkor {
    NodeSkor* top;   // elemen paling atas
    int jumlah;
};

// ============================================================
// GRAPH: PETA GRID PERMAINAN
// Grid adalah graph dengan setiap sel terhubung ke 4 tetangga
// (atas, bawah, kiri, kanan)
// ============================================================
struct SelGrid {
    bool adaTembok;   // apakah sel ini adalah tembok?
    bool adaMakanan;  // apakah sel ini ada makanan?
    bool adaUlar;     // apakah sel ini ada bagian tubuh ular?
};

struct GraphGrid {
    SelGrid grid[TINGGI][LEBAR]; // matriks sel
};

// ============================================================
// ADT: DATA UTAMA GAME (menggabungkan semua struktur)
// ============================================================
struct DataGame {
    LinkedListUlar  ular;       // tubuh ular (Linked List)
    QueueMakanan    antrian;    // antrian makanan (Queue)
    StackSkor       riwayat;   // riwayat skor (Stack)
    GraphGrid       peta;      // peta permainan (Graph)
    Arah            arahGerak; // arah gerak ular saat ini
    int             skor;      // skor saat ini
    bool            gameOver;  // status apakah game berakhir
};


// ============================================================
// DEKLARASI FUNGSI - LINKED LIST (tubuh ular)
// ============================================================
void  inisialisasiUlar(LinkedListUlar& ular, int startX, int startY);
void  tambahKepalaBaru(LinkedListUlar& ular, int x, int y);
void  hapusEkor(LinkedListUlar& ular);
bool  cekTabrakanDiri(LinkedListUlar& ular, int x, int y);
void  bersihkanUlar(LinkedListUlar& ular);

// ============================================================
// DEKLARASI FUNGSI - QUEUE (antrian makanan)
// ============================================================
void  inisialisasiQueue(QueueMakanan& q);
void  enqueue(QueueMakanan& q, int x, int y);
bool  dequeue(QueueMakanan& q, int& x, int& y);
bool  cekTabrakanMakanan(QueueMakanan& q, int x, int y);
bool  hapusMakananDiPosisi(QueueMakanan& q, int x, int y);
bool  queueKosong(QueueMakanan& q);
void  bersihkanQueue(QueueMakanan& q);

// ============================================================
// DEKLARASI FUNGSI - STACK (riwayat skor)
// ============================================================
void  inisialisasiStack(StackSkor& s);
void  push(StackSkor& s, int skor);
bool  pop(StackSkor& s, int& skor);
bool  stackKosong(StackSkor& s);
void  tampilkanRiwayatSkor(StackSkor& s);
void  bersihkanStack(StackSkor& s);

// ============================================================
// DEKLARASI FUNGSI - GRAPH (peta grid)
// ============================================================
void  inisialisasiGraph(GraphGrid& peta);
void  updateGraph(GraphGrid& peta, LinkedListUlar& ular, QueueMakanan& q);
bool  selBisaDimasuki(GraphGrid& peta, int x, int y);

// ============================================================
// DEKLARASI FUNGSI - GAME UTAMA
// ============================================================
void  inisialisasiGame(DataGame& game);
void  generateMakananBaru(DataGame& game);
void  pindahkanUlar(DataGame& game);
void  tampilkanLayar(DataGame& game);
void  jalankanGame(DataGame& game);
int   ambilInput(); // Ubah ke int untuk handle arrow keys

// ============================================================
// KONSTANTA KEYBOARD (Arrow Keys)
// ============================================================
const int KEY_UP    = 1001;
const int KEY_DOWN  = 1002;
const int KEY_LEFT  = 1003;
const int KEY_RIGHT = 1004;

#endif  // HEADER_H
