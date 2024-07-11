#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#include <windows.h>

void header(){
        printf("\n\n\t\t=====> Program Cek Kelulusan oleh Ken Foster Morintoh_672020175 <=====\n\n");
    printf("\t\t\t=====>  AST. Dasar Dasar Pemograman(vincent, Hosea) <=====\n\n");
}
void allrightreserved(){
    printf("\n\n\t\t\t\t\tAll Right Reserved \n");
    printf("\t\t\t\t\tCopyright 2023\n"); 
    printf("\t\t\t\t\tKMorin\n\n");
}
int main(){
    char nilai[3];
    int tidakHadir;
    char karakter[3];
    header();
    
    printf("Masukan Nilaimu (A-E) : ");
    scanf(" %s", &nilai);
    printf("Jumlah Ketidakhadiran(Angka) : ");
    int absen = scanf("%d", &tidakHadir); 
      if (absen != 1){
            printf("\n\nMasukan Angka bukan Huruf");
            return 0;
        }
    karakter[0] = toupper(nilai[0]);
    karakter[1] = toupper(nilai[1]);
    karakter[2] = '\0';
    /* karena if else statement lebih baik dari speed efektifitas dalam hal compare dan dapat menghemat line dalam penulisan code
        saya memilih if else stament daripada switch case */
    if (strcmp(karakter, "A") == 0 || strcmp(karakter, "AB") == 0 || strcmp(karakter, "B") == 0 || strcmp(karakter, "BC") == 0 || strcmp(karakter, "C") == 0 || strcmp(karakter, "CD") == 0) {
        if (tidakHadir < 3) {
            printf("\n\nKAMU LULUS\n");
            allrightreserved();
        }   else{
            printf("\n\nKAMU TIDAK LULUT");
             allrightreserved();
        }
        //nilai E
    } else if ((strcmp(karakter, "E") == 0) && (tidakHadir >= 3 || tidakHadir <= 3)) {
            printf("\n\nKAMU TIDAK LULUS");
            allrightreserved();}
    else{ //salah input.
        
        system("cls");
        header();
        printf("\n\n Mohon Masukan Inputan Dengan Benar ya..");
        allrightreserved();
    } 

    return 0;
}
    // printf("Masukan Nilai : ");
    // scanf(" %c", &nilai);
    // printf("Jumlah Ketidakhadiran : ");
    // scanf("%d", &tidakHadir);
    // char karakter = toupper(nilai);
    // switch (karakter){
    // case 'A': 
    //     if( tidakHadir < 3){
    //         printf("KAMU LULUS");
    //     }else{
    //         printf("KAMU TIDAK LULUS");
    //     }
    //     break;
    // case 'B' : 
    //       if(tidakHadir < 3){
    //         printf("KAMU LULUS");
    //     }else{
    //         printf("KAMU TIDAK LULUS");
    //     }
    //     break;
    //     case 'C' : 
    //     if(tidakHadir < 3){
    //         printf("KAMU LULUS");
    //     }else{
    //         printf("KAMU TIDAK LULUS");
    //     }
    //     break;
    //     case 'D' : 
    //     if(tidakHadir < 3){
    //         printf("KAMU LULUS");
    //     }else{
    //         printf("KAMU TIDAK LULUS");
    //     }break;
    //     case 'E' : 
    //     if(tidakHadir < 3){
    //         printf("KAMU ");
    //     }else{
    //         printf("KAMU TIDAK LULUS");
    //     }break;
    // default:
    //     printf("MOHON MASUKAN NILAI YANG VALID A - E");
    //     break;
    // }
    
