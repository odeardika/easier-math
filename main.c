#include <stdio.h>

double kalkulator();
void MBDatar(); //Menu Bangun Datar
void MBRuang(); //Menu Bangun Ruang

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
        MBDatar();
        break;
    case '3' :
        MBRuang();
        break;
    default:
        break;
    }
    return 0;
}

double kalkulator(){
    char pil;
    double awal, penambah;
    printf("Masukan Angka Pertama : ");
    scanf("%lf", &awal);
    while(getchar() != '\n');
    printf("Masukan Pilihan ( + - * / ) : ");
    scanf("%c", &pil);
    printf("Masukan Angka Penambah : ");
    scanf("%lf", &penambah);

    if(pil == '+') return awal + penambah;
    if(pil == '-') return awal - penambah;
    if(pil == '*') return awal * penambah;
    if(pil == '/') return awal / penambah;
}

void MBDatar(){
    printf("Menu :\n"
           "1. Persegi\n"
           "2. Persegi Panjang\n"
           "3. Segitiga\n"
           "4. Jajar Genjang\n"
           "5. Trapesium\n"
           "6. Belah Ketupat\n"
           "7. Layang - layang\n"
           "8. Lingkaran\n");
}

void MBRuang(){
    printf("Menu :\n"
           "1. Kubus\n"
           "2. Balok\n"
           "3. Prisma\n"
           "4. Limas\n"
           "5. Tabung\n"
           "6. Kerucut\n"
           "7.Bola\n");
}

