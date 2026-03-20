#include <stdio.h>

int main(){
    int nilai;
    char nama[50];

    printf("Masukan Nama \n > ");
    scanf("%s", nama);

    printf("Masukan Nilai \n > ");
    scanf("%d", &nilai);

    if (nilai >= 7 ){
        printf("%s, Nilai %d tuntas dengan predikat A", nama, nilai);
    }
    else if (nilai >= 6 ){
        printf("%s, Nilai %d tuntas dengan predikat B", nama, nilai);
    }
    else if (nilai >= 5 ){
        printf("%s, Nilai %d tuntas dengan predikat C", nama, nilai);
    }
    else {
        printf("%s, Nilai %d tidak tuntas dengan predikat D", nama, nilai);
    }
    
    return 0;
}