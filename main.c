#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void kalkulator(); 
double rumus_datar();
double rumus_ruang();
int menu_bangun_datar(); //Menu Bangun Datar
int menu_bangun_ruang(); //Menu Bangun Ruang
int matriks();
void history();

int main(){
    double hasil;
    system("cls");
    printf("\t ------------------------ \n"
           "\t|    ~SELAMAT DATANG~    |\n"
           "\t|       DI PROGRAM       |\n"
           "\t|      EASIER  MATH      |\n"
           "\t ------------------------ \n");
    printf("\nM E N U:\n"
           "1. Kalkulator\n"
           "2. Bangun Datar\n"
           "3. Bangun Ruang\n"
           "4. Matriks\n"
           "5. Riwayat\n"
           "6. Keluar\n");
    char pilihan,kal,ulang;
    printf("Pilihan: ");
    scanf("%c", &pilihan);
    while(getchar() != '\n'); // menghilangkan enter otomatis
    switch (pilihan)
    {
    case '1':
        printf("Pilih Kalkulator\n"
               "1. Kalkulator\n"
               "2. Kalkulator Ekstra\n"
               "Pilihan : ");
        scanf("%c",&kal);
        while(getchar() != '\n');
        if(kal == '1')kalkulator(1);
        if(kal == '2')kalkulator(2);
        break;
    case '2':
        menu_bangun_datar();
        break;
    case '3' :
        menu_bangun_ruang();
        break;
    case '4' :
        matriks();
        break;
    case '5' :
        history();
        break;
    case '6' :
        return 0;
    default:
        return main();
    }
    loop:
        printf("\nApakah Anda ingin mengulang? [y/n]: "); scanf(" %c", &ulang); getchar();
        if(ulang == 'y' || ulang == 'Y') return main();
        else if(ulang == 'n' || ulang == 'N'){
            printf("\nTerima kasih telah menggunakan program kami^^");
            return 0;
        }else goto loop;
}

void kalkulator(int a){
    char pil;
    double awal, penambah, hasil;
    if(a == 1) //kalkulator biasa
    {
        printf("Menu Kalkulator ( + - * / = ) : \n");
    }
    if(a == 2) //kalkulator ekstra
    {
        printf("Menu Kalkulator Ekstra :\n"
           "===================================================================\n"
           "|   + -> pertambah  |   * -> perkalian    |   ^ -> perpangkatan   |\n"
           "|   - -> pengurang  |   / -> perbagian    |   v -> pengakaran     |\n"
           "|   s -> sinus(sin) |   c -> kosinus(cos) |   t -> tangen(tan)    |\n"
           "|   S -> cosecan    |   C -> secan        |   T -> cotangen       |\n"
           "|   % -> persen     |   l -> logaritma    |   = -> hasil          |\n"
           "===================================================================\n");
    }
    FILE *Fptr = fopen ("History_Kalkulator.txt", "a");
    fprintf(Fptr, "===========================");
    printf("Masukan Angka Pertama : ");
    scanf("%lf", &awal);
    while (1) // kondisi = 1 supaya selalu looping
    {
        printf("Masukan Pilihan : ");
        while(getchar() != '\n');
        scanf("%c", &pil);
        if(pil == '+')
        {
            printf("Masukan Angka Penambah : ");
            scanf("%lf", &penambah);
            hasil = awal + penambah;
            fprintf(Fptr, "\n %.2lf + %.2lf = %.2lf",awal, penambah,hasil);
        } 
        if(pil == '-')
        {
            printf("Masukan Angka Pengurangan : ");
            scanf("%lf", &penambah);
            hasil = awal - penambah;
            fprintf(Fptr, "\n %.2lf - %.2lf = %.2lf",awal,penambah,hasil);
        }
        if(pil == '*')
        {
            printf("Masukan Angka Pengalian : ");
            scanf("%lf", &penambah);
            hasil = awal * penambah;
            fprintf(Fptr, "\n %.2lf x %.2lf = %.2lf",awal, penambah,hasil);
        }
        if(pil == '/')
        {
            printf("Masukan Angka Pembagi : ");
            scanf("%lf", &penambah);
            hasil = awal / penambah;
            fprintf(Fptr, "\n %.2lf : %.2lf = %.2lf",awal, penambah,hasil);
        }
        if(pil == '^')
        {
            printf("Mau Dipangkatkan berapa : ");
            scanf("%lf", &penambah);
            hasil = pow(awal,penambah);
            fprintf(Fptr, "\n %.2lf^%.2lf = %.2lf",awal, penambah,hasil);
        }
        if(pil == 'v')
        {
            hasil = sqrt(awal);
            fprintf(Fptr, "\n  ______");
            fprintf(Fptr, "\n\\/%.2lf   = %.2lf", awal,hasil);
            
        }
        if(pil == 's')
        {
            hasil = sin(awal);
            fprintf(Fptr, "\nsin(%.2lf) = %.2lf", awal,hasil);
        }
        if(pil == 'c')
        {
            hasil = cos(awal);
            fprintf(Fptr, "\ncos(%.2lf) = %.2lf", awal,hasil);
        }
        if(pil == 't')
        {
            hasil = tan(awal);
            fprintf(Fptr, "\ntan(%.2lf) = %.2lf", awal,hasil);
        }
        if(pil == 'S')
        {
            hasil = asin(awal);
            fprintf(Fptr, "\n-sin(%.2lf) = %.2lf", awal,hasil);
        }
        if(pil == 'C')
        {
            hasil = acos(awal);
            fprintf(Fptr, "\n-cos(%.2lf) = %.2lf", awal,hasil);
        }
        if(pil == 'T')
        {
            hasil = atan(awal);
            fprintf(Fptr, "\n-tan(%.2lf) = %.2lf", awal,hasil);
        }
        if(pil == '%')
        {
            printf("Berapa persen : ");
            scanf("%lf", &penambah);
            hasil = awal * (penambah/100);
            fprintf(Fptr, "\n%.2lf * %.2lf% = %.2lf", awal,penambah,hasil);
        }
        if(pil == 'l')
        {
            hasil = log(awal);
            fprintf(Fptr, "\nlog(%.2lf) = %.2lf", awal,hasil);
        }
        if(pil == '=')
        {
            goto end;
        }
    printf("%.2lf\n", hasil);
    awal = hasil;
    }
    end :
    fprintf(Fptr, "\n===========================\n");
    fclose(Fptr);
    printf("%.2lf\n", awal);

}
double rumus_datar(int pil, double a, double b, double c, double d){
    if(pil == 1) return pow(a, 1.0/2.0); // luas menjadi sisi
    if(pil == 2) return a / 4; //keliling menjadi sisi
    if(pil == 3) return (a + b) * 2; //sisi menjadi keliling
    if(pil == 4) return a * b; //sisi/alas & tinggi menjadi luas
    if(pil == 5) return a / b; // mencari panjang/lebar/tinggi dari luas
    if(pil == 6) return ( a / 2 ) - b; //mencari panjang/lebar dari keliling
    if(pil == 7) return a + b + c; //keliling segitiga
    if(pil == 8) return a / 3; //keliling ke sisi (segitiga sama sisi)
    if(pil == 9) return a - (b + c); //keliling ke sisi (segitiga siku-siku)
    if(pil == 10) return (a * 2) / b; //luas ke sisi & mencari salah satu diagonal belah ketupat dan layang-layang
    if(pil == 11) return (a * b) / 2; //luas segitiga, belah ketupat, dan layang-layang
    if(pil == 12) return (a - 2 * b) / 2; //mencari alas/sisi miring dari keliling jajar genjang dan panjang diagonal dari keliling layang-layang
    if(pil == 13) return a - b - c - d; //mencari sisi dari keliling trapesium
	if(pil == 14) return a + b + c + d; //mencari keliling trapesium
	if(pil == 15) return 2 * a / (b + c); //mencari tinggi trapesium
	if(pil == 16) return (a + b) * c / 2; //luas trapesium
	if(pil == 17) return a * 4; //keliling belah ketupat
	if(pil == 18) return a / 2; //mencari jari-jari lingakran dari diameter
	if(pil == 19) return a * 2; //mencari diameter lingkaran dari jari-jari
	if(pil == 20) return 2 * 3.14 * a; //keliling lingkaran dengan jari-jari
	if(pil == 21) return 3.14 * a; //keliling lingkaran dengan diameter
	if(pil == 22) return 3.14 * pow(a,2); //luas lingkaran dengan jari-jari
	if(pil == 23) return 3.14 * pow(a,2) / 4; //luas lingkaran dengan diameter
}
int menu_bangun_datar(){
    system("cls");
    char pilihan;
	int segitiga;
    double sisi[4] = {0,0,0,0},luas = 0,keliling = 0,tinggi,jari,diameter;
    printf("|---- Selamat Datang di Kalkulator Bangun Datar ----|\n\n"
           "Menu :\n"
           "1. Persegi                          5. Trapesium\n"
           "2. Persegi Panjang                  6. Belah Ketupat\n"
           "3. Segitiga                         7. Layang-layang\n"
           "4. Jajar Genjang                    8. Lingkaran\n"
           "                     9. Kembali\n"
           "Pilihan: ");
    scanf("%c",&pilihan);
    while(getchar() != '\n');
    switch (pilihan)
    {
    case '1':
        system("cls");
        printf("|---- Selamat Datang di Kalkulator Persegi ----|\n\n");
        printf("Masukan Data : \n");
        printf("Masukan Sisi = ");scanf("%lf", &sisi[0]);
        printf("Masukan Keliling = ");scanf("%lf", &keliling);
        printf("Masukan Luas = ");scanf("%lf", &luas);
        printf("\n");
        if(sisi[0] == 0)
        {
            if(luas != 0)
            {
                sisi[0] = rumus_datar(1,luas,luas,0,0);
                printf("Diketahui Luas = %.2lf\n", luas);
                printf("        ______\n");
                printf("Sisi = / %.2lf\n", luas);
                printf("Sisi = %.2lf\n\n", sisi[0]);
            }
            if (keliling != 0)
            {
                sisi[0] = rumus_datar(2,keliling, keliling,0,0);
                printf("Diketahui Keliling = %.2lf\n", keliling);
                printf("Sisi = %.2lf / 4 \n",keliling);
                printf("Sisi = %.2lf\n\n", sisi[0]);
            }
        }
        if(keliling == 0)
        {
            keliling = rumus_datar(3,sisi[0],sisi[0],0,0);
            printf("Diketahui Sisi = %.2lf\n", sisi[0]);
            printf("Keliling = %.2lf * 4\n", sisi[0]);
            printf("Keliling = %.2lf\n\n", keliling);
        }
        if(luas == 0)
        {
            luas = rumus_datar(4,sisi[0],sisi[0],0,0);
            printf("Diketahui Sisi = %.2lf\n", sisi[0]);
            printf("Luas = %.2lf * %.2lf\n", sisi[0], sisi[0]);
            printf("Luas = %.2lf\n\n", luas);
        }
        printf("Data dari Persegi :\n");
        printf("Sisi dari Persegi = %.2lf\n", sisi[0]);
        printf("Keliling dari Persegi = %.2lf\n", keliling);
        printf("Luas dari Persegi = %.2lf\n", luas);
        system("pause");
        break;
    case '2':
        system("cls");
        printf("           |---- Selamat Datang di Kalkulator Persegi Panjang ----|\n\n");
        printf("Masukan Data : \n");
        printf("Masukan Panjang = ");scanf("%lf", &sisi[0]);
        printf("Masukan Lebar = ");scanf("%lf", &sisi[1]);
        printf("Masukan Keliling = ");scanf("%lf", &keliling);
        printf("Masukan Luas = ");scanf("%lf", &luas);
        printf("\n");
        if(sisi[0] == 0)
        {
            if(sisi[1] != 0)
            {
                if (keliling != 0)
                {
                    sisi[0] = rumus_datar(6,keliling,sisi[1],0,0);
                    printf("Diketahui Lebar = %.2lf\n", sisi[1]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Panjang = (%.2lf / 2) - %.2lf\n", keliling,sisi[1]);
                    printf("Panjang = %.2lf\n\n", sisi[0]);
                }
                if (luas != 0)
                {
                    sisi[0] = rumus_datar(5,luas,sisi[1],0,0);
                    printf("Diketahui Lebar = %.2lf\n", sisi[1]);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Panjang = %.2lf / %.2lf\n", luas,sisi[1]);
                    printf("Panjang = %.2lf\n\n", sisi[0]);
                }  
            }
        }
        if(sisi[1] == 0)
        {
            if(sisi[0] != 0)
            {
                if (keliling != 0)
                {
                    sisi[1] = rumus_datar(6,keliling,sisi[0],0,0);
                    printf("Diketahui Panjang = %.2lf\n", sisi[0]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Lebar = (%.2lf / 2) - %.2lf\n", keliling,sisi[0]);
                    printf("Lebar = %.2lf\n\n", sisi[1]);
                }
                if (luas != 0)
                {
                    sisi[1] = rumus_datar(5,luas,sisi[0],0,0);
                    printf("Diketahui Panjang = %.2lf\n", sisi[0]);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Lebar = %.2lf / %.2lf\n", luas,sisi[0]);
                    printf("Lebar = %.2lf\n\n", sisi[1]);
                }  
            }
        }
        if(keliling == 0)
        {
            keliling = rumus_datar(3,sisi[1],sisi[0],0,0);
            printf("Diketahui Panjang = %.2lf\n", sisi[0]);
            printf("Diketahui Lebar = %.2lf\n", sisi[1]);
            printf("keliling = (%.2lf + %.2lf) * 2\n", sisi[0],sisi[1]);
            printf("Keliling = %.2lf\n\n", keliling);
        }
        if(luas == 0)
        {
            luas = rumus_datar(4,sisi[1],sisi[0],0,0);
            printf("Diketahui Panjang = %.2lf\n", sisi[0]);
            printf("Diketahui Lebar = %.2lf\n", sisi[1]);
            printf("Luas = %.2lf * %.2lf\n", sisi[0],sisi[1]);
            printf("Luas = %.2lf\n\n", luas);
        }
        printf("Data dari Persegi Panjang :\n");
        printf("Panjang dari Persegi Panjang = %.2lf\n", sisi[0]);
        printf("Lebar dari Persegi Panjang = %.2lf\n", sisi[1]);
        printf("Keliling dari Persegi Panjang = %.2lf\n", keliling);
        printf("Luas dari Persegi Panjang = %.2lf\n", luas);
        system("pause");
        break;
    case '3':
        system("cls");
        printf("             |---- Selamat Datang di Kalkulator Segitiga ----|\n\n"
               "Jenis Segitiga yang Tersedia\n1. Segitiga Siku-siku\n2. Segitiga Sama Kaki\n3. Segitiga Sama Sisi\n");
        printf("Masukan Jenis Segitiga No Berapa: ");scanf("%d", &segitiga);
        printf("Masukan Data : \n");
        if(segitiga == 1){
            printf("Masukan Tinggi = ");scanf("%lf", &sisi[0]);
            printf("Masukan Alas = ");scanf("%lf", &sisi[1]);
            printf("Masukan Sisi Miring = ");scanf("%lf",&sisi[2]);
        }
        if(segitiga == 2){
            printf("Masukan Tinggi = ");scanf("%lf",&sisi[0]);
            printf("Masukan Alas = ");scanf("%lf", &sisi[1]); 
            printf("Masukan Sisi Miring = ");scanf("%lf",&sisi[2]);
        }
        if(segitiga == 3){
            printf("Masukan Sisi = ");scanf("%lf", &sisi[0]);
        }
        printf("Masukan Keliling = ");scanf("%lf", &keliling);
        printf("Masukan Luas = ");scanf("%lf", &luas);
        printf("\n");
        if(segitiga == 1)
        {
            if(sisi[0] == 0)
            {
                if(keliling != 0 && sisi[2] != 0)
                {
                    sisi[0] = rumus_datar(9,keliling,sisi[1],sisi[2],0);
                    printf("Diketahui Alas = %.2lf\n", sisi[1]);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Tinggi = %.2lf - (%.2lf + %.2lf)\n", keliling,sisi[1],sisi[2]);
                    printf("Tinggi = %.2lf\n\n", sisi[0]);
                }
                if(luas != 0)
                {
                    sisi[0] = rumus_datar(10,luas,sisi[1],0,0);
                    printf("Diketahui Alas = %.2lf\n", sisi[1]);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Tinggi = (%.2lf * 2) / %.2lf\n", luas,sisi[1]);
                    printf("Tinggi = %.2lf\n\n", sisi[0]);
                }
            }
            if(sisi[1] == 0)
            {
                if(keliling != 0 && sisi[2] != 0)
                {
                    sisi[1] = rumus_datar(9,keliling,sisi[0],sisi[2],0);
                    printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Alas = %.2lf - (%.2lf + %.2lf)\n", keliling,sisi[0],sisi[2]);
                    printf("Alas = %.2lf\n\n", sisi[1]);
                }
                if(luas != 0)
                {
                    sisi[1] = rumus_datar(10,luas,sisi[0],0,0);
                    printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Alas = (%.2lf * 2) / %.2lf\n", luas,sisi[0]);
                    printf("Alas = %.2lf\n\n", sisi[1]);
                }
            }
            if(sisi[2] == 0)
            {
                if(keliling != 0)
                {
                    sisi[2] = rumus_datar(9,keliling,sisi[0],sisi[1],0);
                    printf("Diketahui Alas = %.2lf\n", sisi[1]);
                    printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Sisi Miring = %.2lf - (%.2lf + %.2lf)\n", keliling,sisi[0],sisi[1]);
                    printf("Sisi Miring = %.2lf\n\n", sisi[2]);
                }
            }
            if(keliling == 0)
            {
                keliling = rumus_datar(7,sisi[0],sisi[1],sisi[2],0);
                printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                printf("Diketahui Alas = %.2lf\n", sisi[1]);
                printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                printf("keliling = %.2lf + %.2lf + %.2lf\n", sisi[0],sisi[1],sisi[2]);
                printf("Keliling = %.2lf\n\n", keliling);
            }
            if (luas == 0)
            {
                luas = rumus_datar(11,sisi[0],sisi[1],0,0);
                printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                printf("Diketahui Alas = %.2lf\n", sisi[1]);
                printf("Luas = (%.2lf * %.2lf) / 2\n", sisi[0],sisi[1]);
                printf("Luas = %.2lf\n\n", luas);
            }
            printf("Tinggi Segitiga = %.2lf\n", sisi[0]);
            printf("Alas Segitiga = %.2lf\n", sisi[1]);
            printf("Sisi Miring Segitiga = %.2lf\n", sisi[2]);
        }
        if(segitiga == 2)
        {
            if(sisi[0] == 0)
            {
                if(luas != 0)
                {
                    sisi[0] = rumus_datar(10,luas,sisi[1],0,0);
                    printf("Diketahui Alas = %.2lf\n", sisi[1]);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Tinggi = (%.2lf * 2) / %.2lf\n", luas,sisi[1]);
                    printf("Tinggi = %.2lf\n\n", sisi[0]);    
                }
            }
            if(sisi[1] == 0)
            {
                if(keliling != 0)
                {
                    sisi[1] = rumus_datar(9,keliling,sisi[0],sisi[0],0);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Alas = %.2lf - (%.2lf * 2)\n", keliling,sisi[0]);
                    printf("Alas = %.2lf\n\n", sisi[1]);
                }
                if(luas != 0)
                {
                    sisi[1] = rumus_datar(10,luas,sisi[0],0,0);
                    printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Alas = (%.2lf * 2) / %.2lf\n", luas,sisi[0]);
                    printf("Alas = %.2lf\n\n", sisi[1]);
                }
            }
            if (sisi[2] == 0)
            {
                if (keliling != 0)
                {
                    sisi[2] = rumus_datar(9,keliling,sisi[1],0,0)/2;
                    printf("Diketahui Alas = %.2lf\n", sisi[1]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Sisi Miring = (%.2lf - %.2lf) / 2\n", keliling,sisi[2]);
                    printf("Sisi Miring = %.2lf\n\n", sisi[2]);
                }
            }
            if(keliling == 0)
            {
                keliling = rumus_datar(7,sisi[2],sisi[1],sisi[2],0);
                printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                printf("Diketahui Alas = %.2lf\n", sisi[1]);
                printf("keliling = %.2lf + %.2lf + %.2lf\n", sisi[2],sisi[1],sisi[2]);
                printf("Keliling = %.2lf\n\n", keliling);
            }
            if(luas == 0)
            {
                luas = rumus_datar(11,sisi[0],sisi[1],0,0);
                printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                printf("Diketahui Alas = %.2lf\n", sisi[1]);
                printf("Luas = (%.2lf * %.2lf) / 2\n", sisi[0],sisi[1]);
                printf("Luas = %.2lf\n\n", luas);
            }
            printf("Sisi Miring Segitiga = %.2lf\n", sisi[2]);
            printf("Alas Segitiga = %.2lf\n", sisi[1]);
            printf("Tinggi Segitiga = %.2lf\n", sisi[0]);
        }
        if (segitiga == 3)
        {
            if (sisi[0] == 0)
            {
                if (keliling != 0)
                {
                    sisi[0] = rumus_datar(8,keliling,0,0,0);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Sisi = %.2lf / 3\n", keliling,sisi[0],sisi[2]);
                    printf("Sisi = %.2lf\n\n", sisi[0]);
                }
                if(luas != 0)
                {
                    sisi[0] = rumus_datar(1,luas*2,0,0,0);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("        ______________\n");
                    printf("Sisi = / (%.2lf * 2)\n", luas);
                    printf("Sisi = %.2lf\n\n", sisi[0]);
                }
            }
            if(keliling == 0)
            {
                keliling = rumus_datar(7,sisi[0],sisi[0],sisi[0],0);
                printf("Diketahui Sisi = %.2lf\n", sisi[0]);
                printf("keliling = %.2lf + %.2lf + %.2lf\n", sisi[0],sisi[0],sisi[0]);
                printf("Keliling = %.2lf\n\n", keliling);

            }
            if(luas == 0)
            {
                luas = rumus_datar(11,sisi[0],sisi[0],0,0);
                printf("Diketahui Sisi = %.2lf\n", sisi[0]);
                printf("Luas = (%.2lf * %.2lf) / 2\n", sisi[0],sisi[0]);
                printf("Luas = %.2lf\n\n", luas);
            }
            printf("Sisi Segitiga = %.2lf\n", sisi[0]);
        }
        printf("Keliling Segitiga = %.2lf\n", keliling);
        printf("Luas Segitiga = %.2lf\n", luas);
        break;
    case '4':
		system("cls");
        printf("|---- Selamat Datang di Kalkulator Jajar Genjang ----|\n\n");
        printf("Masukan Data : \n");
        printf("Masukan Alas = ");scanf("%lf", &sisi[0]);
        printf("Masukan Sisi Miring = ");scanf("%lf", &sisi[1]);
        printf("Masukkan Tinggi = ");scanf("%lf", &sisi[2]);
        printf("Masukan Keliling = ");scanf("%lf", &keliling);
        printf("Masukan Luas = ");scanf("%lf", &luas);
        printf("\n");
        if(sisi[0] == 0)
        {
            if(sisi[1] != 0)
            {
                if (keliling != 0)
                {
                    sisi[0] = rumus_datar(12,keliling,sisi[1],0,0);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[1]);
                    printf("Alas = (%.2lf - 2 * %.2lf) / 2\n", keliling,sisi[1]);
                    printf("Alas = %.2lf\n\n", sisi[0]);
                }
            }
        }
        if(sisi[1] == 0)
        {
            if(sisi[0] != 0)
            {
                if (keliling != 0)
                {
                    sisi[1] = rumus_datar(12,keliling,sisi[0],0,0);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Diketahui Alas = %.2lf\n", sisi[0]);
                    printf("Sisi Miring = (%.2lf - 2 * %.2lf) / 2\n", keliling,sisi[0]);
                    printf("Sisi Miring = %.2lf\n\n", sisi[1]);
                }
            }
        }
        if(sisi[2] == 0)
        {
        	if(sisi[0] != 0)
        	{
        		if(luas != 0)
        		{
        			sisi[2] = rumus_datar(5,luas,sisi[0],0,0);
        			printf("Diketahui Luas = %.2lf\n", luas);
        			printf("Diketahui Alas = %.2lf\n", sisi[0]);
                    printf("Tinggi = %.2lf/%.2lf\n", luas,sisi[0]);
                    printf("Tinggi = %.2lf\n\n", sisi[2]);
				}
			}
		}
        if(keliling == 0)
        {
            keliling = rumus_datar(3,sisi[0],sisi[1],0,0);
            printf("Diketahui Alas = %.2lf\n", sisi[0]);
            printf("Diketahui Sisi Miring = %.2lf\n", sisi[1]);
            printf("keliling = (%.2lf + %.2lf) * 2\n", sisi[0],sisi[1]);
            printf("Keliling = %.2lf\n\n", keliling);
        }
        if(luas == 0)
        {
            luas = rumus_datar(4,sisi[0],sisi[2],0,0);
            printf("Diketahui Alas = %.2lf\n", sisi[0]);
            printf("Diketahui Tinggi = %.2lf\n", sisi[2]);
            printf("Luas = %.2lf * %.2lf\n", sisi[0],sisi[2]);
            printf("Luas = %.2lf\n\n", luas);
        }
        printf("Data dari Jajar Genjang :\n");
        printf("Panjang dari Jajar Genjang = %.2lf\n", sisi[0]);
        printf("Lebar dari Jajar Genjang = %.2lf\n", sisi[1]);
        printf("Tinggi dari Jajar Genjang = %.2lf\n", sisi[2]);
        printf("Keliling dari Jajar Genjang = %.2lf\n", keliling);
        printf("Luas dari Jajar Genjang = %.2lf\n", luas);
        system("pause");
		break;		
    case '5':
    	system("cls");
        printf("|---- Selamat Datang di Kalkulator Trapesium ----|\n\n");
        printf("Masukan Data : \n");
        printf("Masukan Panjang Rusuk Atas = ");scanf("%lf", &sisi[0]);
        printf("Masukan Panjang Rusuk Bawah = ");scanf("%lf", &sisi[1]);
        printf("Masukkan Panjang Rusuk Kiri = ");scanf("%lf", &sisi[2]);
        printf("Masukkan Panjang Rusuk Kanan = ");scanf("%lf", &sisi[3]);
        printf("Masukkan Tinggi Trapesium = ");scanf("%lf", &tinggi);
        printf("Masukan Keliling = ");scanf("%lf", &keliling);
        printf("Masukan Luas = ");scanf("%lf", &luas);
        printf("\n");
        if(sisi[0] == 0)
        {
            if(sisi[1] != 0)
            {
            	if(sisi[2] != 0)
            	{
            		if(sisi[3] != 0)
            		{
            			if (keliling != 0)
                		{
                    		sisi[0] = rumus_datar(13,keliling,sisi[1],sisi[2],sisi[3]);
                    		printf("Diketahui Keliling = %.2lf\n", keliling);
                    		printf("Diketahui Rusuk Bawah = %.2lf\n", sisi[1]);
                    		printf("Diketahui Rusuk Kiri = %.2lf\n", sisi[2]);
                    		printf("Diketahui Rusuk Kanan = %.2lf\n", sisi[3]);
                    		printf("Rusuk Atas = %.2lf - %.2lf - %.2lf - %.2lf\n", keliling,sisi[1],sisi[2],sisi[3]);
                    		printf("Rusuk Atas = %.2lf\n\n", sisi[0]);
                		}
					}
				} 
            }
        }
        if(sisi[1] == 0)
        {
            if(sisi[0] != 0)
            {
            	if(sisi[2] != 0)
            	{
            		if(sisi[3] != 0)
            		{
            			if (keliling != 0)
                		{
                    		sisi[1] = rumus_datar(13,keliling,sisi[0],sisi[2],sisi[3]);
                    		printf("Diketahui Keliling = %.2lf\n", keliling);
                    		printf("Diketahui Rusuk Atas = %.2lf\n", sisi[0]);
                    		printf("Diketahui Rusuk Kiri = %.2lf\n", sisi[2]);
                    		printf("Diketahui Rusuk Kanan = %.2lf\n", sisi[3]);
                    		printf("Rusuk Bawah = %.2lf - %.2lf - %.2lf - %.2lf\n", keliling,sisi[0],sisi[2],sisi[3]);
                    		printf("Rusuk Bawah = %.2lf\n\n", sisi[1]);
                		}
					}
				} 
            }
        }
        if(sisi[2] == 0)
        {
            if(sisi[0] != 0)
            {
            	if(sisi[1] != 0)
            	{
            		if(sisi[3] != 0)
            		{
            			if (keliling != 0)
                		{
                    		sisi[2] = rumus_datar(13,keliling,sisi[0],sisi[1],sisi[3]);
                    		printf("Diketahui Keliling = %.2lf\n", keliling);
                    		printf("Diketahui Rusuk Atas = %.2lf\n", sisi[0]);
                    		printf("Diketahui Rusuk Bawah = %.2lf\n", sisi[1]);
                    		printf("Diketahui Rusuk Kanan = %.2lf\n", sisi[3]);
                    		printf("Rusuk Kiri = %.2lf - %.2lf - %.2lf - %.2lf\n", keliling,sisi[0],sisi[1],sisi[3]);
                    		printf("Rusuk Kiri = %.2lf\n\n", sisi[2]);
                		}
					}
				} 
            }
        }
        if(sisi[3] == 0)
        {
            if(sisi[0] != 0)
            {
            	if(sisi[1] != 0)
            	{
            		if(sisi[2] != 0)
            		{
            			if (keliling != 0)
                		{
                    		sisi[3] = rumus_datar(13,keliling,sisi[0],sisi[1],sisi[2]);
                    		printf("Diketahui Keliling = %.2lf\n", keliling);
                    		printf("Diketahui Rusuk Atas = %.2lf\n", sisi[0]);
                    		printf("Diketahui Rusuk Bawah = %.2lf\n", sisi[1]);
                    		printf("Diketahui Rusuk Kiri = %.2lf\n", sisi[2]);
                    		printf("Rusuk Kanan = %.2lf - %.2lf - %.2lf - %.2lf\n", keliling,sisi[0],sisi[1],sisi[2]);
                    		printf("Rusuk Kanan = %.2lf\n\n", sisi[3]);
                		}
					}
				} 
            }
        }
        if(tinggi == 0)
        {
        	if(sisi[0] != 0)
        	{
        		if(sisi[1] != 0)
        		{
        			if(luas != 0)
        			{
        				tinggi = rumus_datar(15,luas,sisi[0],sisi[1],0);
        				printf("Diketahui Luas = %.2lf\n", luas);
        				printf("Diketahui Rusuk Atas = %.2lf\n", sisi[0]);
        				printf("Diketahui Rusuk Bawah = %.2lf\n", sisi[1]);
                    	printf("Tinggi = 2 * %.2lf / (%.2lf + %.2lf)\n", luas,sisi[0],sisi[1]);
                    	printf("Tinggi = %.2lf\n\n", tinggi);
					}
				}
			}
		}
        if(keliling == 0)
        {
            keliling = rumus_datar(14,sisi[0],sisi[1],sisi[2],sisi[3]);
            printf("Diketahui Rusuk Atas = %.2lf\n", sisi[0]);
            printf("Diketahui Rusuk Bawah = %.2lf\n", sisi[1]);
            printf("Diketahui Rusuk Kiri = %.2lf\n", sisi[2]);
            printf("Diketahui Rusuk Kanan = %.2lf\n", sisi[3]);
            printf("keliling = %.2lf + %.2lf + %.2lf + %.2lf\n", sisi[0],sisi[1],sisi[2],sisi[3]);
            printf("Keliling = %.2lf\n\n", keliling);
        }
        if(luas == 0)
        {
            luas = rumus_datar(16,sisi[0],sisi[2],tinggi,0);
            printf("Diketahui Rusuk Atas = %.2lf\n", sisi[0]);
            printf("Diketahui Rusuk Bawah = %.2lf\n", sisi[1]);
            printf("Diketahui Tinggi = %.2lf\n", tinggi);
            printf("Luas = (%.2lf + %.2lf) * %.2lf / 2\n", sisi[0],sisi[1],tinggi);
            printf("Luas = %.2lf\n\n", luas);
        }
        printf("Data dari Trapesium :\n");
        printf("Panjang Rusuk Atas dari Trapesium = %.2lf\n", sisi[0]);
        printf("Panjang Rusuk Bawah dari Trapesium = %.2lf\n", sisi[1]);
        printf("Panjang Rusuk Kiri dari Trapesium = %.2lf\n", sisi[2]);
        printf("Panjang Rusuk Kanan dari Trapesium = %.2lf\n", sisi[3]);
        printf("Tinggi dari Trapesium = %.2lf\n", tinggi);
        printf("Keliling dari Trapesium = %.2lf\n", keliling);
        printf("Luas dari Trapesium = %.2lf\n", luas);
        system("pause");
        break;
    case '6':
    	system("cls");
        printf("|---- Selamat Datang di Kalkulator Belah Ketupat ----|\n\n");
        printf("Masukan Data : \n");
        printf("Masukkan Sisi = "); scanf("%lf", &sisi[0]);
        printf("Masukkan Panjang Diagonal 1 = "); scanf("%lf", &sisi[1]);
        printf("Masukkan Panjang Diagonal 2 = "); scanf("%lf", &sisi[2]);
        printf("Masukan Keliling = ");scanf("%lf", &keliling);
        printf("Masukan Luas = ");scanf("%lf", &luas);
        printf("\n");
        if(sisi[0] == 0)
        {
        	if(keliling != 0)
        	{
        		sisi[0] = rumus_datar(2,keliling,0,0,0);
        		printf("Diketahui Keliling = %.2lf\n", keliling);
        		printf("Sisi = %.2lf / 4\n", keliling);
        		printf("Sisi = %.2lf\n\n", sisi[0]);
			}
		}
		if(sisi[1] == 0)
		{
			if(sisi[2] != 0)
			{
				if(luas != 0)
				{
					sisi[1] = rumus_datar(10,luas,sisi[2],0,0);
					printf("Diketahui Luas = %.2lf", luas);
					printf("Diketahui Panjang Diagonal 2 = %.2lf\n", sisi[2]);
					printf("Diagonal 1 = %.2lf * 2 / %.2lf\n", luas,sisi[2]);
					printf("Diagonal 1 = %.2lf\n\n", sisi[1]);
				}
			}
		}
		if(sisi[2] == 0)
		{
			if(sisi[1] != 0)
			{
				if(luas != 0)
				{
					sisi[2] = rumus_datar(10,luas,sisi[1],0,0);
					printf("Diketahui Luas = %.2lf\n", luas);
					printf("Diketahui Panjang Diagonal 1 = %.2lf\n", sisi[1]);
					printf("Diagonal 2 = %.2lf * 2 / %.2lf\n", luas,sisi[1]);
					printf("Diagonal 2 = %.2lf\n\n", sisi[2]);
				}
			}
		}
		if(keliling == 0)
		{
			keliling = rumus_datar(17,sisi[0],0,0,0);
        	printf("Diketahui Sisi = %.2lf\n", sisi[0]);
        	printf("Keliling = %.2lf * 4\n", sisi[0]);
        	printf("Keliling = %.2lf\n\n", keliling);
		}
		if(luas == 0)
		{
			luas = rumus_datar(11,sisi[1],sisi[2],0,0);
        	printf("Diketahui Diagonal 1 = %.2lf\n", sisi[1]);
        	printf("Diketahui Diagonal 2 = %.2lf\n", sisi[2]);
        	printf("Luas = (%.2lf * %.2lf) / 2\n", sisi[1],sisi[2]);
        	printf("Luas = %.2lf\n\n", luas);
		}
		printf("Data dari Belah Ketupat :\n");
        printf("Panjang Sisi dari Belah Ketupat = %.2lf\n", sisi[0]);
        printf("Panjang Diagonal 1 dari Belah Ketupat = %.2lf\n", sisi[1]);
        printf("Panjang Diagonal 2 dari Belah Ketupat = %.2lf\n", sisi[2]);
        printf("Keliling dari Belah Ketupat = %.2lf\n", keliling);
        printf("Luas dari Belah Ketupat = %.2lf\n", luas);
        system("pause");
        break;
    case '7':
    	system("cls");
        printf("|---- Selamat Datang di Kalkulator Layang-Layang ----|\n\n");
        printf("Masukan Data : \n");
        printf("Masukkan Panjang Rusuk Pendek = "); scanf("%lf", &sisi[0]);
        printf("Masukkan Panjang Rusuk Panjang = "); scanf("%lf", &sisi[1]);
        printf("Masukkan Panjang Diagonal 1 = "); scanf("%lf", &sisi[2]);
        printf("Masukkan Panjang Diagonal 2 = "); scanf("%lf", &sisi[3]);
        printf("Masukan Keliling = ");scanf("%lf", &keliling);
        printf("Masukan Luas = ");scanf("%lf", &luas);
        printf("\n");
        if(sisi[0] == 0)
        {
            if(sisi[1] != 0)
            {
                if (keliling != 0)
                {
                    sisi[0] = rumus_datar(12,keliling,sisi[1],0,0);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Diketahui Rusuk Panjang = %.2lf\n", sisi[1]);
                    printf("Rusuk Pendek = (%.2lf - 2 * %.2lf) / 2\n", keliling,sisi[1]);
                    printf("Rusuk Pendek = %.2lf\n\n", sisi[0]);
                }
            }
        }
        if(sisi[1] == 0)
        {
            if(sisi[0] != 0)
            {
                if (keliling != 0)
                {
                    sisi[1] = rumus_datar(12,keliling,sisi[0],0,0);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Diketahui Rusuk Pendek = %.2lf\n", sisi[0]);
                    printf("Rusuk Panjang = (%.2lf - 2 * %.2lf) / 2\n", keliling,sisi[0]);
                    printf("Rusuk Panjang = %.2lf\n\n", sisi[1]);
                }
            }
        }
		if(sisi[2] == 0)
		{
			if(sisi[3] != 0)
			{
				if(luas != 0)
				{
					sisi[2] = rumus_datar(10,luas,sisi[3],0,0);
					printf("Diketahui Luas = %.2lf\n", luas);
					printf("Diketahui Panjang Diagonal 2 = %.2lf\n", sisi[3]);
					printf("Diagonal 1 = %.2lf * 2 / %.2lf\n", luas,sisi[3]);
					printf("Diagonal 1 = %.2lf\n\n", sisi[2]);
				}
			}
		}
		if(sisi[3] == 0)
		{
			if(sisi[2] != 0)
			{
				if(luas != 0)
				{
					sisi[3] = rumus_datar(10,luas,sisi[2],0,0);
					printf("Diketahui Luas = %.2lf\n", luas);
					printf("Diketahui Panjang Diagonal 1 = %.2lf\n", sisi[2]);
					printf("Diagonal 2 = %.2lf * 2 / %.2lf\n", luas,sisi[2]);
					printf("Diagonal 2 = %.2lf\n\n", sisi[3]);
				}
			}
		}
		if(keliling == 0)
		{
			keliling = rumus_datar(3,sisi[0],sisi[1],0,0);
        	printf("Diketahui Rusuk Pendek = %.2lf\n", sisi[0]);
        	printf("Diketahui Rusuk Panjang = %.2lf\n", sisi[1]);
        	printf("Keliling = (%.2lf + %.2lf) * 2\n", sisi[0],sisi[1]);
        	printf("Keliling = %.2lf\n\n", keliling);
		}
		if(luas == 0)
		{
			luas = rumus_datar(11,sisi[2],sisi[3],0,0);
        	printf("Diketahui Diagonal 1 = %.2lf\n", sisi[2]);
        	printf("Diketahui Diagonal 2 = %.2lf\n", sisi[3]);
        	printf("Luas = (%.2lf * %.2lf) / 2\n", sisi[2],sisi[3]);
        	printf("Luas = %.2lf\n\n", luas);
		}
		printf("Data dari Layang-Layang :\n");
        printf("Panjang Rusuk Pendek dari Layang-Layang = %.2lf\n", sisi[0]);
        printf("Panjang Rusuk Panjang dari Layang-Layang = %.2lf\n", sisi[1]);
        printf("Panjang Diagonal 1 dari Layang-Layang = %.2lf\n", sisi[2]);
        printf("Panjang Diagonal 2 dari Layang-Layang = %.2lf\n", sisi[3]);
        printf("Keliling dari Layang-Layang = %.2lf\n", keliling);
        printf("Luas dari Layang-Layang = %.2lf\n", luas);
        system("pause");
        break;
    case '8':
    	system("cls");
        printf("|---- Selamat Datang di Kalkulator Lingkaran ----|\n\n");
        printf("Masukan Data : \n");
        printf("Masukkan Jari-Jari = "); scanf("%lf", &jari);
        printf("Masukkan Diameter = "); scanf("%lf", &diameter);
        printf("Masukan Keliling = ");scanf("%lf", &keliling);
        printf("Masukan Luas = ");scanf("%lf", &luas);
        printf("\n");
        if(jari == 0)
        {
        	if(diameter != 0)
        	{
        		jari = rumus_datar(18,diameter,0,0,0);
        		printf("Diketahui Diameter = %.2lf\n", diameter);
        		printf("Jari-Jari = %.2lf / 2\n", diameter);
        		printf("Jari-Jari = %.2lf\n\n", jari);
			}
		}
		if(diameter == 0)
		{
			if(jari != 0)
			{
				diameter = rumus_datar(19,jari,0,0,0);
				printf("Diketahui Jari-Jari = %.2lf\n", jari);
				printf("Diameter = %.2lf * 2\n", jari);
				printf("Diameter = %.2lf\n\n", diameter);
			}
		}
		if(keliling == 0)
		{
			if(jari != 0)
			{
				keliling = rumus_datar(20,jari,0,0,0);
				printf("Diketahui Jari-Jari = %.2lf\n", jari);
				printf("Keliling = 2 * 3.14 * %.2lf\n", jari);
				printf("Keliling = %.2lf\n\n", keliling);
			}
			else if(diameter != 0)
			{
				keliling = rumus_datar(21,diameter,0,0,0);
				printf("Diketahui Diameter = %.2lf\n", diameter);
				printf("Keliling = 3.14 * %.2lf\n", diameter);
				printf("keliling = %.2lf", keliling);
			}
		}
		if(luas == 0)
		{
			if(jari != 0)
			{
				luas = rumus_datar(22,jari,0,0,0);
				printf("Diketahui Jari-Jari = %.2lf\n", jari);
				printf("Luas = 3.14 * %.2lf * %.2lf\n", jari,jari);
				printf("Luas = %.2lf\n\n", luas);
			}
			else if(diameter != 0)
			{
				luas = rumus_datar(23,diameter,0,0,0);
				printf("Diketahui Diameter = %.2lf\n", diameter);
				printf("Luas = 3.14 * %.2lf * %.2lf / 4\n", diameter,diameter);
				printf("Luas = %.2lf\n\n", luas);
			}
		}
		printf("Data dari Lingkaran :\n");
        printf("Jari-Jari dari Lingkaran = %.2lf\n", jari);
        printf("Diameter dari Lingkaran = %.2lf\n", diameter);
        printf("Keliling dari Lingkaran = %.2lf\n", keliling);
        printf("Luas dari Lingkaran = %.2lf\n", luas);
        system("pause");
        break;
    case '9':
        return main();
        break;
    default:
        return menu_bangun_datar();
    }
}
double rumus_ruang(int pil, double a, double b, double c, double d){
	if(pil == 1) return sqrt(a / 6); //luas permukaan menjadi sisi kubus
	if(pil == 2) return cbrt(a); //volume menjadi sisi kubus
	if(pil == 3) return 6 * pow(a, 2); //sisi menjadi luas permukaan kubus
	if(pil == 4) return pow(a, 3); //sisi menjadi volume kubus
	if(pil == 5) return ((a / 2) - b * c) / (b + c); //mencari panjang/lebar/tinggi dari luas permukaan balok
	if(pil == 6) return a / b * c; //mencari panjang/lebar/tinggi dari volume balok
	if(pil == 7) return 2 * ((a * b) + (a * c) + (b * c)); //panjang, lebar, dan tinggi menjadi luas permukaan balok
	if(pil == 8) return a * b * c; //panjang, lebar, dan tinggi menjadi volume balok dan volume prisma
	if(pil == 9) return sqrt(a / 3.14 * b); //mencari jari-jari dari volume tabung
	if(pil == 10) return a / 3.14 * pow (b,2); //mencari tinggi dari volume tabung
	if(pil == 11) return a / 2 * 3.14 * b; //mencari jari-jari/tinggi dari luas selimut tabung
	if(pil == 12) return 2 * 3.14 * a * (a + b); //luas permukaan tabung dengan tutup
	if(pil == 13) return 3.14 * a * (a + 2 * b); //luas permukaan tabung tanpa tutup
	if(pil == 14) return 3.14 * pow(a, 2) * b; //volume tabung
	if(pil == 15) return 2 * 3.14 * a * b; //luas selimut tabung dan kerucut
	if(pil == 16) return sqrt(a / 4 * 3.14); //mencari jari-jari dari luas permukaan bola
	if(pil == 17) return cbrt(3 * a / 4 * 3.14); //mencari jari-jari dari volume bola
	if(pil == 18) return 4 * 3.14 * a; //luas permukaan bola
	if(pil == 19) return 3.14 * pow(a, 3) * 4/3; //volume bola
	if(pil == 20) return sqrt(3 * a / 3.14 * b); //mencari jari-jari dari volume kerucut
	if(pil == 21) return a / 3.14 * b; //mencari jari-jari dan garis pelukis dari luas selimut kerucut
	if(pil == 22) return a * 3 / 3.14 * pow(b,2); //mencari tinggi dari volume kerucut
	if(pil == 23) return sqrt(pow(a,2) + pow(b,2)); //mencari garis pelukis dari jari-jari dan tinggi kerucut
	if(pil == 24) return sqrt(pow(a,2) - pow(b,2)); //mencari jari-jari dan tinggi kerucut jika diketahui garis pelukis kerucut 
	if(pil == 25) return 3.14 * a * (a + b); //luas permukaan kerucut
	if(pil == 26) return 3.14 * pow(a,2) * b / 3; //volume kerucut
}
int menu_bangun_ruang(){
	char pilihan;
	int tab;
	double sisi[4]={0,0,0,0}, lp = 0, vol = 0, ls = 0, r = 0, t = 0, s = 0;
	system("cls");
    printf("|---- Selamat Datang di Kalkulator Bangun Ruang ----|\n\n"
           "Menu :\n"
           "1. Kubus                                   5. Tabung\n"
           "2. Balok                                   6. Kerucut\n"
           "3. Prisma                                  7. Bola\n"
           "4. Limas                                   8. Kembali\n"
		   "Pilihan : ");
	scanf("%c",&pilihan);
	while(getchar() != '\n');
    switch (pilihan)
    {
    	case '1':
    		system("cls");
	        printf("|---- Selamat Datang di Kalkulator Kubus ----|\n\n");
	        printf("Masukan Data : \n");
	        printf("Masukan Sisi = "); scanf("%lf", &sisi[0]);
	        printf("Masukan Luas Permukaan = "); scanf("%lf", &lp);
	        printf("Masukan Volume = "); scanf("%lf", &vol);
	        printf("\n");
	        if(sisi[0] == 0)
	        {
	            if(lp != 0)
	            {
	                sisi[0] = rumus_ruang(1,lp,0,0,0);
	                printf("Diketahui Luas Permukaan = %.2lf\n", lp);
	                printf("Sisi = sqrt(%.2lf/6)\n", lp);
	                printf("Sisi = %.2lf\n\n", sisi[0]);
	            }
	            if (vol != 0)
	            {
	                sisi[0] = rumus_ruang(2,vol,0,0,0);
	                printf("Diketahui Volume = %.2lf\n", vol);
	                printf("Sisi = cbrt(%.2lf)\n", vol);
	                printf("Sisi = %.2lf\n\n", sisi[0]);
	            }
	        }
	        if(lp == 0)
	        {
	            lp = rumus_ruang(3,sisi[0],0,0,0);
	            printf("Diketahui Sisi = %.2lf\n", sisi[0]);
	            printf("Luas Permukaan = 6 * %.2lf * %.2lf\n", sisi[0], sisi[0]);
	            printf("Luas Permukaan = %.2lf\n\n", lp);
	        }
	        if(vol == 0)
	        {
	            vol = rumus_ruang(4,sisi[0],0,0,0);
	            printf("Diketahui Sisi = %.2lf\n", sisi[0]);
	            printf("Volume = %.2lf * %.2lf * %.2lf\n", sisi[0], sisi[0], sisi[0]);
	            printf("Volume = %.2lf\n\n", vol);
	        }
	        printf("Data dari Kubus :\n");
	        printf("Sisi dari Kubus = %.2lf\n", sisi[0]);
	        printf("Luas Permukaan dari Kubus = %.2lf\n", lp);
	        printf("Volume dari Kubus = %.2lf\n", vol);
	        system("pause");
	        break;
	    case '2':
	    	system("cls");
	        printf("|---- Selamat Datang di Kalkulator Balok ----|\n\n");
	        printf("Masukan Data : \n");
	        printf("Masukan Panjang = "); scanf("%lf", &sisi[0]);
	        printf("Masukan Lebar = "); scanf("%lf", &sisi[1]);
	        printf("Masukan Tinggi = "); scanf("%lf", &sisi[2]);
	        printf("Masukan Luas Permukaan = "); scanf("%lf", &lp);
	        printf("Masukan Volume = "); scanf("%lf", &vol);
	        printf("\n");
	        if(sisi[0] == 0)
	        {
	            if(sisi[1] != 0)
	            {
	            	if(sisi[2] != 0)
	            	{
	            		if(lp != 0)
	            		{
	            			sisi[0] = rumus_ruang(5,lp,sisi[1],sisi[2],0);
		                	printf("Diketahui Luas Permukaan = %.2lf\n", lp);
		                	printf("Diketahui Lebar = %.2lf\n", sisi[1]);
		                	printf("Diketahui Tinggi = %.2lf\n", sisi[2]);
		                	printf("Panjang = ((%.2lf / 2) - %.2lf * %.2lf) / %.2lf + %.2lf\n", lp,sisi[1],sisi[2],sisi[1],sisi[2]);
		                	printf("Panjang = %.2lf\n\n", sisi[0]);
						}
	            		else if(vol != 0)
	            		{
	            			sisi[0] = rumus_ruang(6,vol,sisi[1],sisi[2],0);
	            			printf("Diketahui Volume = %.2lf\n", vol);
	            			printf("Diketahui Lebar = %.2lf\n", sisi[1]);
		                	printf("Diketahui Tinggi = %.2lf\n", sisi[2]);
		                	printf("Panjang = %.2lf / %.2lf * %.2lf\n", vol,sisi[1],sisi[2]);
		                	printf("Panjang = %.2lf\n\n", sisi[0]);
						}
					}
	            }
	        }
	        if(sisi[1] == 0)
	        {
	            if(sisi[0] != 0)
	            {
	            	if(sisi[2] != 0)
	            	{
	            		if(lp != 0)
	            		{
	            			sisi[1] = rumus_ruang(5,lp,sisi[0],sisi[2],0);
		                	printf("Diketahui Luas Permukaan = %.2lf\n", lp);
		                	printf("Diketahui Panjang = %.2lf\n", sisi[0]);
		                	printf("Diketahui Tinggi = %.2lf\n", sisi[2]);
		                	printf("Lebar = ((%.2lf / 2) - %.2lf * %.2lf) / %.2lf + %.2lf\n", lp,sisi[0],sisi[2],sisi[0],sisi[2]);
		                	printf("Lebar = %.2lf\n\n", sisi[1]);
						}
	            		else if(vol != 0)
	            		{
	            			sisi[1] = rumus_ruang(6,vol,sisi[0],sisi[2],0);
	            			printf("Diketahui Volume = %.2lf\n", vol);
	            			printf("Diketahui Panjang = %.2lf\n", sisi[0]);
		                	printf("Diketahui Tinggi = %.2lf\n", sisi[2]);
		                	printf("Lebar = %.2lf / %.2lf * %.2lf\n", vol,sisi[0],sisi[2]);
		                	printf("Lebar = %.2lf\n\n", sisi[1]);
						}
					}
	            }
	        }
	        if(sisi[2] == 0)
	        {
	            if(sisi[0] != 0)
	            {
	            	if(sisi[1] != 0)
	            	{
	            		if(lp != 0)
	            		{
	            			sisi[2] = rumus_ruang(5,lp,sisi[0],sisi[1],0);
		                	printf("Diketahui Luas Permukaan = %.2lf\n", lp);
		                	printf("Diketahui Panjang = %.2lf\n", sisi[0]);
		                	printf("Diketahui Lebar = %.2lf\n", sisi[1]);
		                	printf("Tinggi = ((%.2lf / 2) - %.2lf * %.2lf) / %.2lf + %.2lf\n", lp,sisi[0],sisi[1],sisi[0],sisi[1]);
		                	printf("Tinggi = %.2lf\n\n", sisi[2]);
						}
	            		else if(vol != 0)
	            		{
	            			sisi[2] = rumus_ruang(6,vol,sisi[0],sisi[1],0);
	            			printf("Diketahui Volume = %.2lf\n", vol);
	            			printf("Diketahui Panjang = %.2lf\n", sisi[0]);
		                	printf("Diketahui Lebar = %.2lf\n", sisi[1]);
		                	printf("Tinggi = %.2lf / %.2lf * %.2lf\n", vol,sisi[0],sisi[1]);
		                	printf("Tinggi = %.2lf\n\n", sisi[2]);
						}
					}
	            }
	        }
	        if(lp == 0)
	        {
	            lp = rumus_ruang(7,sisi[0],sisi[1],sisi[2],0);
	            printf("Diketahui Panjang = %.2lf\n", sisi[0]);
	            printf("Diketahui Lebar = %.2lf\n", sisi[1]);
	            printf("Diketahui Tinggi = %.2lf\n", sisi[2]);
	            printf("Luas Permukaan = 2 * ((%.2lf * %.2lf) + (%.2lf * %.2lf) + (%.2lf * %.2lf))\n", sisi[0],sisi[1],sisi[0],sisi[2],sisi[1],sisi[2]);
	            printf("Luas Permukaan = %.2lf\n\n", lp);
	        }
	        if(vol == 0)
	        {
	            vol = rumus_ruang(8,sisi[0],sisi[1],sisi[2],0);
	            printf("Diketahui Panjang = %.2lf\n", sisi[0]);
	            printf("Diketahui Lebar = %.2lf\n", sisi[1]);
	            printf("Diketahui Tinggi = %.2lf\n", sisi[2]);
	            printf("Volume = %.2lf * %.2lf * %.2lf\n", sisi[0], sisi[1], sisi[2]);
	            printf("Volume = %.2lf\n\n", vol);
	        }
	        printf("Data dari Balok :\n");
	        printf("Panjang dari Balok = %.2lf\n", sisi[0]);
	        printf("Lebar dari Balok = %.2lf\n", sisi[1]);
	        printf("Tinggi dari Balok = %.2lf\n", sisi[2]);
	        printf("Luas Permukaan dari Balok = %.2lf\n", lp);
	        printf("Volume dari Balok = %.2lf\n", vol);
	        system("pause");
	        break;
	    case '3':
	    	printf("|---- Selamat Datang di Kalkulator Prisma ----|\n\n");
	        printf("Masukan Data : \n");
	        printf("Masukan Alas = "); scanf("%lf", &sisi[0]);
	        printf("Masukan Tinggi = "); scanf("%lf", &sisi[1]);
	        printf("Masukan Tinggi Prisma = "); scanf("%lf", &sisi[2]);
	        printf("Masukan Luas Permukaan = "); scanf("%lf", &lp);
	        printf("Masukan Volume = "); scanf("%lf", &vol);
	        printf("\n");
	        if(vol == 0)
	        {
	        	vol = rumus_ruang(8,sisi[0],sisi[1],sisi[2],0) / 2;
	        	printf("Diketahui Alas = %.2lf\n", sisi[0]);
	        	printf("Diketahui Tinggi = %.2lf\n", sisi[1]);
	        	printf("Diketahui Tinggi Prisma = %.2lf\n", sisi[2]);
	        	printf("Volume = %.2lf * %.2lf * %.2lf / 2\n", sisi[0],sisi[1],sisi[2]);
	        	printf("Volume = %.2lf\n\n", vol);
			}
			printf("Data dari Prisma :\n");
	        printf("Alas dari Prisma = %.2lf\n", sisi[0]);
	        printf("Tinggi dari Alas Prisma = %.2lf\n", sisi[1]);
	        printf("Tinggi dari Prisma = %.2lf\n", sisi[2]);
	        printf("Volume dari Prisma = %.2lf\n", vol);
	        system("pause");
	    	break;
	    case '4':
	    	printf("|---- Selamat Datang di Kalkulator Limas ----|\n\n");
	        printf("Masukan Data : \n");
	        printf("Masukan Alas = "); scanf("%lf", &sisi[0]);
	        printf("Masukan Tinggi = "); scanf("%lf", &sisi[1]);
	        printf("Masukan Tinggi Limas = "); scanf("%lf", &sisi[2]);
	        printf("Masukan Luas Permukaan = "); scanf("%lf", &lp);
	        printf("Masukan Volume = "); scanf("%lf", &vol);
	        printf("\n");
	        if(vol == 0)
	        {
	        	vol = rumus_ruang(8,sisi[0],sisi[1],sisi[2],0) / 6;
	        	printf("Diketahui Alas = %.2lf\n", sisi[0]);
	        	printf("Diketahui Tinggi = %.2lf\n", sisi[1]);
	        	printf("Diketahui Tinggi Limas = %.2lf\n", sisi[2]);
	        	printf("Volume = %.2lf * %.2lf * %.2lf / 6\n", sisi[0],sisi[1],sisi[2]);
	        	printf("Volume = %.2lf\n\n", vol);
			}
			printf("Data dari Limas :\n");
	        printf("Alas dari Limas = %.2lf\n", sisi[0]);
	        printf("Tinggi dari Alas Limas = %.2lf\n", sisi[1]);
	        printf("Tinggi dari Limas = %.2lf\n", sisi[2]);
	        printf("Volume dari Limas = %.2lf\n", vol);
	        system("pause");
	    	break;
	    case '5':
	    	system("cls");
	        printf("|---- Selamat Datang di Kalkulator Tabung ----|\n\n");
	        printf("Masukan Data : \n");
	        printf("Masukan Jari-Jari = "); scanf("%lf", &r);
	        printf("Masukan Tinggi = "); scanf("%lf", &t);
	        printf("Masukan Luas Permukaan = "); scanf("%lf", &lp);
            printf("Masukkan Luas Selimut = "); scanf("%lf", &ls);
	        printf("Masukan Volume = "); scanf("%lf", &vol);
	        printf("\n");
	        printf("Menu Tabung Yang Tersedia :\n1. Dengan Tutup\n2.Tanpa Tutup\n");
	        printf("Pilih Jenis Tabung No Berapa: ");scanf("%d", &tab);
	        printf("\n");
	        if(r == 0)
	        {
	        	if(ls != 0)
	        	{
	        		r = rumus_ruang(11,ls,t,0,0);
	        		printf("Diketahui Luas Selimut = %.2lf\n", ls);
	        		printf("Diketahui Tinggi = %.2lf\n", t);
	        		printf("Jari-Jari = %.2lf / 2 * 3.14 * %.2lf\n", ls,t);
	        		printf("Jari-Jari = %.2lf\n\n", r);
				}
				else if(vol != 0)
	        	{
	        		r = rumus_ruang(9,vol,t,0,0);
	        		printf("Diketahui Volume = %.2lf\n", vol);
	        		printf("Diketahui Tinggi = %.2lf\n", t);
	        		printf("Jari-Jari = akar (%.2lf / 3.14 * %.2lf)\n", vol,t);
	        		printf("Jari-Jari = %.2lf\n\n", r);
				}
			}
			if(t == 0)
			{
				if(ls != 0)
				{
					t = rumus_ruang(11,ls,r,0,0);
					printf("Diketahui Luas Selimut = %.2lf\n", ls);
					printf("Diketahui Jari-Jari = %.2lf\n", r);
					printf("Tinggi = %.2lf / 2 * 3.14 * %.2lf\n", ls,r);
					printf("Tinggi = %.2lf\n\n", t);
				}
				else if(vol != 0)
				{
					t = rumus_ruang(10,vol,r,0,0);
					printf("Diketahui Volume = %.2lf\n", vol);
					printf("Diketahui Jari-Jari = %.2lf\n", r);
					printf("Tinggi = %.2lf / 3.14 * pow (%.2lf,2)\n", vol,r);
					printf("Tinggi = %.2lf\n\n", t);
				}
			}
	        if(lp == 0)
	        {
	        	if(tab == 1)
	        	{
	        		lp = rumus_ruang(9,r,t,0,0);
	        		printf("Diketahui Jari-Jari = %.2lf\n", r);
	        		printf("Diketahui Tinggi = %.2lf\n", t);
	        		printf("Luas Permukaan = 2 * 3.14 * %.2lf * (%.2lf + %.2lf)\n", r,r,t);
	        		printf("Luas Permukaan = %.2lf\n\n", lp);
				}
				if(tab == 2)
				{
					lp = rumus_ruang(13,r,t,0,0);
					printf("Diketahui Jari-Jari = %.2lf\n", r);
					printf("Diketahui Tinggi = %.2lf\n", t);
					printf("Luas Permukaan = 3.14 * %.2lf * (%.2lf + 2 * %.2lf)\n", r,r,t);
					printf("Luas Permukaan = %.2lf\n\n", lp);
				}
			}
			if(ls == 0)
	        {
	        	ls = rumus_ruang(15,r,t,0,0);
	        	printf("Diketahui Jari-Jari = %.2lf\n", r);
	        	printf("Diketahui Tinggi = %.2lf\n", t);
	        	printf("Luas Selimut = 2 * 3.14 * %.2lf * %.2lf\n", r,t);
	        	printf("Luas Selimut = %.2lf\n\n", ls);
			}
			if(vol == 0)
			{
				vol = rumus_ruang(14,r,t,0,0);
				printf("Diketahui Jari-Jari = %.2lf\n", r);
				printf("Diketahui Tinggi = %.2lf\n", t);
				printf("Volume = 3.14 * pow(%.2lf, 2) * %.2lf\n", r,t);
			}
			printf("Data dari Tabung :\n");
	        printf("Jari-Jari dari Tabung = %.2lf\n", r);
	        printf("Tinggi dari Tabung = %.2lf\n", t);
	        printf("Luas Selimut dari Tabung = %.2lf\n", ls);
	        printf("Luas Permukaan dari Tabung = %.2lf\n", lp);
	        printf("Volume dari Tabung = %.2lf\n", vol);
	        system("pause");
	        break;
	    case '6':
	    	system("cls");
	        printf("|---- Selamat Datang di Kalkulator Kerucut ----|\n\n");
	        printf("Masukan Data : \n");
	        printf("Masukan Jari-Jari = "); scanf("%lf", &r);
	        printf("Masukan Tinggi = "); scanf("%lf", &t);
	        printf("Masukan Garis Pelukis = "); scanf("%lf", &s);
	        printf("Masukan Luas Permukaan = "); scanf("%lf", &lp);
	        printf("Masukan Volume = "); scanf("%lf", &vol);
	        printf("Masukkan Luas Selimut = "); scanf("%lf", &ls);
	        printf("\n");
	        if(r == 0)
	        {
	        	if(vol != 0)
	        	{
	        		r = rumus_ruang(20,vol,t,0,0);
	        		printf("Diketahui Volume = %,2lf\n", vol);
	        		printf("Diketahui Tinggi = %.2lf\n", t);
	        		printf("Jari-Jari = akar(3 * %.2lf / 3.14 * %.2lf)\n", vol,t);
	        		printf("Jari-Jari = %.2lf\n\n", r);
				}
				else if(s != 0)
				{
					if(ls != 0)
					{
						r = rumus_ruang(21,ls,s,0,0);
						printf("Diketahui Luas Selimut = %.2lf\n", ls);
						printf("Diketahui Garis Pelukis = %.2lf\n", s);
						printf("Jari-Jari = %.2lf / 3.14 * %.2lf\n", ls,s);
						printf("Jari-Jari = %.2lf\n\n", r);
					}
					else if(t != 0)
					{
						r = rumus_ruang(24,s,t,0,0);
						printf("Diketahui Garis Pelukis = %.2lf\n", s);
						printf("Diketahui Tinggi = %.2lf\n", t);
						printf("Jari-Jari = akar((%.2lf * %.2lf) - (%.2lf * %.2lf))\n", s,s,t,t);
						printf("Jari-Jari = %.2lf\n\n", r);
					}
				}
			}
			if(t == 0)
			{
				if(r != 0)
				{
					if(vol != 0)
					{
						t = rumus_ruang(22,vol,r,0,0);
						printf("Diketahui Volume = %.2lf\n", vol);
						printf("Diketahui Jari-Jari = %.2lf\n", r);
						printf("Tinggi = %.2lf * 3 / 3.14 * %.2lf * %.2lf\n", vol,r,r);
						printf("Tinggi = %.2lf\n\n", t);
					}
					else if(s != 0)
					{
						t = rumus_ruang(24,s,r,0,0);
						printf("Diketahui Garis Pelukis = %.2lf\n", s);
						printf("Diketahui Jari-Jari = %.2lf\n", r);
						printf("Tinggi = akar((%.2lf * %.2lf) - (%.2lf * %.2lf))\n", s,s,r,r);
						printf("Tinggi = %.2lf\n\n", t);
					}
				}
			}
			if(s == 0)
			{
				if(r != 0)
				{
					if(ls != 0)
					{
						s = rumus_ruang(21,ls,r,0,0);
						printf("Diketahui Luas Selimut = %.2lf\n", ls);
						printf("Diketahui Jari-Jari = %.2lf\n", r);
						printf("Garis Pelukis = %.2lf / 3.14 * %.2lf\n", ls,r);
						printf("Garis Pelukis = %.2lf\n\n", s);
					}
					else if(t != 0)
					{
						s = rumus_ruang(23,r,t,0,0);
						printf("Diketahui Jari-Jari = %.2lf\n", r);
						printf("Diketahui Tinggi = %.2lf\n", t);
						printf("Garis Pelukis = akar((%.2lf * %.2lf) + (%.2lf * %.2lf))\n", r,r,t,t);
						printf("Garis Pelukis = %.2lf\n\n", s);
					}
				}
			}
			if(lp == 0)
			{
				lp = rumus_ruang(25,r,s,0,0);
				printf("Diketahui Jari-Jari = %.2lf\n", r);
				printf("Diketahui Garis Pelukis = %.2lf\n", s);
				printf("Luas Permukaan = 3.14 * %.2lf * (%.2lf + %.2lf)\n", r,r,s);
				printf("Luas Permukaan = %.2lf\n\n", lp);
			}
			if(vol == 0)
			{
				vol = rumus_ruang(26,r,t,0,0);
				printf("Diketahui Jari-Jari = %.2lf\n", r);
				printf("Diketahui Tinggi = %.2lf\n", t);
				printf("Volume = 3.14 * %.2lf * %.2lf * %.2lf / 3\n", r,r,t);
				printf("Volume = %.2lf\n\n", vol);
			}
			printf("Data dari Kerucut :\n");
	        printf("Jari-Jari dari Kerucut = %.2lf\n", r);
	        printf("Tinggi dari Kerucut = %.2lf\n", t);
	        printf("Luas Selimut dari Kerucut = %.2lf\n", ls);
	        printf("Luas Permukaan dari Kerucut = %.2lf\n", lp);
	        printf("Volume dari Kerucut = %.2lf\n", vol);
	        system("pause");
	        break;
	    case '7':
	    	system("cls");
	        printf("|---- Selamat Datang di Kalkulator Bola ----|\n\n");
	        printf("Masukan Data : \n");
	        printf("Masukan Jari-Jari = "); scanf("%lf", &r);
	        printf("Masukan Luas Permukaan = "); scanf("%lf", &lp);
	        printf("Masukan Volume = "); scanf("%lf", &vol);
	        printf("\n");
	        if(r == 0)
	        {
	        	if(lp != 0)
	        	{
	        		r = rumus_ruang(16,lp,0,0,0);
	        		printf("Diketahui Luas Permukaan = %.2lf\n", lp);
	        		printf("Jari - Jari = akar(%.2lf / 4 * 3.14)\n", lp);
	        		printf("Jari - Jari = %.2lf\n\n", r);
				}
				else if(vol != 0)
				{
					r = rumus_ruang(17,vol,0,0,0);
	        		printf("Diketahui Volume = %.2lf\n", vol);
	        		printf("Jari - Jari = akar kubik(3 * a / 4 * 3.14)\n", vol);
	        		printf("Jari - Jari = %.2lf\n\n", r);
				}
			}
			if(lp == 0)
			{
				lp = rumus_ruang(18,r,0,0,0);
				printf("Diketahui Jari-Jari = %.2lf\n", r);
				printf("Luas Permukaan = 4 * 3.14 * %.2lf\n", r);
				printf("Luas Permukaan = %.2lf\n\n", lp);
			}
			if(vol == 0)
			{
				vol = rumus_ruang(19,r,0,0,0);
				printf("Diketahui Jari-Jari = %.2lf\n", r);
				printf("Volume = 3.14 * %.2lf * %.2lf * %.2lf * 4/3\n", r,r,r);
				printf("Volume = %.2lf\n\n", vol);
			}
			printf("Data dari Bola :\n");
	        printf("Jari-Jari dari Bola = %.2lf\n", r);
	        printf("Luas Permukaan dari Bola = %.2lf\n", lp);
	        printf("Volume dari Bola = %.2lf\n", vol);
	        system("pause");
	        break;
	    default :
	    	return menu_bangun_ruang();
	}
}

float dtrm(int pilihan, float matriks1[4][4]){ // Untuk determinan
	float dtr = 0;
	int i;
	if(pilihan == 1) dtr += matriks1[0][0]*matriks1[1][1]-matriks1[0][1]*matriks1[1][0];
	else{
		for(int i=0; i<3; i++){
			dtr += (matriks1[0][i]*(matriks1[1][(i+1)%3]*matriks1[2][(i+2)%3]-matriks1[1][(i+2)%3]*matriks1[2][(i+1)%3]));
		}
	}
	return dtr;
}

int jumlahkurang(int pil){ // Untuk Penjumlahan dan Pengurangan Matriks
	int baris, kolom, banyak;
	printf("Masukkan jumlah baris matriks: "); scanf("%d", &baris);
	printf("Masukkan jumlah kolom matriks: "); scanf("%d", &kolom);
	printf("Masukkan banyak matriks yang ingin dioperasikan: "); scanf("%d", &banyak);
	if(baris==0||kolom==0||banyak==0) return matriks();
	int matriks[banyak][baris][kolom];
	for(int i=0; i<banyak; i++){
		printf("\nMASUKKAN ANGKA MATRIKS KE-%d :\n", i+1);
		for(int j=0; j<baris; j++){
			for(int k=0; k<kolom; k++){
				printf("MATRIKS %d [%d][%d] = ", i+1, j+1, k+1);
				scanf("%d", &matriks[i][j][k]);
			}
		}
		printf("\nMatriks %d :\n", i+1);
		for(int j=0; j<baris; j++){
			for(int k=0; k<kolom; k++){
				printf("%d\t", matriks[i][j][k]);
			}
			printf("\n");
		}
	}
	if(pil == 1){
		for(int i=0; i<banyak-1; i++){
			for(int j=0; j<baris; j++){
				for(int k=0; k<kolom; k++){
					matriks[i+1][j][k]=matriks[i][j][k]+matriks[i+1][j][k];
				}
			}
		}
		printf("\nHasil Penjumlahan Matriks :\n");
		for(int j=0; j<baris; j++){
			for(int k=0; k<kolom; k++){
				printf("%d\t", matriks[banyak-1][j][k]);
			}
			printf("\n");
		}
	}else if(pil == 2){
		for(int i=0; i<banyak-1; i++){
			for(int j=0; j<baris; j++){
				for(int k=0; k<kolom; k++){
					matriks[i+1][j][k]=matriks[i][j][k]-matriks[i+1][j][k];
				}
			}
		}
		printf("\nHasil Pengurangan Matriks :\n");
		for(int j=0; j<baris; j++){
			for(int k=0; k<kolom; k++){
				printf("%d\t", matriks[banyak-1][j][k]);
			}
			printf("\n");
		}
	}
}

int kali(){ // Untuk Perkalian Matriks
	int baris1, kolom1, baris2, kolom2;
	printf("MATRIKS 1\nMasukkan banyak baris: "); scanf("%d", &baris1);
	printf("Masukkan banyak kolom: "); scanf("%d", &kolom1);
	printf("\nMATRIKS 2\nMasukkan banyak baris: "); scanf("%d", &baris2);
	printf("Masukkan banyak kolom: "); scanf("%d", &kolom2);
	if(baris1==0||kolom1==0||baris2==0||kolom2==0) return matriks();
	if(kolom1!=baris2) printf("\nSYARAT PERKALIAN MATRIKS: BANYAK KOLOM MATRIKS 1 = BANYAK BARIS MATRIKS 2!");
	else{
		int matriks1[baris1][kolom1], matriks2[baris2][kolom2], hasil[baris1][kolom2], jumlah = 0;
		printf("\nMASUKKAN MATRIKS 1 :\n");
		for(int i=0; i<baris1; i++){
			for(int j=0; j<kolom1;j++){
				printf("Matriks 1 [%d][%d] = ", i+1, j+1);
				scanf("%d", &matriks1[i][j]);
			}
		}
		printf("\nMATRIKS 1 :\n");
		for(int i=0; i<baris1; i++){
			for(int j=0; j<kolom1;j++){
				printf("%d\t", matriks1[i][j]);
			}
			printf("\n");
		}
		printf("\nMASUKKAN MATRIKS 2 :\n");
		for(int i=0; i<baris2; i++){
			for(int j=0; j<kolom2; j++){
				printf("Matriks 2 [%d][%d] = ", i+1, j+1);
				scanf("%d", &matriks2[i][j]);
			}
		}
		printf("\nMATRIKS 2 :\n");
		for(int i=0; i<baris2; i++){
			for(int j=0; j<kolom2;j++){
				printf("%d\t", matriks2[i][j]);
			}
			printf("\n");
		}
		printf("\nHasil Perkalian antara Matriks 1 dan Matriks 2 :\n");
		for(int i=0; i<baris1; i++){
			for(int j=0; j<kolom2; j++){
				for(int k=0; k<baris2; k++){
					jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
				}
				hasil[i][j] = jumlah;
				printf("%d\t", hasil[i][j]);
				jumlah = 0;
			}
			printf("\n");
		}
	}
}

int detinvers(int pil){ // Untuk Determinan dan Invers Matriks
	printf("\nSilahkan masukkan pilihan ingin matriks ordo berapa?\n");
	printf("1. Matriks 2x2                          2. Matriks 3x3\n");
	printf("\t\t     3. Kembali\n\nNOTE: MASUKAN PILIHAN SESUAI DENGAN NOMOR PILIHAN!\n");
	int pilihan;
	float matriks1[4][4];
	printf("   Pilihan: ");scanf("%d", &pilihan); getchar();
	if(pilihan==1){
	    printf("\nMASUKKAN MATRIKS ORDO 2x2 :\n");
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				printf("Matriks [%d][%d] = ", i+1, j+1);
				scanf("%f", &matriks1[i][j]);
			}
		}
		printf("\nMatriks yang diinput :\n");
		for(int i=0; i<2; i++){
			for(int j=0; j<2;j++){
				printf("%.2f\t", matriks1[i][j]);
			}
			printf("\n");
		}
		float dtr=dtrm(pilihan, matriks1);
	    if(pil == 4) printf("\nHasil Determinan Matriks 2x2 = %.2f", dtr);
		else if(pil == 5){
			if(dtr==0) printf("\nMATRIKS YANG DIINPUT MERUPAKAN MATRIKS SINGULAR ATAU MATRIKS YANG TIDAK MEMILIKI INVERS");
			else{
				printf("\nHasil Invers Matriks 2x2 :\n");
				for(int i=1; i>=0; i--){
					for(int j=1; j>=0; j--){
						if(i==j) printf("%.2f\t", matriks1[j][i]/dtr);
						else printf("%.2f\t", -matriks1[j][i]/dtr);
					}
					printf("\n");
				}
			}
		}
	}else if(pilihan==2){
		printf("\nMASUKKAN MATRIKS ORDO 3x3 :\n");
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				printf("Matriks [%d][%d] = ", i+1, j+1);
				scanf("%f", &matriks1[i][j]);
			}
		}
		printf("\nMatriks yang diinput :\n");
		for(int i=0; i<3; i++){
			for(int j=0; j<3;j++){
				printf("%.2f\t", matriks1[i][j]);
			}
			printf("\n");
		}
		float dtr=dtrm(pilihan, matriks1);
        if(pil == 4) printf("\nHasil Determinan Matriks 3x3 = %.2f", dtr);
		else if(pil == 5){
			if(dtr==0) printf("\nMATRIKS YANG DIINPUT MERUPAKAN MATRIKS SINGULAR ATAU MATRIKS YANG TIDAK MEMILIKI INVERS");
			else{
				printf("\nHasil Invers Matriks 3x3 :\n");
				for(int i=0; i<3; i++){
					for(int j=0; j<3; j++){
						printf("%.2f\t", (matriks1[(j+1)%3][(i+1)%3]*matriks1[(j+2)%3][(i+2)%3]-matriks1[(j+1)%3][(i+2)%3]*matriks1[(j+2)%3][(i+1)%3])/dtr);
					}
					printf("\n");
				}
			}
		}
	}else if(pilihan==3) return matriks();
	else return detinvers(pil);
}
int transpose(){ // Untuk Transpose Matriks
	int baris, kolom;
	printf("Masukkan banyak baris : "); scanf("%d", &baris);
	printf("Masukkan banyak kolom : "); scanf("%d", &kolom);
	if(baris==0||kolom==0) return matriks();
	int matriks[baris][kolom];
	printf("\nMASUKKAN MATRIKS ORDO %dx%d:\n", baris, kolom);
	for(int i=0; i<baris; i++){
	    for(int j=0; j<kolom; j++){
	    	printf("Matriks[%d][%d] = ", i+1, j+1); scanf("%d", &matriks[i][j]);
	    }
	}
	printf("\nMatriks yang diinput:\n");
	for(int i=0; i<baris; i++){
	    for(int j=0; j<kolom; j++){
	        printf("%d\t", matriks[i][j]);
	    }
	    printf("\n");
	}
	printf("\nHasil Transpose Matriks :\n");
	for(int i=0; i<kolom; i++){
	    for(int j=0; j<baris; j++){
	        printf("%d\t", matriks[j][i]);
	    }
	    printf("\n");
	}
}

int matriks(){ // MATRIKS
    system("cls");
    printf("      |==========Selamat Datang di Kalkulator Matriks==========|\n");
    printf("\nMenu :\n");
    printf("1. Penjumlahan Matriks                          4. Determinan Matriks\n");
    printf("2. Pengurangan Matriks                          5. Invers Matriks\n");
    printf("3. Perkalian Matriks                            6. Transpose Matriks\n");
    printf("\t\t\t      7. Kembali\nNOTE: MASUKAN PILIHAN SESUAI DENGAN NOMOR PILIHAN!\n");
    int pil;
    printf("   Pilihan: ");scanf("%d", &pil);
    getchar();
    if(pil==1){
        system("cls");
        printf("|========Selamat Datang di Kalkulator Penjumlahan Matriks========|\n\n");
        printf("NOTE: MASUKKAN ANGKA 0 UNTUK KEMBALI\n\n");
        jumlahkurang(pil);
    }else if(pil==2){
        system("cls");
        printf("|========Selamat Datang di Kalkulator Pengurangan Matriks========|\n\n");
        printf("NOTE: MASUKKAN ANGKA 0 UNTUK KEMBALI\n\n");
        jumlahkurang(pil);
    }else if(pil==3){
        system("cls");
        printf("|========Selamat Datang di Kalkulator Perkalian Matriks========|\n\n");
        printf("NOTE: MASUKKAN ANGKA 0 UNTUK KEMBALI\n\n");
        kali();
    }else if(pil==4){
		system("cls");
		printf("|========Selamat Datang di Kalkulator Determinan Matriks========|\n\n");
        detinvers(pil);
    }else if(pil==5){
		system("cls");
		printf("|========Selamat Datang di Kalkulator Invers Matriks========|\n\n");
        detinvers(pil);
    }else if(pil==6){
        system("cls");
        printf("|========Selamat Datang di Kalkulator Transpose Matriks========|\n\n");
        transpose();
    }else if(pil==7) return main();
    else return matriks();
}

void history(){
    char pilihan;
    system("cls");
    printf("Menu Riwayat\n");
    printf("1. Lihat Riwayat Kalkulator\n2. Hapus Riwayat\n");
    printf("Masukan Pilihan: ");scanf("%c", &pilihan);
    switch (pilihan)
    {
    case '1':
        printf("=== Riwayat Dari Kalkulator ===\n");
            FILE *file2 = fopen("History_Kalkulator.txt", "r");
            char temp[255];
            if(file2 == NULL)
            {
                printf("Belum ada riwayat\n");
                fclose(file2);
            }
            else
            {
                while(fgets(temp,225,file2) != NULL)
                {
                    printf("%s", temp);
                }    
            }
            fclose(file2);
        break;
    case '2':
        if (remove("History_Kalkulator.txt") == 0) printf("Riwayat telah dihapus\n");
        else printf("Riwayat tidak ditemukan\n");
        break;
    default:
        break;
    }
}
