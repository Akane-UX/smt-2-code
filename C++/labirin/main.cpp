/**
 * ============================================
 *  LABIRIN GAME - Main Entry Point
 *  
 *  Game labirin CLI berbasis C/C++
 *  Navigasi labirin dan temukan jalan keluar!
 *  Hati-hati: Menabrak dinding = GAME OVER!
 *
 *  Fitur:
 *  - 3 Level dengan tingkat kesulitan berbeda
 *  - Maze generation otomatis (Recursive Backtracking)
 *  - Fog of War (area gelap belum dijelajah)
 *  - Sistem skor berdasarkan langkah
 *  - Warna terminal ANSI
 *  - Kontrol WASD dan Arrow Keys
 *
 *  Compile: g++ main.cpp source.cpp -o labirin
 *  Run:     ./labirin
 * ============================================
 */

#include "header.h"

int main() {
    char choice;

    // Tampilkan splash screen
    showSplashScreen();

    while (true) {
        showMainMenu();
        choice = getKeyPress();

        switch (choice) {
            case '1':
                startGame();
                break;
            case '2':
                showHowToPlay();
                break;
            case '3':
                clearScreen();
                printf("\n");
                setColor(COLOR_CYAN);
                printf("  ╔══════════════════════════════════════╗\n");
                printf("  ║                                      ║\n");
                printf("  ║  ");
                setColor(COLOR_YELLOW);
                printf("Terima kasih sudah bermain!");
                setColor(COLOR_CYAN);
                printf("       ║\n");
                printf("  ║  ");
                setColor(COLOR_DIM);
                printf("Sampai jumpa di labirin lain...");
                setColor(COLOR_CYAN);
                printf("   ║\n");
                printf("  ║                                      ║\n");
                printf("  ╚══════════════════════════════════════╝\n");
                setColor(COLOR_RESET);
                printf("\n");
                return 0;
            default:
                break;
        }
    }

    return 0;
}
