#include <stdio.h>
#include <windows.h>

int main(){
    int n; //tinggi segitiga 
    int input;
    while(input != 3) { 
        input = 0;
        system("cls");
        printf("1. Segitiga\n");
        printf("2. Konversi Mata Uang\n");
        printf("3. Exit \n");
        printf("Masukkan Input : ");
        scanf("%d", &input);

        system("cls");
    
        switch (input){

        case 1: 


         printf("Masukan Tinggi : ");
            scanf("%d",&n); 


        for(int i = 1; i <= n ; i++){
                for (int j = 0; j <= n - i; j++){
                    printf("*");
                }
                printf("\n");
           }

           system("pause");
            break;

        case 2 : 
        
            printf("Konveri Mata Uang\n");
            //USD = DOLLAR, SGD = SINGAPURA DOLAR, EUR = UERO, JPY = YEN
            double USD; 
            //NILAI  CONVERSI PERSATUAN DOLAR TIAP MASING-MASING MATA-UANG
            double Sgd = 1.350;
            double Idr = 15.000; 
            double  Eur = 0.9;
            double Yen = 148.00; 

                printf("Masukan jumlah US Dollars (USD): ");
                scanf("%lf", &USD);

            double SgdTotal = USD *Sgd;
            double IdrTotal = USD *Idr;
            double EurTotal = USD * Eur;
            double YenTotal = USD * Yen;

            printf("Nominal Singapore Dollars (SGD) : %.3lf \n", SgdTotal);
            printf("Nominal Indonesia Dollars (IDR) : %.3lf \n", IdrTotal);
            printf("Nominal Euro (EUR)              : %.3lf \n", EurTotal);
            printf("Nominal Japanese Yen (YEN)      : %.3lf \n", YenTotal);
            system("pause");
            break;
        case 3:
            printf("Ken Foster Morintoh \n");
            printf("672020175\n");
            Sleep(5000);
            system("exit");
            break;
        default : 
            printf("Salah inputan\n");
            system("pause");

            break;
        }
    }
}