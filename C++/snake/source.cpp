#include "header.h"

// ============================================================
//  IMPLEMENTASI LINKED LIST - TUBUH ULAR
//  Setiap node = satu bagian tubuh ular
//  Kepala selalu di depan, ekor di belakang
// ============================================================

// Membuat ular awal dengan panjang 3 bagian
void inisialisasiUlar(LinkedListUlar& ular, int startX, int startY) {
    ular.kepala = nullptr;
    ular.ekor   = nullptr;
    ular.panjang = 0;

    // BUG FIX: Loop dari i=2 turun ke 0 agar kepala berada di startX.
    // Dulu: i=0,1,2 ? insert (startX, startX-1, startX-2) ke depan
    //       ? kepala akhirnya di startX-2 (paling kiri/belakang)
    //       ? gerak KANAN langsung tabrak tubuh sendiri!
    // Sekarang: i=2,1,0 ? insert (startX-2, startX-1, startX) ke depan
    //           ? kepala akhirnya di startX (paling kanan/depan) ?
    for (int i = 2; i >= 0; i--) {
        tambahKepalaBaru(ular, startX - i, startY);
    }
}

// Menambah node baru di depan (menjadi kepala baru)
// Ini terjadi setiap ular bergerak
void tambahKepalaBaru(LinkedListUlar& ular, int x, int y) {
    NodeTubuh* nodeBaru = new NodeTubuh;
    nodeBaru->x    = x;
    nodeBaru->y    = y;
    nodeBaru->next = ular.kepala;  // sambungkan ke kepala lama

    ular.kepala = nodeBaru;  // kepala baru menggantikan kepala lama

    // Jika ini node pertama, dia juga menjadi ekor
    if (ular.ekor == nullptr) {
        ular.ekor = nodeBaru;
    }
    ular.panjang++;
}

// Menghapus node paling belakang (ekor)
// Ini terjadi saat ular bergerak tanpa makan
void hapusEkor(LinkedListUlar& ular) {
    if (ular.kepala == nullptr) return;

    // Jika hanya ada 1 node
    if (ular.kepala == ular.ekor) {
        delete ular.kepala;
        ular.kepala = nullptr;
        ular.ekor   = nullptr;
        ular.panjang = 0;
        return;
    }

    // Cari node sebelum ekor
    NodeTubuh* nodeSaatIni = ular.kepala;
    while (nodeSaatIni->next != ular.ekor) {
        nodeSaatIni = nodeSaatIni->next;
    }

    // Hapus ekor dan update pointer
    delete ular.ekor;
    ular.ekor = nodeSaatIni;
    ular.ekor->next = nullptr;
    ular.panjang--;
}

// Cek apakah posisi (x,y) sudah ditempati tubuh ular sendiri
bool cekTabrakanDiri(LinkedListUlar& ular, int x, int y) {
    NodeTubuh* saat = ular.kepala;
    while (saat != nullptr) {
        if (saat->x == x && saat->y == y) return true;
        saat = saat->next;
    }
    return false;
}

// Bebaskan semua memori linked list
void bersihkanUlar(LinkedListUlar& ular) {
    NodeTubuh* saat = ular.kepala;
    while (saat != nullptr) {
        NodeTubuh* berikut = saat->next;
        delete saat;
        saat = berikut;
    }
    ular.kepala  = nullptr;
    ular.ekor    = nullptr;
    ular.panjang = 0;
}


// ============================================================
//  IMPLEMENTASI QUEUE - ANTRIAN MAKANAN
//  FIFO: makanan yang dimasukkan duluan = keluar duluan
//  Digunakan untuk menentukan makanan berikutnya
// ============================================================

void inisialisasiQueue(QueueMakanan& q) {
    q.depan    = nullptr;
    q.belakang = nullptr;
    q.jumlah   = 0;
}

// Tambah makanan baru ke belakang antrian (enqueue)
void enqueue(QueueMakanan& q, int x, int y) {
    NodeMakanan* nodeBaru = new NodeMakanan;
    nodeBaru->x    = x;
    nodeBaru->y    = y;
    nodeBaru->next = nullptr;

    if (q.belakang != nullptr) {
        q.belakang->next = nodeBaru;
    }
    q.belakang = nodeBaru;

    if (q.depan == nullptr) {
        q.depan = nodeBaru;
    }
    q.jumlah++;
}

// Ambil makanan dari depan antrian (dequeue)
// Mengembalikan true jika berhasil, false jika antrian kosong
bool dequeue(QueueMakanan& q, int& x, int& y) {
    if (q.depan == nullptr) return false;

    NodeMakanan* hapus = q.depan;
    x = hapus->x;
    y = hapus->y;

    q.depan = q.depan->next;
    if (q.depan == nullptr) {
        q.belakang = nullptr;
    }

    delete hapus;
    q.jumlah--;
    return true;
}

bool queueKosong(QueueMakanan& q) {
    return q.depan == nullptr;
}

// Cek apakah posisi (x,y) sudah ada makanan di antrian
bool cekTabrakanMakanan(QueueMakanan& q, int x, int y) {
    NodeMakanan* saat = q.depan;
    while (saat != nullptr) {
        if (saat->x == x && saat->y == y) return true;
        saat = saat->next;
    }
    return false;
}

// Hapus makanan di posisi tertentu (jika dimakan ular)
bool hapusMakananDiPosisi(QueueMakanan& q, int x, int y) {
    if (q.depan == nullptr) return false;

    NodeMakanan* saat = q.depan;
    NodeMakanan* sebelum = nullptr;

    while (saat != nullptr) {
        if (saat->x == x && saat->y == y) {
            // Ketemu! Hapus node ini
            if (sebelum == nullptr) {
                // Hapus di depan
                q.depan = saat->next;
                if (q.depan == nullptr) q.belakang = nullptr;
            } else {
                // Hapus di tengah atau belakang
                sebelum->next = saat->next;
                if (saat == q.belakang) q.belakang = sebelum;
            }
            delete saat;
            q.jumlah--;
            return true;
        }
        sebelum = saat;
        saat = saat->next;
    }
    return false;
}

void bersihkanQueue(QueueMakanan& q) {
    int x, y;
    while (!queueKosong(q)) {
        dequeue(q, x, y);
    }
}


// ============================================================
//  IMPLEMENTASI STACK - RIWAYAT SKOR
//  LIFO: skor yang dimasukkan terakhir = ditampilkan pertama
//  Menyimpan 5 skor terakhir permainan
// ============================================================

void inisialisasiStack(StackSkor& s) {
    s.top    = nullptr;
    s.jumlah = 0;
}

// Masukkan skor baru ke atas stack (push)
void push(StackSkor& s, int skor) {
    // Jika sudah penuh, hapus skor paling bawah dulu
    if (s.jumlah >= MAKS_SKOR_HISTORY) {
        // Cari dan hapus node paling bawah
        NodeSkor* saat = s.top;
        NodeSkor* sebelumnya = nullptr;
        while (saat->next != nullptr) {
            sebelumnya = saat;
            saat = saat->next;
        }
        if (sebelumnya != nullptr) {
            sebelumnya->next = nullptr;
        } else {
            s.top = nullptr;
        }
        delete saat;
        s.jumlah--;
    }

    NodeSkor* nodeBaru = new NodeSkor;
    nodeBaru->skor = skor;
    nodeBaru->next = s.top;  // sambung ke top lama
    s.top    = nodeBaru;     // node baru jadi top
    s.jumlah++;
}

// Ambil skor dari atas stack (pop)
bool pop(StackSkor& s, int& skor) {
    if (s.top == nullptr) return false;

    NodeSkor* hapus = s.top;
    skor  = hapus->skor;
    s.top = s.top->next;

    delete hapus;
    s.jumlah--;
    return true;
}

bool stackKosong(StackSkor& s) {
    return s.top == nullptr;
}

// Tampilkan semua skor dari top ke bawah
void tampilkanRiwayatSkor(StackSkor& s) {
    if (stackKosong(s)) {
        cout << "  (belum ada riwayat skor)\n";
        return;
    }

    NodeSkor* saat = s.top;
    int urutan = 1;
    while (saat != nullptr) {
        cout << "  " << urutan << ". Skor: " << saat->skor << "\n";
        saat = saat->next;
        urutan++;
    }
}

void bersihkanStack(StackSkor& s) {
    int skor;
    while (!stackKosong(s)) {
        pop(s, skor);
    }
}


// ============================================================
//  IMPLEMENTASI GRAPH - PETA GRID
//  Grid adalah graph tak berarah
//  Setiap sel (node graph) terhubung ke 4 tetangga
//  Digunakan untuk mendeteksi tabrakan dan validasi posisi
// ============================================================

// Reset semua sel grid menjadi kosong
void inisialisasiGraph(GraphGrid& peta) {
    for (int baris = 0; baris < TINGGI; baris++) {
        for (int kolom = 0; kolom < LEBAR; kolom++) {
            // Tepi grid adalah tembok
            bool iniTembok = (baris == 0 || baris == TINGGI - 1 ||
                              kolom == 0 || kolom == LEBAR  - 1);
            peta.grid[baris][kolom].adaTembok  = iniTembok;
            peta.grid[baris][kolom].adaMakanan = false;
            peta.grid[baris][kolom].adaUlar    = false;
        }
    }
}

// Update status setiap sel berdasarkan posisi ular & makanan
void updateGraph(GraphGrid& peta, LinkedListUlar& ular, QueueMakanan& q) {
    // Reset dulu semua sel (kecuali tembok)
    for (int baris = 0; baris < TINGGI; baris++) {
        for (int kolom = 0; kolom < LEBAR; kolom++) {
            peta.grid[baris][kolom].adaMakanan = false;
            peta.grid[baris][kolom].adaUlar    = false;
        }
    }

    // Tandai sel yang ditempati ular
    NodeTubuh* saatUlar = ular.kepala;
    while (saatUlar != nullptr) {
        if (saatUlar->y >= 0 && saatUlar->y < TINGGI &&
            saatUlar->x >= 0 && saatUlar->x < LEBAR) {
            peta.grid[saatUlar->y][saatUlar->x].adaUlar = true;
        }
        saatUlar = saatUlar->next;
    }

    // Tandai SEMUA sel makanan dari antrian (Queue)
    NodeMakanan* saatMakan = q.depan;
    while (saatMakan != nullptr) {
        if (saatMakan->y >= 0 && saatMakan->y < TINGGI &&
            saatMakan->x >= 0 && saatMakan->x < LEBAR) {
            peta.grid[saatMakan->y][saatMakan->x].adaMakanan = true;
        }
        saatMakan = saatMakan->next;
    }
}

// Cek apakah sebuah sel bisa dimasuki (tidak tembok)
// Ini memanfaatkan konsep adjacency dalam graph
bool selBisaDimasuki(GraphGrid& peta, int x, int y) {
    if (x < 0 || x >= LEBAR || y < 0 || y >= TINGGI) return false;
    return !peta.grid[y][x].adaTembok;
}


// ============================================================
//  FUNGSI INPUT KEYBOARD (cross-platform)
// ============================================================
int ambilInput() {
#ifdef _WIN32
    if (_kbhit()) {
        int ch = _getch();
        if (ch == 0 || ch == 224) { // Kode awal untuk arrow keys
            ch = _getch();
            switch (ch) {
                case 72: return KEY_UP;
                case 80: return KEY_DOWN;
                case 75: return KEY_LEFT;
                case 77: return KEY_RIGHT;
            }
        }
        return ch;
    }
    return 0;
#else
    // Linux/Mac: set terminal ke non-blocking dan handle escape sequences
    struct termios t_lama, t_baru;
    tcgetattr(STDIN_FILENO, &t_lama);
    t_baru = t_lama;
    t_baru.c_lflag    &= ~(ICANON | ECHO);
    t_baru.c_cc[VMIN]  = 0;
    t_baru.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &t_baru);

    char c = 0;
    int nread = read(STDIN_FILENO, &c, 1);
    
    if (nread > 0 && c == '\033') { // Escape sequence
        char seq[3];
        if (read(STDIN_FILENO, &seq[0], 1) > 0 && read(STDIN_FILENO, &seq[1], 1) > 0) {
            if (seq[0] == '[') {
                tcsetattr(STDIN_FILENO, TCSANOW, &t_lama);
                switch (seq[1]) {
                    case 'A': return KEY_UP;
                    case 'B': return KEY_DOWN;
                    case 'C': return KEY_RIGHT;
                    case 'D': return KEY_LEFT;
                }
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &t_lama);
    return (nread > 0) ? (int)c : 0;
#endif
}


// ============================================================
//  GENERATE MAKANAN BARU
//  Posisi makanan dibuat random lalu dimasukkan ke Queue
// ============================================================
void generateMakananBaru(DataGame& game) {
    int x, y;
    int coba = 0;

    // Coba cari posisi kosong (bukan tembok, bukan ular, bukan makanan lain)
    do {
        x = rand() % (LEBAR  - 2) + 1;
        y = rand() % (TINGGI - 2) + 1;
        coba++;
    } while ((cekTabrakanDiri(game.ular, x, y) || cekTabrakanMakanan(game.antrian, x, y)) && coba < 100);

    // Masukkan posisi makanan ke antrian (Queue)
    enqueue(game.antrian, x, y);
}


// ============================================================
//  INISIALISASI GAME
//  Menyiapkan semua struktur data sebelum game dimulai
// ============================================================
void inisialisasiGame(DataGame& game) {
    // BUG FIX: srand dipanggil SEKALI di sini agar tiap sesi
    // menghasilkan posisi makanan yang berbeda-beda
    srand((unsigned int)time(nullptr));

    // Inisialisasi semua struktur data
    inisialisasiGraph(game.peta);
    inisialisasiQueue(game.antrian);
    // (Stack riwayat TIDAK direset agar skor tersimpan antar sesi)

    // Buat ular di tengah layar
    int tengahX = LEBAR  / 2;
    int tengahY = TINGGI / 2;
    inisialisasiUlar(game.ular, tengahX, tengahY);

    game.arahGerak = KANAN;
    game.skor      = 0;
    game.gameOver  = false;

    // Siapkan 3 makanan sekaligus di antrian
    generateMakananBaru(game);
    generateMakananBaru(game);
    generateMakananBaru(game);
}


// ============================================================
//  PINDAHKAN ULAR (logika utama gerak)
// ============================================================
void pindahkanUlar(DataGame& game) {
    // Hitung posisi kepala baru berdasarkan arah
    int kepalaBaru_X = game.ular.kepala->x;
    int kepalaBaru_Y = game.ular.kepala->y;

    switch (game.arahGerak) {
        case ATAS:   kepalaBaru_Y--; break;
        case BAWAH:  kepalaBaru_Y++; break;
        case KIRI:   kepalaBaru_X--; break;
        case KANAN:  kepalaBaru_X++; break;
    }

    // Cek apakah kepala baru menabrak tembok (gunakan Graph)
    if (!selBisaDimasuki(game.peta, kepalaBaru_X, kepalaBaru_Y)) {
        game.gameOver = true;
        return;
    }

    // Cek apakah kepala baru menabrak tubuh sendiri (gunakan Linked List)
    if (cekTabrakanDiri(game.ular, kepalaBaru_X, kepalaBaru_Y)) {
        game.gameOver = true;
        return;
    }

    // Gerakkan ular: tambah kepala baru di depan
    tambahKepalaBaru(game.ular, kepalaBaru_X, kepalaBaru_Y);

    // BUG FIX: Cek apakah kepala baru memakan SALAH SATU makanan di antrian
    if (hapusMakananDiPosisi(game.antrian, kepalaBaru_X, kepalaBaru_Y)) {
        // Makan! Skor bertambah, ekor TIDAK dihapus (ular memanjang)
        game.skor += 10;
        // Isi antrian lagi dengan makanan baru
        generateMakananBaru(game);
    } else {
        // Tidak makan: hapus ekor agar panjang ular tetap
        hapusEkor(game.ular);
    }
}


// ============================================================
//  TAMPILKAN LAYAR GAME
// ============================================================
void tampilkanLayar(DataGame& game) {
    system(CLEAR);

    // Update graph dengan semua makanan
    updateGraph(game.peta, game.ular, game.antrian);

    cout << "=== GAME SNAKE - STRUKTUR DATA ===" << "\n";
    cout << "Skor: " << game.skor
         << "  |  Panjang Ular: " << game.ular.panjang << "\n";
    cout << "Kontrol: ARROW atau WASD  (Q=Keluar)\n";
    cout << "\n";

    // Gambar grid berdasarkan GraphGrid
    for (int baris = 0; baris < TINGGI; baris++) {
        for (int kolom = 0; kolom < LEBAR; kolom++) {
            SelGrid& sel = game.peta.grid[baris][kolom];

            if (sel.adaTembok) {
                cout << "#";  // tembok
            } else if (kolom == game.ular.kepala->x &&
                       baris == game.ular.kepala->y) {
                cout << "O";  // kepala ular
            } else if (sel.adaUlar) {
                cout << "o";  // badan ular
            } else if (sel.adaMakanan) {
                cout << "*";  // makanan
            } else {
                cout << " ";  // kosong
            }
        }
        cout << "\n";
    }

    cout << "\n";
    cout << "--- Struktur Data yang Digunakan ---\n";
    cout << "Linked List : tubuh ular (" << game.ular.panjang << " node)\n";
    cout << "Queue       : " << game.antrian.jumlah << " makanan di layar/antrian\n";
    cout << "Stack       : " << game.riwayat.jumlah << " skor tersimpan di riwayat\n";
    cout << "Graph       : grid " << LEBAR << "x" << TINGGI << " (tiap sel = node graph)\n";
}


// ============================================================
//  LOOP UTAMA GAME
// ============================
void jalankanGame(DataGame& game) {
    tampilkanLayar(game);

    while (!game.gameOver) {
        // Delay agar game tidak terlalu cepat
#ifdef _WIN32
        Sleep(150);
#else
        usleep(150000);
#endif

        // Baca input keyboard (non-blocking)
        int tombol = ambilInput();

        // Update arah (support WASD + Arrow Keys)
        if      (((tombol == 'w' || tombol == 'W') || tombol == KEY_UP)    && game.arahGerak != BAWAH)
            game.arahGerak = ATAS;
        else if (((tombol == 's' || tombol == 'S') || tombol == KEY_DOWN)  && game.arahGerak != ATAS)
            game.arahGerak = BAWAH;
        else if (((tombol == 'a' || tombol == 'A') || tombol == KEY_LEFT)  && game.arahGerak != KANAN)
            game.arahGerak = KIRI;
        else if (((tombol == 'd' || tombol == 'D') || tombol == KEY_RIGHT) && game.arahGerak != KIRI)
            game.arahGerak = KANAN;
        else if (tombol == 'q' || tombol == 'Q') {
            game.gameOver = true;
            break;
        }

        // Pindahkan ular satu langkah
        pindahkanUlar(game);

        // Tampilkan layar hasil setelah bergerak
        tampilkanLayar(game);
    }

    // Simpan skor ke Stack setelah game selesai
    push(game.riwayat, game.skor);

    // Tampilkan layar game over
    system(CLEAR);
    cout << "\n";
    cout << "  ============================\n";
    cout << "         GAME  OVER!\n";
    cout << "  ============================\n";
    cout << "  Skor Anda   : " << game.skor << "\n";
    cout << "  Panjang Ular: " << game.ular.panjang << "\n";
    cout << "\n";
    cout << "  === Riwayat Skor (Stack) ===\n";
    tampilkanRiwayatSkor(game.riwayat);
    cout << "\n";
}
