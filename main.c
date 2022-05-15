#include <stdio.h>
#include <math.h>

void kalkulator();
void ekstra_kalkulator(); 
void menu_bangun_datar(); //Menu Bangun Datar
void menu_bangun_ruang(); //Menu Bangun Ruang

int main(){
    double hasil;
    printf("Menu :\n"
           "1. Kalkulator\n"
           "2. Bangun Datar\n"
           "3. Bangun Ruang\n"
           "4. Matriks\n");
    char pilihan,kal;
    printf("Masukan Pilihan : ");
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
        if(kal == '1')ekstra_kalkulator(1);
        if(kal == '2')ekstra_kalkulator(2);
        break;
    case '2':
        menu_bangun_datar();
        break;
    case '3' :
        menu_bangun_ruang();
        break;
    default:
        break;
    }
    return 0;
}

void ekstra_kalkulator(int a){
    char pil;
    int banyak = 1;
    double awal, penambah, hasil;
    if(a == 1) //kalkulator biasa
    {
        printf("Menu Kalkulator : \n");
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
            printf("Masukan Angka Penambah : ");
            scanf("%lf", &penambah);
            hasil = awal - penambah;
            fprintf(Fptr, "\n %.2lf - %.2lf = %.2lf",awal,penambah,hasil);
        }
        if(pil == '*')
        {
            printf("Masukan Angka Penambah : ");
            scanf("%lf", &penambah);
            hasil = awal * penambah;
            fprintf(Fptr, "\n %.2lf x %.2lf = %.2lf",awal, penambah,hasil);
        }
        if(pil == '/')
        {
            printf("Masukan Angka Penambah : ");
            scanf("%lf", &penambah);
            hasil = awal / penambah;
            fprintf(Fptr, "\n %.2lf : %.2lf = %.2lf",awal, penambah,hasil);
        }
        if(pil == '^')
        {
            printf("Masukan Pangkat : ");
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
        if(pil == '%')
        {
            hasil = awal/100;
            fprintf(Fptr, "\n%.2lf% = %.2lf", awal,hasil);
        }
        if(pil == '=')
        {
            goto end;
        }
    printf("%.2lf\n", hasil);
    banyak++;
    awal = hasil;
    }
    end :
    fprintf(Fptr, "\n===========================\n");
    fclose(Fptr);
    printf("%.2lf\n", awal);

}

void menu_bangun_datar(){
    char pilihan,rumus;
    double sisi,panjang,lebar,luas,keliling;
    printf("Menu :\n"
           "1. Persegi\n"
           "2. Persegi Panjang\n"
           "3. Segitiga\n"
           "4. Jajar Genjang\n"
           "5. Trapesium\n"
           "6. Belah Ketupat\n"
           "7. Layang - layang\n"
           "8. Lingkaran\n"
           "Masukan Pilihan : ");
    scanf("%c",&pilihan);
    while(getchar() != '\n');
    switch (pilihan)
    {
    case '1':
        
        printf("Menu Persegi\n"
               "1. Mencari Luas\n"
               "2. Mencari Keliling\n"
               "3. Mencari Sisi (dengan luas)\n"
               "4. Mencari Sisi (dengan keliling)\n"
               "Masukan Pilihan : ");
                scanf("%c", &rumus);
                switch (rumus)
                {
                case '1':
                    printf("Masukan Sisi = ");
                    scanf("%lf", &sisi);
                    luas = sisi * sisi;
                    printf("Luas = %.2lf", luas);
                    break;
                case '2':
                    printf("Masukan Sisi = ");
                    scanf("%lf", &sisi);
                    keliling = sisi * 4;
                    printf("Keliling = %.2lf", keliling);
                    break;
                case '3':
                    printf("Masukan Luas = ");
                    scanf("%lf", &luas);
                    sisi = sqrt(luas);
                    printf("Sisi = %.2lf", sisi);
                    break;
                case '4':
                    printf("Masukan Luas = ");
                    scanf("%lf", &keliling);
                    sisi = keliling / 4;
                    printf("Sisi = %.2lf", sisi);
                    break;
                default:
                    break;
               }
        break;
    case '2':
        printf("Menu Persegi Panjang\n"
               "1. Mencari Luas\n"
               "2. Mencari Keliling\n"
               "3. Mencari panjang (dengan luas)\n"
               "4. Mencari panjang (dengan keliling)\n"
               "5. Mencari lebar (dengan luas)\n"
               "6. Mencari lebar (dengan keliling)\n"
               "Masukan Pilihan : ");
                scanf("%c", &rumus);
                switch (rumus)
                {
                case '1':
                    printf("Masukan  Panjang = ");
                    scanf("%lf", &panjang);
                    printf("Masukan  Lebar = ");
                    scanf("%lf", &lebar);
                    luas = panjang * lebar;
                    printf("Luas = %.2lf", luas);
                    break;
                case '2':
                    printf("Masukan  Panjang = ");
                    scanf("%lf", &panjang);
                    printf("Masukan  Lebar = ");
                    scanf("%lf", &lebar);
                    keliling = ( panjang + lebar ) * 2;
                    printf("Keliling = %.2lf", keliling);
                    break;
                case '3':
                    printf("Masukan Luas = ");
                    scanf("%lf", &luas);
                    printf("Masukan  Lebar = ");
                    scanf("%lf", &lebar);
                    panjang = luas / lebar;
                    printf("Panjang = %.2lf", panjang);
                    break;
                case '4':
                    printf("Masukan Luas = ");
                    scanf("%lf", &keliling);
                    printf("Masukan  Lebar = ");
                    scanf("%lf", &lebar);
                    panjang = ( keliling / 2 ) - lebar;
                    printf("Panjang = %.2lf", panjang);
                    break;
                case '5':
                    printf("Masukan Luas = ");
                    scanf("%lf", &luas);
                    printf("Masukan  panjang = ");
                    scanf("%lf", &panjang);
                    lebar = luas / panjang;
                    printf("Panjang = %.2lf", lebar);
                    break;
                case '6':
                    printf("Masukan Luas = ");
                    scanf("%lf", &luas);
                    printf("Masukan  Lebar = ");
                    scanf("%lf", &panjang);
                    lebar = ( keliling / 2 ) - panjang;
                    printf("Panjang = %.2lf", lebar);
                    break;
                default:
                    break;
               }
        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        break;
    case '6':
        break;
    case '7':
        break;
    case '8':
        break;
    default:
        break;
    }

}

void menu_bangun_ruang(){
    printf("Menu :\n"
           "1. Kubus\n"
           "2. Balok\n"
           "3. Prisma\n"
           "4. Limas\n"
           "5. Tabung\n"
           "6. Kerucut\n"
           "7.Bola\n");
}

