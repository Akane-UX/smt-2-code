/**
 * ============================================
 *  LABIRIN GAME - Header File
 *  Game labirin CLI berbasis C/C++
 *  Jika player menabrak dinding = GAME OVER!
 * ============================================
 */

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <termios.h>
#include <unistd.h>

using namespace std;

// ==================== KONSTANTA ====================
#define MAX_WIDTH  41
#define MAX_HEIGHT 21
#define MAX_LEVELS 3

// Karakter peta
#define WALL_CHAR   '#'
#define PATH_CHAR   ' '
#define PLAYER_CHAR 'P'
#define EXIT_CHAR   'E'
#define TRAIL_CHAR  '.'
#define FOG_CHAR    '~'

// Warna ANSI
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_WHITE   "\033[1;37m"
#define COLOR_BG_RED  "\033[41m"
#define COLOR_BG_GREEN "\033[42m"
#define COLOR_BG_BLUE  "\033[44m"
#define COLOR_DIM     "\033[2m"
#define COLOR_BOLD    "\033[1m"

// ==================== STRUCT ====================

// Posisi di dalam labirin
struct Position {
    int x;
    int y;
};

// Data player
struct Player {
    Position pos;
    int lives;
    int score;
    int steps;
    int level;
    char name[50];
    bool isAlive;
};

// Data labirin
struct Labirin {
    char map[MAX_HEIGHT][MAX_WIDTH];
    char fog[MAX_HEIGHT][MAX_WIDTH];  // fog of war
    int width;
    int height;
    Position start;
    Position exitPos;
    int level;
};

// Data game
struct Game {
    Player player;
    Labirin maze;
    bool isRunning;
    bool fogEnabled;
    int fogRadius;
    double startTime;
};

// ==================== FUNGSI UTILITAS ====================
void clearScreen();
char getKeyPress();
void setColor(const char* color);
void printCentered(const char* text, int width);
void sleepMs(int milliseconds);

// ==================== FUNGSI MENU ====================
void showSplashScreen();
void showMainMenu();
void showHowToPlay();
void showGameOver(Player* player, bool won);
void showLevelComplete(Player* player);
void showVictoryScreen(Player* player);

// ==================== FUNGSI LABIRIN ====================
void initLabirin(Labirin* maze, int level);
void generateMaze(Labirin* maze);
void carvePath(Labirin* maze, int x, int y);
void updateFog(Labirin* maze, Position playerPos, int radius);
void printLabirin(Game* game);

// ==================== FUNGSI GAME ====================
void initGame(Game* game);
void initPlayer(Player* player, const char* name);
void movePlayer(Game* game, char direction);
bool checkCollision(Labirin* maze, int x, int y);
bool checkExit(Labirin* maze, int x, int y);
void gameLoop(Game* game);
void nextLevel(Game* game);
void startGame();

#endif // HEADER_H
