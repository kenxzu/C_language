#include <stdio.h> 
#include <conio.h> //library untuk getch()

//compiler yang digunakan : vscode compiler
int main(){

int tanggalSekarang, bulanSekarang, tanggalLahir, bulanLahir;


printf("\n\t\t====== >   Program cek ulang tahun  < =======\n");
printf("\t\t====== >  Ken Foster Morintoh 672020175 < =======\n\n\n");

printf("Masukan tanggal hari ini : ");
int x = scanf("%d", &tanggalSekarang);
//human error handling 
if(x != 1) { 
    printf("\nMohon isikan data dengan angka\n\n");
    return 1;
}
printf("Masukan bulan hari ini  : ");
int y = scanf("%d", &bulanSekarang);
if(y != 1) { 
    printf("\nMohon isikan data dengan angka\n\n");
    return 1;
}
printf("Masukan tanggal lahir : ");
int z = scanf("%d",&tanggalLahir );
if( z != 1) { 
    printf("\nMohon isikan data dengan angka\n\n");
    return 1;
}
printf("Masukan bulan lahir : ");
int w = scanf("%d",&bulanLahir );
if(w != 1) { 
    printf("\nMohon isikan data dengan angka\n\n");
    return 1;
}
//jika inputan angka yang berlebihan
if (bulanLahir >= 13 || tanggalLahir >= 32 || bulanSekarang >= 13 || tanggalSekarang >= 31) {

    printf("\nMasukan Bulan(0-12) dan Tanggal(1-31)\n");
    printf("Press any key to continue ...");
    getch();
} else if (bulanSekarang == bulanLahir) {
    if (tanggalSekarang == tanggalLahir) {
        printf("\nUlang tahun anda hari ini\n\n");
    } else if (tanggalSekarang > tanggalLahir) {
        printf("\nUlang tahun sudah terlewati\n\n");
    } else {
        printf("\nUlang tahun belum terlewati\n\n");
    }
} else if (bulanSekarang > bulanLahir) {
    printf("\nUlang tahun anda sudah terlewati\n\n");
} else {
    printf("\nUlang tahun belum terlewati\n\n");
}
return 0;
}
