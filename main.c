#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void kalkulator();
void ekstra_kalkulator(); 
void menu_bangun_datar(); //Menu Bangun Datar
void menu_bangun_ruang(); //Menu Bangun Ruang
int matriks();

int main(){
    system("cls");
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
    case '4' :
        matriks();
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

float dtrm(int pilihan, float matriks1[4][4]){ // Untuk determinan
	float dtr=0;
	if(pilihan==1){
		dtr += matriks1[0][0]*matriks1[1][1]-matriks1[0][1]*matriks1[1][0];
	}else{
		for(int i=0; i<3; i++){
			dtr += (matriks1[0][i]*(matriks1[1][(i+1)%3]*matriks1[2][(i+2)%3]-matriks1[1][(i+2)%3]*matriks1[2][(i+1)%3]));
		}
	}
	return dtr;
}
int jumlahkurang(int pil){ // Untuk Penjumlahan dan Pengurangan Matriks
	int baris, kolom, banyak;
	printf("Masukkan jumlah baris matriks : "); scanf("%d", &baris);
	printf("Masukkan jumlah kolom matriks : "); scanf("%d", &kolom);
	printf("Masukkan banyak matriks yang ingin dioperasikan : "); scanf("%d", &banyak);
	if(baris==0||kolom==0||banyak==0){
		return matriks();
	}
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
		printf("\nHasil penjumlahan matriks :\n");
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
		printf("\nHasil pengurangan matriks diatas:\n");
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
	printf("MATRIKS 1\nMasukkan banyak baris : "); scanf("%d", &baris1);
	printf("Masukkan banyak kolom : "); scanf("%d", &kolom1);
	printf("\nMATRIKS 2\nMasukkan banyak baris : "); scanf("%d", &baris2);
	printf("Masukkan banyak kolom : "); scanf("%d", &kolom2);
	if(baris1==0||kolom1==0||baris2==0||kolom2==0){
		return matriks();
	}
	if(kolom1!=baris2){
		printf("\nSYARAT PERKALIAN MATRIKS : BANYAK KOLOM MATRIKS 1 = BANYAK BARIS MATRIKS 2!");
	}else{
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
	printf("   Pilihan : ");scanf("%d", &pilihan); getchar();
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
			if(dtr==0){
				printf("\nMATRIKS YANG DIINPUT MERUPAKAN MATRIKS SINGULAR ATAU MATRIKS YANG TIDAK MEMILIKI INVERS");
			}else{
				printf("\nHasil Invers Matriks 2x2:\n");
				for(int i=1; i>=0; i--){
					for(int j=1; j>=0; j--){
						if(i==j){
							printf("%.2f\t", matriks1[j][i]/dtr);
						}
						else{
							printf("%.2f\t", -matriks1[j][i]/dtr);
						}
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
			if(dtr==0){
			printf("\nMATRIKS YANG DIINPUT MERUPAKAN MATRIKS SINGULAR ATAU MATRIKS YANG TIDAK MEMILIKI INVERS");
			}else{
				printf("\nHasil Invers Matriks 3x3:\n");
				for(int i=0; i<3; i++){
					for(int j=0; j<3; j++){
						printf("%.2f\t", (matriks1[(j+1)%3][(i+1)%3]*matriks1[(j+2)%3][(i+2)%3]-matriks1[(j+1)%3][(i+2)%3]*matriks1[(j+2)%3][(i+1)%3])/dtr);
					}
					printf("\n");
				}
			}
		}
	}else if(pilihan==3){
		return matriks();
	}else{
		return detinvers(pil);
	}
}
int transpose(){ // Untuk Transpose Matriks
	int baris, kolom;
	printf("Masukkan banyak baris : "); scanf("%d", &baris);
	printf("Masukkan banyak kolom : "); scanf("%d", &kolom);
	if(baris==0||kolom==0){
		return matriks();
	}
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
	printf("\nHasil Transpose matriks diatas:\n");
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
    printf("\nSilahkan masukkan pilihan ingin menghitung apa:\n");
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
    }else if(pil==7){
        return main();
    }else{
      	return matriks();
    }
}
