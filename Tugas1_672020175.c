#include<stdio.h>
#include<math.h>
# define M_PI 3.14159265358979323846  /* nilai pi */

int main(){ 
//inisialisasi derajat
double derajat;
printf("==============================================\n");
printf("\tNama : Ken Foster Morintoh\n");
printf("\t  NIM   : 67202017 \n" ) ;
printf("\t  Kelas : Asdos DDP G \n");
printf("==============================================\n");
printf("   SELAMAT DATANG DI PROGRAM SIN COS TAN \n");
printf("==============================================\n\n");
printf("masukan angka = ");
scanf("%lf", &derajat);

  //ubah dearajat ke radian
    double derajat_radian = derajat * M_PI / 180.0;
    
    // perhitungan sin, cos dan tan
    double sinus = sin(derajat);
    double cosinus = cos(derajat);
    double tangen = tan(derajat);

     // tampilkan hasil
    printf("Sinus dari %.2lf derajat = %.2lf\n", derajat, sinus);
    printf("Cosinus dari %.2lf derajat = %.2lf\n", derajat, cosinus);
    printf("Tangen dari %.2lf derajat = %.2lf\n", derajat, tangen);


return 0;
} 
