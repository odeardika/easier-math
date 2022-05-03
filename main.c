#include <stdio.h>

double kalkulator(){
    char pil;
    double awal, penambah;
    printf("Masukan Angka Pertama : ");
    scanf("%lf", &awal);
    fflush(stdin);
    printf("Masukan Pilihan ( + - * / ) : ");
    scanf("%c", &pil);
    printf("Masukan Angka Penambah : ");
    scanf("%lf", &penambah);

    if(pil == '+') return awal + penambah;
    if(pil == '-') return awal - penambah;
    if(pil == '*') return awal * penambah;
    if(pil == '/') return awal / penambah;
}

int main(){
    double hasil;
    printf("Menu :\n"
           "1. Kalkulator\n"
           "2. Bangun Datar\n"
           "3. Bangun Ruang\n");
    char pilihan;
    printf("Masukan Pilihan : ");
    scanf("%c", &pilihan);
    switch (pilihan)
    {
    case '1':
        hasil = kalkulator();
        printf("Hasil : %.2lf", hasil);
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
    return 0;
}

