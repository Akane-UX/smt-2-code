#include <stdio.h>
#include <iostream>
#define MAX 8

using namespace std;

struct Queue{
    int data[MAX];
    int head;
    int tail;
};

void menu();