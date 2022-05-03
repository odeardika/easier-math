#include <stdio.h>

int main(){
    printf("Menu :\n"
           "1. Kalkulator\n"
           "2. Bangun Datar\n"
           "3. Bangun Ruang\n");
    char pilihan;
    printf("Masukan Pilihan : ");
    scanf("%c");
    switch (pilihan)
    {
    case '1':
        //kalkulator
        break;
    case '2':
        //Bangun Datar
        break;
    case '3' :
        //Bangun Ruang
        break;
    default:
        break;
    }
}