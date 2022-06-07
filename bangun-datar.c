double rumus_datar(int pil, double a, double b, double c){
    if(pil == 1) return pow(a, 1.0/2.0); // luas menjadi sisi
    if(pil == 2) return a / 4; //keliling menjadi sisi
    if(pil == 3) return (a + b) * 2; //sisi menjadi keliling
    if(pil == 4) return a * b; //sisi menjadi luas
    if(pil == 5) return a / b; // mencari panjang/lebar dari luas
    if(pil == 6) return ( a / 2 ) - b; //mencari panjang/lebar dari keliling
    if(pil == 7) return a + b + c; //keliling segitiga
    if(pil == 8) return a / 3; //keliling ke sisi (segitiga sama sisi)
    if(pil == 9) return a - (b + c); //keliling ke sisi (segitiga siku")
    if(pil == 10) return (a * 2) / b; //luas ke sisi 
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
                printf("Sisi = %.2lf\n\n", sisi[0]);
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
            printf("Masukan Tinggi = ");scanf("%lf", &sisi[0]);
            printf("Masukan Alas = ");scanf("%lf", &sisi[1]);
            printf("Masukan Sisi Miring = ");scanf("%lf",&sisi[2]);
        }
        if(segitiga == 2){
            printf("Masukan Sisi Miring = ");scanf("%lf",&sisi[0]);
            printf("Masukan Alas = ");scanf("%lf", &sisi[1]); 
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
                    sisi[0] = rumus_datar(9,keliling,sisi[1],sisi[2]);
                    printf("Diketahui Alas = %.2lf\n", sisi[1]);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Tinggi = %.2lf - (%.2lf + %.2lf)\n", keliling,sisi[1],sisi[2]);
                    printf("Tinggi = %.2lf\n\n", sisi[0]);
                }
                if(luas != 0)
                {
                    sisi[0] = rumus_datar(10,luas,sisi[1],0);
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
                    sisi[1] = rumus_datar(9,keliling,sisi[0],sisi[2]);
                    printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Alas = %.2lf - (%.2lf + %.2lf)\n", keliling,sisi[0],sisi[2]);
                    printf("Alas = %.2lf\n\n", sisi[1]);
                }
                if(luas != 0)
                {
                    sisi[1] = rumus_datar(10,luas,sisi[0],0);
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
                    sisi[2] = rumus_datar(9,keliling,sisi[0],sisi[1]);
                    printf("Diketahui Alas = %.2lf\n", sisi[1]);
                    printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Sisi Miring = %.2lf - (%.2lf + %.2lf)\n", keliling,sisi[0],sisi[1]);
                    printf("Sisi Miring = %.2lf\n\n", sisi[2]);
                }
            }
            if(keliling == 0)
            {
                keliling = rumus_datar(7,sisi[0],sisi[1],sisi[2]);
                printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                printf("Diketahui Alas = %.2lf\n", sisi[1]);
                printf("Diketahui Sisi Miring = %.2lf\n", sisi[2]);
                printf("keliling = %.2lf + %.2lf + %.2lf\n", sisi[0],sisi[1],sisi[2]);
                printf("Keliling = %.2lf\n\n", keliling);
            }
            if (luas == 0)
            {
                luas = rumus_datar(11,sisi[0],sisi[1],0);
                printf("Diketahui Tinggi = %.2lf\n", sisi[0]);
                printf("Diketahui Alas = %.2lf\n", sisi[1]);
                printf("Luas = (%.2lf * %.2lf) / 2\n", sisi[0],sisi[1]);
                printf("Luas = %.2lf\n\n", luas);
            }
            
        }
        if(segitiga == 2)
        {
            if(sisi[0] == 0)
            {
                if(keliling != 0)
                {
                    sisi[0] = rumus_datar(9,keliling,sisi[1],0)/2;
                    printf("Diketahui Alas = %.2lf\n", sisi[1]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Sisi Miring = (%.2lf - %.2lf) / 2\n", keliling,sisi[1]);
                    printf("Sisi Miring = %.2lf\n\n", sisi[0]);
                }
                if(luas != 0)
                {
                    sisi[0] = rumus_datar(10,luas,sisi[1],0);
                    printf("Diketahui Alas = %.2lf\n", sisi[1]);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Sisi Miring = (%.2lf * 2) / %.2lf\n", luas,sisi[1]);
                    printf("Sisi Miring = %.2lf\n\n", sisi[0]);    
                }
            }
            if(sisi[1] == 0)
            {
                if(keliling != 0)
                {
                    sisi[1] = rumus_datar(9,keliling,sisi[0],sisi[0]);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[0]);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Alas = %.2lf - (%.2lf * 2)\n", keliling,sisi[0]);
                    printf("Alas = %.2lf\n\n", sisi[1]);
                }
                if(luas != 0)
                {
                    sisi[1] = rumus_datar(10,luas,sisi[0],0);
                    printf("Diketahui Sisi Miring = %.2lf\n", sisi[0]);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("Alas = (%.2lf * 2) / %.2lf\n", luas,sisi[0]);
                    printf("Alas = %.2lf\n\n", sisi[1]);
                }
            }
            if(keliling == 0)
            {
                keliling = rumus_datar(7,sisi[0],sisi[1],sisi[0]);
                printf("Diketahui Sisi Miring = %.2lf\n", sisi[0]);
                printf("Diketahui Alas = %.2lf\n", sisi[1]);
                printf("keliling = %.2lf + %.2lf + %.2lf\n", sisi[0],sisi[0],sisi[2]);
                printf("Keliling = %.2lf\n\n", keliling);
            }
            if(luas == 0)
            {
                luas = rumus_datar(11,sisi[0],sisi[1],0);
                printf("Diketahui Sisi Miring = %.2lf\n", sisi[0]);
                printf("Diketahui Alas = %.2lf\n", sisi[1]);
                printf("Luas = (%.2lf * %.2lf) / 2\n", sisi[0],sisi[1]);
                printf("Luas = %.2lf\n\n", luas);
            }
        }
        if (segitiga == 3)
        {
            if (sisi[0] == 0)
            {
                if (keliling != 0)
                {
                    sisi[0] = rumus_datar(8,keliling,0,0);
                    printf("Diketahui Keliling = %.2lf\n", keliling);
                    printf("Sisi = %.2lf / 3\n", keliling,sisi[0],sisi[2]);
                    printf("Sisi = %.2lf\n\n", sisi[0]);
                }
                if(luas != 0)
                {
                    sisi[0] = rumus_datar(1,luas*2,0,0);
                    printf("Diketahui Luas = %.2lf\n", luas);
                    printf("        ______________\n");
                    printf("Sisi = / (%.2lf * 2)\n", luas);
                    printf("Sisi = %.2lf\n\n", sisi[0]);
                }
            }
            if(keliling == 0)
            {
                keliling = rumus_datar(7,sisi[0],sisi[0],sisi[0]);
                printf("Diketahui Sisi = %.2lf\n", sisi[0]);
                printf("keliling = %.2lf + %.2lf + %.2lf\n", sisi[0],sisi[0],sisi[0]);
                printf("Keliling = %.2lf\n\n", keliling);

            }
            if(luas == 0)
            {
                luas = rumus_datar(11,sisi[0],sisi[0],0);
                printf("Diketahui Sisi = %.2lf\n", sisi[0]);
                printf("Luas = (%.2lf * %.2lf) / 2\n", sisi[0],sisi[0]);
                printf("Luas = %.2lf\n\n", luas);
            }
        }
        break;