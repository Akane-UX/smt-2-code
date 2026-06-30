/**
 * ============================================
 *  LABIRIN GAME - Source / Implementasi
 *  Semua logika game ada di sini
 * ============================================
 */

#include "header.h"

// ==================== FUNGSI UTILITAS ====================

void clearScreen() {
    printf("\033[2J\033[H");
}

// Membaca input keyboard tanpa perlu Enter (raw mode)
char getKeyPress() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void setColor(const char* color) {
    printf("%s", color);
}

void printCentered(const char* text, int width) {
    int len = strlen(text);
    int padding = (width - len) / 2;
    if (padding < 0) padding = 0;
    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s", text);
}

void sleepMs(int milliseconds) {
    usleep(milliseconds * 1000);
}

// ==================== FUNGSI MENU ====================

void showSplashScreen() {
    clearScreen();
    setColor(COLOR_CYAN);
    printf("\n\n\n");
    printf("    ██╗      █████╗ ██████╗ ██╗██████╗ ██╗███╗   ██╗\n");
    printf("    ██║     ██╔══██╗██╔══██╗██║██╔══██╗██║████╗  ██║\n");
    printf("    ██║     ███████║██████╔╝██║██████╔╝██║██╔██╗ ██║\n");
    printf("    ██║     ██╔══██║██╔══██╗██║██╔══██╗██║██║╚██╗██║\n");
    printf("    ███████╗██║  ██║██████╔╝██║██║  ██║██║██║ ╚████║\n");
    printf("    ╚══════╝╚═╝  ╚═╝╚═════╝ ╚═╝╚═╝  ╚═╝╚═╝╚═╝ ╚═══╝\n");
    setColor(COLOR_RESET);
    printf("\n");
    setColor(COLOR_YELLOW);
    printCentered(">> THE MAZE ESCAPE <<", 60);
    printf("\n\n");
    setColor(COLOR_DIM);
    printCentered("Temukan jalan keluar... atau mati mencoba.", 60);
    printf("\n\n");
    setColor(COLOR_WHITE);
    printCentered("[Tekan ENTER untuk mulai]", 60);
    setColor(COLOR_RESET);
    printf("\n");

    // Animasi berkedip
    char ch;
    do {
        ch = getKeyPress();
    } while (ch != '\n' && ch != '\r');
}

void showMainMenu() {
    clearScreen();
    printf("\n");
    setColor(COLOR_CYAN);
    printf("  ╔══════════════════════════════════════╗\n");
    printf("  ║         ");
    setColor(COLOR_YELLOW);
    printf("LABIRIN - MAZE GAME");
    setColor(COLOR_CYAN);
    printf("         ║\n");
    printf("  ╠══════════════════════════════════════╣\n");
    printf("  ║                                      ║\n");
    printf("  ║");
    setColor(COLOR_GREEN);
    printf("   [1] Mulai Permainan                ");
    setColor(COLOR_CYAN);
    printf("║\n");
    printf("  ║");
    setColor(COLOR_BLUE);
    printf("   [2] Cara Bermain                   ");
    setColor(COLOR_CYAN);
    printf("║\n");
    printf("  ║");
    setColor(COLOR_RED);
    printf("   [3] Keluar                         ");
    setColor(COLOR_CYAN);
    printf("║\n");
    printf("  ║                                      ║\n");
    printf("  ╚══════════════════════════════════════╝\n");
    setColor(COLOR_RESET);
    printf("\n  Pilihan: ");
}

void showHowToPlay() {
    clearScreen();
    printf("\n");
    setColor(COLOR_CYAN);
    printf("  ╔══════════════════════════════════════╗\n");
    printf("  ║           ");
    setColor(COLOR_YELLOW);
    printf("CARA BERMAIN");
    setColor(COLOR_CYAN);
    printf("               ║\n");
    printf("  ╠══════════════════════════════════════╣\n");
    setColor(COLOR_RESET);
    printf("  ║                                      ║\n");
    setColor(COLOR_WHITE);
    printf("  ║  Kontrol:                             ║\n");
    setColor(COLOR_GREEN);
    printf("  ║    W / ↑  = Gerak Atas               ║\n");
    printf("  ║    S / ↓  = Gerak Bawah              ║\n");
    printf("  ║    A / ←  = Gerak Kiri               ║\n");
    printf("  ║    D / →  = Gerak Kanan              ║\n");
    setColor(COLOR_RED);
    printf("  ║    Q      = Keluar Game               ║\n");
    setColor(COLOR_RESET);
    printf("  ║                                      ║\n");
    setColor(COLOR_WHITE);
    printf("  ║  Simbol:                              ║\n");
    setColor(COLOR_GREEN);
    printf("  ║    P  = Posisi Player                ║\n");
    setColor(COLOR_MAGENTA);
    printf("  ║    E  = Pintu Keluar (EXIT)          ║\n");
    setColor(COLOR_BLUE);
    printf("  ║    #  = Dinding (BAHAYA!)            ║\n");
    setColor(COLOR_DIM);
    printf("  ║    .  = Jejak langkah                ║\n");
    printf("  ║    ~  = Kabut (area belum dijelajah) ║\n");
    setColor(COLOR_RESET);
    printf("  ║                                      ║\n");
    setColor(COLOR_RED);
    printf("  ║  ⚠  MENABRAK DINDING = GAME OVER!   ║\n");
    setColor(COLOR_RESET);
    printf("  ║                                      ║\n");
    setColor(COLOR_YELLOW);
    printf("  ║  Tips: Hati-hati setiap langkah!     ║\n");
    printf("  ║  Semakin sedikit langkah = skor      ║\n");
    printf("  ║  semakin tinggi!                     ║\n");
    setColor(COLOR_CYAN);
    printf("  ║                                      ║\n");
    printf("  ╚══════════════════════════════════════╝\n");
    setColor(COLOR_RESET);
    printf("\n  ");
    setColor(COLOR_DIM);
    printf("[Tekan sembarang tombol untuk kembali]");
    setColor(COLOR_RESET);
    getKeyPress();
}

void showGameOver(Player* player, bool won) {
    clearScreen();
    printf("\n\n\n");

    if (!won) {
        setColor(COLOR_RED);
        printf("    ╔═══════════════════════════════════════╗\n");
        printf("    ║                                       ║\n");
        printf("    ║      ██████╗  █████╗ ███╗   ███╗███████╗║\n");
        printf("    ║     ██╔════╝ ██╔══██╗████╗ ████║██╔════╝║\n");
        printf("    ║     ██║  ███╗███████║██╔████╔██║█████╗  ║\n");
        printf("    ║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ║\n");
        printf("    ║     ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗║\n");
        printf("    ║      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝║\n");
        printf("    ║                                       ║\n");
        printf("    ║      ██████╗ ██╗   ██╗███████╗██████╗ ║\n");
        printf("    ║     ██╔═══██╗██║   ██║██╔════╝██╔══██╗║\n");
        printf("    ║     ██║   ██║██║   ██║█████╗  ██████╔╝║\n");
        printf("    ║     ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗║\n");
        printf("    ║     ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║║\n");
        printf("    ║      ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝║\n");
        printf("    ║                                       ║\n");
        printf("    ╚═══════════════════════════════════════╝\n");
        setColor(COLOR_RESET);
        printf("\n");
        setColor(COLOR_YELLOW);
        printf("    💀 %s menabrak dinding dan tewas!\n", player->name);
        printf("\n");
        setColor(COLOR_WHITE);
        printf("    📊 Statistik:\n");
        printf("       Level    : %d\n", player->level);
        printf("       Langkah  : %d\n", player->steps);
        printf("       Skor     : %d\n", player->score);
    }

    setColor(COLOR_RESET);
    printf("\n    ");
    setColor(COLOR_DIM);
    printf("[Tekan sembarang tombol untuk kembali ke menu]");
    setColor(COLOR_RESET);
    printf("\n");
    getKeyPress();
}

void showLevelComplete(Player* player) {
    clearScreen();
    printf("\n\n");
    setColor(COLOR_GREEN);
    printf("  ╔══════════════════════════════════════╗\n");
    printf("  ║                                      ║\n");
    printf("  ║      ✨ LEVEL %d SELESAI! ✨          ║\n", player->level);
    printf("  ║                                      ║\n");
    printf("  ╠══════════════════════════════════════╣\n");
    setColor(COLOR_WHITE);
    printf("  ║                                      ║\n");
    printf("  ║   🏃 Langkah : %-5d                 ║\n", player->steps);
    printf("  ║   ⭐ Skor    : %-5d                 ║\n", player->score);
    printf("  ║   ❤️  Nyawa   : %-5d                 ║\n", player->lives);
    printf("  ║                                      ║\n");
    setColor(COLOR_GREEN);
    printf("  ╚══════════════════════════════════════╝\n");
    setColor(COLOR_RESET);
    printf("\n");
    setColor(COLOR_YELLOW);
    printf("  Bersiap ke Level %d...\n", player->level + 1);
    setColor(COLOR_DIM);
    printf("  [Tekan sembarang tombol untuk lanjut]\n");
    setColor(COLOR_RESET);
    getKeyPress();
}

void showVictoryScreen(Player* player) {
    clearScreen();
    printf("\n\n");
    setColor(COLOR_YELLOW);
    printf("    ╔═══════════════════════════════════════╗\n");
    printf("    ║                                       ║\n");
    printf("    ║    🏆  SELAMAT! KAMU MENANG!  🏆      ║\n");
    printf("    ║                                       ║\n");
    printf("    ║    Kamu berhasil melewati semua        ║\n");
    printf("    ║    labirin dengan selamat!             ║\n");
    printf("    ║                                       ║\n");
    printf("    ╠═══════════════════════════════════════╣\n");
    setColor(COLOR_WHITE);
    printf("    ║                                       ║\n");
    printf("    ║    Player  : %-20s    ║\n", player->name);
    printf("    ║    Level   : %d / %d                    ║\n", MAX_LEVELS, MAX_LEVELS);
    printf("    ║    Langkah : %-5d                     ║\n", player->steps);
    printf("    ║    Skor    : %-5d                     ║\n", player->score);
    printf("    ║                                       ║\n");
    setColor(COLOR_YELLOW);
    printf("    ╚═══════════════════════════════════════╝\n");
    setColor(COLOR_RESET);
    printf("\n    ");
    setColor(COLOR_DIM);
    printf("[Tekan sembarang tombol untuk kembali ke menu]");
    setColor(COLOR_RESET);
    printf("\n");
    getKeyPress();
}

// ==================== FUNGSI LABIRIN ====================

// Inisialisasi labirin - isi semua dengan dinding
void initLabirin(Labirin* maze, int level) {
    maze->level = level;

    // Ukuran labirin berdasarkan level (semakin tinggi semakin besar)
    // Harus ganjil agar maze generation bekerja
    switch (level) {
        case 1:
            maze->width = 21;
            maze->height = 11;
            break;
        case 2:
            maze->width = 31;
            maze->height = 15;
            break;
        case 3:
            maze->width = 41;
            maze->height = 21;
            break;
        default:
            maze->width = 21;
            maze->height = 11;
            break;
    }

    // Isi semua dengan dinding
    for (int y = 0; y < maze->height; y++) {
        for (int x = 0; x < maze->width; x++) {
            maze->map[y][x] = WALL_CHAR;
            maze->fog[y][x] = FOG_CHAR;
        }
    }

    // Generate maze menggunakan recursive backtracking
    generateMaze(maze);

    // Set posisi start (kiri atas) dan exit (kanan bawah)
    maze->start.x = 1;
    maze->start.y = 1;
    maze->map[maze->start.y][maze->start.x] = PATH_CHAR;

    // Cari posisi exit yang valid di dekat pojok kanan bawah
    maze->exitPos.x = maze->width - 2;
    maze->exitPos.y = maze->height - 2;

    // Pastikan posisi exit adalah path
    maze->map[maze->exitPos.y][maze->exitPos.x] = EXIT_CHAR;

    // Buka jalur menuju exit jika tertutup
    if (maze->map[maze->exitPos.y - 1][maze->exitPos.x] == WALL_CHAR &&
        maze->map[maze->exitPos.y][maze->exitPos.x - 1] == WALL_CHAR) {
        maze->map[maze->exitPos.y - 1][maze->exitPos.x] = PATH_CHAR;
    }
}

// Generate maze menggunakan Recursive Backtracking (DFS)
void generateMaze(Labirin* maze) {
    srand(time(NULL));
    // Mulai dari posisi (1,1)
    carvePath(maze, 1, 1);
}

// Recursive carving - membuat jalur di labirin
void carvePath(Labirin* maze, int x, int y) {
    maze->map[y][x] = PATH_CHAR;

    // Arah: 0=atas, 1=kanan, 2=bawah, 3=kiri
    int dx[] = {0, 2, 0, -2};
    int dy[] = {-2, 0, 2, 0};

    // Acak urutan arah (Fisher-Yates shuffle)
    int order[] = {0, 1, 2, 3};
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[order[i]];
        int ny = y + dy[order[i]];

        // Cek apakah posisi baru valid dan masih dinding
        if (nx > 0 && nx < maze->width - 1 && ny > 0 && ny < maze->height - 1) {
            if (maze->map[ny][nx] == WALL_CHAR) {
                // Buka dinding antara posisi saat ini dan posisi baru
                maze->map[y + dy[order[i]] / 2][x + dx[order[i]] / 2] = PATH_CHAR;
                carvePath(maze, nx, ny);
            }
        }
    }
}

// Update fog of war berdasarkan posisi player
void updateFog(Labirin* maze, Position playerPos, int radius) {
    for (int dy = -radius; dy <= radius; dy++) {
        for (int dx = -radius; dx <= radius; dx++) {
            int nx = playerPos.x + dx;
            int ny = playerPos.y + dy;
            if (nx >= 0 && nx < maze->width && ny >= 0 && ny < maze->height) {
                // Hanya reveal dalam radius lingkaran
                if (dx * dx + dy * dy <= radius * radius) {
                    maze->fog[ny][nx] = ' '; // Revealed
                }
            }
        }
    }
}

// Cetak labirin ke layar
void printLabirin(Game* game) {
    Labirin* maze = &game->maze;
    Player* player = &game->player;

    clearScreen();

    // Header info
    setColor(COLOR_CYAN);
    printf("  ╔══════════════════════════════════════════════╗\n");
    printf("  ║  ");
    setColor(COLOR_YELLOW);
    printf("LABIRIN");
    setColor(COLOR_CYAN);
    printf("  │ ");
    setColor(COLOR_WHITE);
    printf("Level: %d", player->level);
    setColor(COLOR_CYAN);
    printf("  │ ");
    setColor(COLOR_GREEN);
    printf("Skor: %d", player->score);
    setColor(COLOR_CYAN);
    printf("  │ ");
    setColor(COLOR_MAGENTA);
    printf("Langkah: %d", player->steps);
    setColor(COLOR_CYAN);
    printf("  ║\n");
    printf("  ╠══════════════════════════════════════════════╣\n");
    printf("  ║  ");
    setColor(COLOR_RED);
    printf("⚠ Menabrak dinding (#) = GAME OVER!");
    setColor(COLOR_CYAN);
    printf("          ║\n");
    printf("  ╚══════════════════════════════════════════════╝\n");
    setColor(COLOR_RESET);
    printf("\n");

    // Update fog of war
    if (game->fogEnabled) {
        updateFog(maze, player->pos, game->fogRadius);
    }

    // Cetak peta
    for (int y = 0; y < maze->height; y++) {
        printf("    ");
        for (int x = 0; x < maze->width; x++) {
            // Cek fog of war
            if (game->fogEnabled && maze->fog[y][x] == FOG_CHAR) {
                setColor(COLOR_DIM);
                printf("%c", FOG_CHAR);
                setColor(COLOR_RESET);
                continue;
            }

            if (x == player->pos.x && y == player->pos.y) {
                // Player
                setColor(COLOR_GREEN);
                printf("%c", PLAYER_CHAR);
            } else if (maze->map[y][x] == EXIT_CHAR) {
                // Exit
                setColor(COLOR_MAGENTA);
                printf("%c", EXIT_CHAR);
            } else if (maze->map[y][x] == WALL_CHAR) {
                // Dinding
                setColor(COLOR_BLUE);
                printf("%c", WALL_CHAR);
            } else if (maze->map[y][x] == TRAIL_CHAR) {
                // Jejak
                setColor(COLOR_DIM);
                printf("%c", TRAIL_CHAR);
            } else {
                // Jalur kosong
                setColor(COLOR_RESET);
                printf(" ");
            }
            setColor(COLOR_RESET);
        }
        printf("\n");
    }

    // Footer kontrol
    printf("\n");
    setColor(COLOR_DIM);
    printf("    [W] Atas  [S] Bawah  [A] Kiri  [D] Kanan  [Q] Keluar\n");
    setColor(COLOR_RESET);
}

// ==================== FUNGSI GAME ====================

void initGame(Game* game) {
    game->isRunning = true;
    game->fogEnabled = true;
    game->fogRadius = 3;
}

void initPlayer(Player* player, const char* name) {
    strncpy(player->name, name, 49);
    player->name[49] = '\0';
    player->lives = 1;
    player->score = 0;
    player->steps = 0;
    player->level = 1;
    player->isAlive = true;
}

// Gerakan player - cek tabrakan dengan dinding
void movePlayer(Game* game, char direction) {
    int newX = game->player.pos.x;
    int newY = game->player.pos.y;

    switch (direction) {
        case 'w': case 'W':
            newY--;
            break;
        case 's': case 'S':
            newY++;
            break;
        case 'a': case 'A':
            newX--;
            break;
        case 'd': case 'D':
            newX++;
            break;
        default:
            return; // Input tidak valid, abaikan
    }

    // Cek batas peta
    if (newX < 0 || newX >= game->maze.width || newY < 0 || newY >= game->maze.height) {
        return; // Di luar peta, abaikan
    }

    // Cek apakah menabrak dinding -> GAME OVER!
    if (checkCollision(&game->maze, newX, newY)) {
        game->player.isAlive = false;
        game->isRunning = false;

        // Tampilkan animasi tabrakan
        clearScreen();
        printf("\n\n\n");
        setColor(COLOR_BG_RED);
        setColor(COLOR_WHITE);
        printf("                                          \n");
        printf("    💥 BRAAAKKK!! Kamu menabrak dinding!   \n");
        printf("                                          \n");
        setColor(COLOR_RESET);
        sleepMs(1500);
        return;
    }

    // Cek apakah mencapai exit
    if (checkExit(&game->maze, newX, newY)) {
        // Bonus skor berdasarkan level
        int bonus = 1000 * game->player.level;
        game->player.score += bonus;

        if (game->player.level >= MAX_LEVELS) {
            // Menang! Semua level selesai
            game->isRunning = false;
            showVictoryScreen(&game->player);
            return;
        } else {
            // Level berikutnya
            showLevelComplete(&game->player);
            nextLevel(game);
            return;
        }
    }

    // Tandai posisi lama sebagai jejak
    game->maze.map[game->player.pos.y][game->player.pos.x] = TRAIL_CHAR;

    // Update posisi player
    game->player.pos.x = newX;
    game->player.pos.y = newY;
    game->player.steps++;
    game->player.score += 10;
}

// Cek apakah posisi adalah dinding
bool checkCollision(Labirin* maze, int x, int y) {
    return maze->map[y][x] == WALL_CHAR;
}

// Cek apakah posisi adalah exit
bool checkExit(Labirin* maze, int x, int y) {
    return maze->map[y][x] == EXIT_CHAR;
}

// Pindah ke level berikutnya
void nextLevel(Game* game) {
    game->player.level++;

    // Fog radius mengecil seiring level naik
    game->fogRadius = 4 - game->player.level;
    if (game->fogRadius < 2) game->fogRadius = 2;

    // Generate labirin baru
    initLabirin(&game->maze, game->player.level);

    // Reset posisi player ke start
    game->player.pos = game->maze.start;
}

// Main game loop
void gameLoop(Game* game) {
    while (game->isRunning) {
        printLabirin(game);

        char input = getKeyPress();

        // Handle arrow keys (escape sequences)
        if (input == 27) { // ESC
            char seq1 = getKeyPress();
            if (seq1 == '[') {
                char seq2 = getKeyPress();
                switch (seq2) {
                    case 'A': input = 'w'; break; // Up
                    case 'B': input = 's'; break; // Down
                    case 'C': input = 'd'; break; // Right
                    case 'D': input = 'a'; break; // Left
                    default: continue;
                }
            } else {
                continue;
            }
        }

        if (input == 'q' || input == 'Q') {
            game->isRunning = false;
            return;
        }

        movePlayer(game, input);

        if (!game->player.isAlive) {
            showGameOver(&game->player, false);
            return;
        }
    }
}

// Mulai game baru
void startGame() {
    Game game;
    char playerName[50];

    clearScreen();
    printf("\n");
    setColor(COLOR_CYAN);
    printf("  ╔══════════════════════════════════════╗\n");
    printf("  ║          ");
    setColor(COLOR_YELLOW);
    printf("PEMAIN BARU");
    setColor(COLOR_CYAN);
    printf("                ║\n");
    printf("  ╚══════════════════════════════════════╝\n");
    setColor(COLOR_RESET);
    printf("\n  Masukkan nama: ");
    setColor(COLOR_GREEN);

    // Baca nama player
    scanf("%49s", playerName);
    // Flush input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    setColor(COLOR_RESET);

    // Inisialisasi game
    initGame(&game);
    initPlayer(&game.player, playerName);
    initLabirin(&game.maze, 1);

    // Set posisi awal player
    game.player.pos = game.maze.start;

    // Mulai game loop
    gameLoop(&game);
}
