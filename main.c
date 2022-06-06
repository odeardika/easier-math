#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void kalkulator();
void ekstra_kalkulator(); 
int menu_bangun_datar(); //Menu Bangun Datar
void menu_bangun_ruang(); //Menu Bangun Ruang
double rumus_datar();
int matriks();

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
           "4. Matriks\n");
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
        if(kal == '1')ekstra_kalkulator(1);
        if(kal == '2')ekstra_kalkulator(2);
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
double rumus_datar(int pil, double a, double b, double c){
    if(pil == 1) return sqrt(a); // luas menjadi sisi
    if(pil == 2) return a / 4; //keliling menjadi sisi
    if(pil == 3) return (a + b) * 2; //sisi menjadi keliling
    if(pil == 4) return a * b; //sisi menjadi luas
    if(pil == 5) return a / b; // mencari panjang/lebar dari luas
    if(pil == 6) return ( a / 2 ) - b; //mencari panjang/lebar dari keliling
    if(pil == 7) return a + b + c; //keliling segitiga
    if(pil == 8) return a / 3; //keliling ke sisi (segitiga sama sisi)
    if(pil == 9) return a - (b + c); //keliling ke sisi (segitiga siku")
    if(pil == 10) return (a * 2) * b; //luas ke sisi 
    if(pil == 11) return (a * b) / 2; //luas segitiga
    
}   

int menu_bangun_datar(){
    system("cls");
    char pilihan;
    int segitiga;
    double sisi[3] = {0,0,0},luas = 0,keliling = 0;
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
                sisi[0] = rumus_datar(1,luas,luas,0);
                printf("Diketahui Luas = %.2lf\n", luas);
                printf("        ______\n");
                printf("Sisi = / %.2lf\n", luas);
                printf("     = %.2lf\n\n", sisi[0]);
            }
            if (keliling != 0)
            {
                sisi[0] = rumus_datar(2,keliling, keliling,0);
                printf("Diketahui Keliling = %.2lf\n", keliling);
                printf("Sisi = %.2lf / 4 \n",keliling);
                printf("Sisi = %.2lf\n\n", sisi[0]);
            }
        }
        if(keliling == 0)
        {
            keliling = rumus_datar(3,sisi[0],sisi[0],0);
            printf("Diketahui Sisi = %.2lf\n", sisi[0]);
            printf("Keliling = %.2lf * 4\n", sisi[0]);
            printf("Keliling = %.2lf\n\n", keliling);
        }
        if(luas == 0)
        {
            luas = rumus_datar(4,sisi[0],sisi[0],0);
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
                    sisi[0] = rumus_datar(6,keliling,sisi[1],0);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Panjang = (%.2lf / 2) - %.2lf\n", keliling,sisi[1]);
                    printf("Panjang = %.2lf\n\n", sisi[0]);
                }
                if (luas != 0)
                {
                    sisi[0] = rumus_datar(5,luas,sisi[1],0);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Panjang = (%.2lf / 2) - %.2lf\n", luas,sisi[1]);
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
                    sisi[1] = rumus_datar(6,keliling,sisi[0],0);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Lebar = (%.2lf / 2) - %.2lf\n", keliling,sisi[0]);
                    printf("Lebar = %.2lf\n\n", sisi[1]);
                }
                if (luas != 0)
                {
                    sisi[1] = rumus_datar(5,luas,sisi[0],0);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Lebar = (%.2lf / 2) - %.2lf\n", luas,sisi[0]);
                    printf("Lebar = %.2lf\n\n", sisi[1]);
                }  
            }
        }
        if(keliling == 0)
        {
            keliling = rumus_datar(3,sisi[1],sisi[2],0);
            printf("Diketahui Panjang = %.2lf\n", sisi[0]);
            printf("Diketahui Lebar = %.2lf\n", sisi[1]);
            printf("keliling = (%.2lf + %.2lf) * 2\n", sisi[0],sisi[1]);
            printf("Keliling = %.2lf\n\n", keliling);
        }
        if(luas == 0)
        {
            luas = rumus_datar(4,sisi[1],sisi[0],0);
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
            printf("Masukan Tinggi = ");scanf("%d", &sisi[0]);
            printf("Masukan Alas = ");scanf("%d", &sisi[1]);
            printf("Masukan Sisi Miring = ");scanf("%d",&sisi[2]);
        }
        if(segitiga == 2){
            printf("Masukan Sisi Miring = ");scanf("%d",&sisi[0]);
            printf("Masukan Alas = ");scanf("%d", &sisi[1]); 
        }
        if(segitiga == 3) {printf("Masukan Sisi = ");scanf("%d", sisi[0]);}
        printf("Masukan Keliling = ");scanf("%lf", &keliling);
        printf("Masukan Luas = ");scanf("%lf", &luas);
        printf("\n");
        if(segitiga == 1)
        {
            if(sisi[0] == 0)
            {
                if(keliling != 0 && sisi[2] != 0)
                {
                    sisi[0] = rumus_datar(9,keliling,sisi[1],sisi[2]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Tinggi = %.2lf - (%.2lf + %.2lf)\n", keliling,sisi[1],sisi[2]);
                    printf("Tinggi = %.2lf\n\n", sisi[0]);
                }
                if(luas != 0)
                {
                    sisi[0] = rumus_datar(10,luas,sisi[1],0);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Tinggi = %.2lf - (%.2lf + %.2lf)\n", keliling,sisi[1],sisi[2]);
                    printf("Tinggi = %.2lf\n\n", sisi[0]);
                }
            }
            if(sisi[1] == 0)
            {
                if(keliling != 0 && sisi[2] != 0)
                {
                    sisi[1] = rumus_datar(9,keliling,sisi[0],sisi[2]);
                }
                if(luas != 0)
                {
                    sisi[1] = rumus_datar(10,luas,sisi[0],0);
                }
            }
            if(sisi[2] == 0)
            {
                if(keliling != 0)
                {
                    sisi[2] = rumus_datar(9,keliling,sisi[0],sisi[1]);
                }
            }
            if(keliling == 0)
            {
                keliling = rumus_datar(7,sisi[0],sisi[1],sisi[2]);
            }
            if (luas == 0)
            {
                luas = rumus_datar(11,sisi[0],sisi[1],0);
            }
            
        }
        if(segitiga == 2)
        {
            if(sisi[0] == 0)
            {
                if(keliling != 0)
                {
                    sisi[0] = rumus_datar(9,keliling,sisi[1],0)/2;
                }
                if(luas != 0)
                {
                    sisi[0] = rumus_datar(10,luas,sisi[1],0);
                }
            }
            if(sisi[1] == 0)
            {
                if(keliling != 0)
                {
                    sisi[1] = rumus_datar(9,keliling,sisi[0],sisi[0]);
                }
                if(luas != 0)
                {
                    sisi[1] = rumus_datar(10,luas,sisi[0],0);
                }
            }
            if(keliling == 0)
            {
                keliling = rumus_datar(7,sisi[0],sisi[1],sisi[0]);
            }
            if(luas == 0)
            {
                luas = rumus_datar(11,sisi[0],sisi[1],0);
            }
        }
        if (segitiga == 3)
        {
            if (sisi[0] == 0)
            {
                if (keliling != 0)
                {
                    sisi[0] = rumus_datar(8,keliling,0,0);
                }
                if(luas != 0)
                {
                    sisi[0] = rumus_datar(1,luas*2,0,0);
                }
            }
            if(keliling == 0)
            {
                keliling = rumus_datar(7,sisi[0],sisi[0],sisi[0]);
            }
            if(luas == 0)
            {
                luas = rumus_datar(11,sisi[0],sisi[0],0);
            }
        }
        //        "Menu:\n"
        //        "1. Mencari Luas                           4. Mencari Alas (dengan Keliling)\n"
        //        "2. Mencari Keliling                       5. Mencari Tinggi (dengan Luas)\n"
        //        "3. Mencari Alas (dengan Luas)             6. Mencari Tinggi (dengan Sisi)\n"
        //        "Pilihan: ");
        // scanf("%c", &rumus); getchar();
        // switch (rumus)
        // {
        // case '1':
        //     printf("\nMasukan Alas = ");
        //     scanf("%lf", &alas);
        //     printf("Masukan Tinggi = ");
        //     scanf("%lf", &tinggi);
        //     luas = ( alas * tinggi ) / 2;
        //     printf("Luas = %.2lf", luas);
        //     break;
        // case '2':
        //     for(int i = 0; i < 3; i++){
        //         printf("Masukan Sisi ke-%d = ", i+1);
        //         scanf(" %lf", &sisi[i]);
        //         keliling += sisi[i];
        //     }
        //     printf("Keliling = %.2lf", keliling);
        //     break;
        // case '3':
        //     printf("\nMasukan Luas = ");
        //     scanf("%lf", &luas);
        //     printf("Masukkan Tinggi = ");
        //     scanf("%lf", &tinggi);
        //     alas = ( luas * 2 ) / tinggi;
        //     printf("Alas = %.2lf", alas);
        //     break;
        // case '4':
        //     printf("\nMasukan Keliling = ");
        //     scanf("%lf", &keliling);
        //     alas = keliling;
        //     for(int i = 0; i < 2; i++){
        //         printf("Masukan Sisi ke-%d = ", i+1);
        //         scanf(" %lf", &sisi[i]);
        //         alas -= sisi[i];
        //     }
        //     printf("Alas = %.2lf", alas);
        //     break;
        // case '5':
        //     printf("\nMasukan Luas = ");
        //     scanf("%lf", &luas);
        //     printf("Masukkan Alas = ");
        //     scanf("%lf", &alas);
        //     tinggi = ( luas * 2 ) / alas;
        //     printf("Tinggi = %.2lf", tinggi);
        //     break;
        // case '6':
        //     printf("\nIngin tinggi dari segitiga apa?\n"
        //            "1. Segitiga Siku-siku\n"
        //            "2. Segitiga Sama Kaki\n"
        //            "3. Segitiga Sama Sisi\n"
        //            "Pilihan: ");
        //     scanf("%c", &pil); getchar();
        //     printf("\nMasukan Sisi Miring = ");
        //     scanf("%lf", &sisi[0]);
        //     if(pil != '3'){
        //         printf("Masukan Sisi Bawah / Alas = ");
        //         scanf("%lf", &alas);
        //     }
        //     if(pil == '1'){
        //         sisi[1] = sqrt(pow(sisi[0], 2) - pow(alas, 2));
        //     }else if(pil == '2'){
        //         alas /= 2;
        //         sisi[1] = sqrt(pow(sisi[0], 2) - pow(alas, 2));
        //     }else if(pil == '3'){
        //         sisi[1] = sqrt(pow(sisi[0], 2) - pow(sisi[0]/2, 2));
        //     }else return menu_bangun_datar();
        //     printf("Tinggi = %.2lf", sisi[1]);
        //     break;
        // default:
        //     return menu_bangun_datar();
        // }
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
    case '9':
        return main();
        break;
    default:
        return menu_bangun_datar();
    }

}

void menu_bangun_ruang(){
    printf("|---- Selamat Datang di Kalkulator Bangun Ruang ----|\n\n"
           "Menu :\n"
           "1. Kubus                                   5. Tabung\n"
           "2. Balok                                   6. Kerucut\n"
           "3. Prisma                                  7. Bola\n"
           "4. Limas                                   8. Kembali\n");
}

float dtrm(int pilihan, float matriks1[4][4]){ // Untuk determinan
	float dtr=0;
	if(pilihan==1) dtr += matriks1[0][0]*matriks1[1][1]-matriks1[0][1]*matriks1[1][0];
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