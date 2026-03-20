#include <iostream>
#include <conio.h>
#define Max 21
using namespace std;

typedef struct
{int TI[Max-1];
int Neff; 
} TabInt;

void MakeEmpty(TabInt *T);
void BacaIsi(TabInt *T);
void TulisIsi(TabInt T);
int LastIdx(TabInt T);
