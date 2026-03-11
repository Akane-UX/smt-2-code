#include <stdio.h>

int main(){
    float pil;
    int bil1, bil2, hasil;

    printf("Pilih Operaasi : \n");
    printf("1) Penjumlahan (+)\n");
    printf("2) Pengurangan (-)\n");
    printf("3) Perkalian (�)\n");
    printf("4) Pembagian (/)\n");

    printf("\nMasukan Pilihan > ");
    scanf("%f", & pil);

    printf("Masukan Angka Pertama > ");
    scanf("%i, > ", & bil1);
    
    printf("Masukan Angka Kedua > ");
    scanf("%i, > ", & bil2);

    if (pil == 1){
        hasil = bil1 + bil2;
    }
    else if (pil == 2){
        hasil = bil1 - bil2;
    }
    else if (pil == 3){
        hasil = bil1 * bil2;
    }
    else if (pil == 4){
        hasil = bil1 / bil2;
        
        if (bil1||bil2 == 0){
            printf("Bilangan tidak bisa dibagi dengan bilangan 0");
            return 0;
        }
    }    printf("Hasilnya = %i", hasil);

    return 0;
}
