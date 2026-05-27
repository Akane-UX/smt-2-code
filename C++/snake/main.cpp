#include "header.h"

// ============================================================
//  TAMPILAN MENU UTAMA
// ============================================================
void tampilkanMenu() {
    system(CLEAR);
    cout << "\n";
    cout << "  ========================================\n";
    cout << "       SNAKE GAME - STRUKTUR DATA\n";
    cout << "  ========================================\n";
    cout << "\n";
    cout << "  Struktur data yang digunakan:\n";
    cout << "  [1] ADT       - Tipe data buatan sendiri\n";
    cout << "  [2] Linked List - Tubuh ular (tiap bagian = node)\n";
    cout << "  [3] Queue       - Antrian makanan (FIFO)\n";
    cout << "  [4] Stack       - Riwayat skor (LIFO)\n";
    cout << "  [5] Graph       - Peta grid permainan\n";
    cout << "\n";
    cout << "  Simbol di layar:\n";
    cout << "    O = Kepala ular\n";
    cout << "    o = Badan ular\n";
    cout << "    * = Makanan\n";
    cout << "    # = Tembok\n";
    cout << "\n";
    cout << "  ========================================\n";
    cout << "  1. Mulai Main\n";
    cout << "  2. Lihat Cara Main\n";
    cout << "  3. Keluar\n";
    cout << "  ========================================\n";
    cout << "  Pilihan: ";
}

// ============================================================
//  TAMPILAN CARA MAIN
// ============================================================
void tampilkanCaraMain() {
    system(CLEAR);
    cout << "\n";
    cout << "  === CARA MAIN ===\n";
    cout << "\n";
    cout << "  Kontrol:\n";
    cout << "    ARROW / WASD  =  Gerak ular\n";
    cout << "    Q             =  Keluar dari game\n";
    cout << "\n";
    cout << "  Aturan:\n";
    cout << "    - Makan bintang (*) untuk menambah skor\n";
    cout << "    - Jangan sampai menabrak tembok (#)\n";
    cout << "    - Jangan sampai menabrak tubuh sendiri\n";
    cout << "    - Setiap makan, tubuh ular memanjang\n";
    cout << "    - Skor tersimpan otomatis setelah game selesai\n";
    cout << "\n";
    cout << "  Penjelasan Singkat Struktur Data:\n";
    cout << "\n";
    cout << "  LINKED LIST:\n";
    cout << "    Tubuh ular disimpan sebagai linked list.\n";
    cout << "    Saat bergerak: tambah node baru di kepala,\n";
    cout << "    hapus node di ekor (kecuali baru makan).\n";
    cout << "\n";
    cout << "  QUEUE (Antrian):\n";
    cout << "    Posisi makanan disimpan dalam antrian.\n";
    cout << "    Makanan masuk dari belakang, diambil dari depan.\n";
    cout << "\n";
    cout << "  STACK (Tumpukan):\n";
    cout << "    Skor tiap game disimpan di stack.\n";
    cout << "    Skor terbaru selalu di atas.\n";
    cout << "\n";
    cout << "  GRAPH:\n";
    cout << "    Grid permainan adalah sebuah graph.\n";
    cout << "    Setiap sel terhubung ke 4 sel tetangga.\n";
    cout << "\n";
    cout << "  Tekan Enter untuk kembali ke menu...";
    cin.get();
}

// ============================================================
//  FUNGSI MAIN - TITIK MASUK PROGRAM
// ============================================================
int main() {
    DataGame game;

    // ===========================================================
    // BUG FIX: Inisialisasi pointer ke nullptr dulu sebelum
    // dipakai. Tanpa ini, pointer bernilai sampah ? crash.
    // ===========================================================
    game.ular.kepala   = nullptr;
    game.ular.ekor     = nullptr;
    game.ular.panjang  = 0;
    game.antrian.depan     = nullptr;
    game.antrian.belakang  = nullptr;
    game.antrian.jumlah    = 0;

    // Inisialisasi stack skor (hanya sekali di awal program)
    inisialisasiStack(game.riwayat);

    char pilihan;
    bool keluarProgram = false;

    while (!keluarProgram) {
        tampilkanMenu();

        // ===========================================================
        // BUG FIX: Gunakan cin.get() agar karakter terbaca dengan
        // benar. cin >> pilihan sering menyisakan '\n' di buffer
        // yang menyebabkan input berikutnya terlewat / salah baca.
        // ===========================================================
        pilihan = cin.get();
        cin.ignore(1000, '\n');  // buang sisa buffer sampai newline

        switch (pilihan) {
            case '1':
                // Bersihkan data lama (aman karena pointer sudah valid)
                bersihkanUlar(game.ular);
                bersihkanQueue(game.antrian);
                // Mulai permainan baru
                inisialisasiGame(game);
                jalankanGame(game);

                cout << "\n  Tekan Enter untuk kembali ke menu...";
                cin.get();
                break;

            case '2':
                // Tampilkan cara main
                tampilkanCaraMain();
                break;

            case '3':
                // Keluar program
                keluarProgram = true;
                break;

            default:
                cout << "\n  Pilihan tidak valid! Tekan Enter...";
                cin.get();
                break;
        }
    }

    // Bersihkan semua memori sebelum program selesai
    bersihkanUlar(game.ular);
    bersihkanQueue(game.antrian);
    bersihkanStack(game.riwayat);

    cout << "\n  Terima kasih sudah bermain!\n\n";
    return 0;
}
