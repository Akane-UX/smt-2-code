#include<iostream>
#define MAX 10

using namespace std;

typedef struct{
    int data[MAX];
    int head;
    int tail;
}CircularQueue;

void menu();