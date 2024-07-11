#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include <unistd.h>




#define ANSI_COLOR_WHITE "\x1b[97m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"
void hati();
void delay (double number_of_second){
    //converting to mili_second
    double mili_second = 1000 * number_of_second;
    // stroring start time 
    clock_t start_time = clock();

    // loopin till time requiered not achieved 
    while (clock()< start_time + mili_second);
    
    }
    
int gotoxy(){
    // Input
    COORD c;
    c.X = 10;
    c.Y = 10;
 
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
    
int main(){
  char pesan[1000] = "Happy Semprolation sayangku Yunita Sania Putri. Gak nyangka yah udah ditahap ini. Tetep Semangat.. Semangat Revisi Juga hehehe. dikit lagi wisuda, ingat perjuanganmu sampe tahap ini. o iya BTW bentar lagi kamu bakalan menempuh perjalanan baru yaitu menjalani dan menerapkan ilmu yang telah kamu dapat disini dan kamu bkalan nyandang gelar S.Teol..kereen pokonya yang \x03. kalo ditanya satu kata yang mendeskripsikan kamu.. seperti slogan kampus kita uksw. PROUD.. Im PROUD of you.. and atleast but not least, Im so excited with what next on our journey ahead especialy the good ones. wish u all the best byy..";
   // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED);

    int arraySize = sizeof(pesan) / sizeof(char);
    
    gotoxy();
   
  for (int i = 0; i < strlen(pesan); i++) {
        printf(ANSI_COLOR_MAGENTA "%c" ANSI_COLOR_RESET, pesan[i]);
    
       delay(0.1);  // Sleep for 0.2 seconds (200,000 microseconds)
    }
printf("\n");
 hati();
    
}

void hati() {
    int i, j, n = 10;

    
    // Print the upper part of the heart
    for (i = n / 2; i <= n; i += 2) {
        // Print leading spaces
        for (j = 1; j < n - i; j += 2)
            printf(" ");

        // Print left side of the heart
        for (j = 1; j <= i; j++)
            printf("*");

        // Print middle space
        for (j = 1; j <= n - i; j++)
            printf(" ");

        // Print right side of the heart
        for (j = 1; j <= i; j++)
            printf("*");

        // Move to the next line
        printf("\n");
    }
    // Print the lower part of the heart
    for (i = n; i >= 1; i--) {
        // Print leading spaces
        for (j = i; j < n; j++)
            printf(" ");

        // Print left side of the heart
        for (j = 1; j <= (i * 2) - 1; j++)
            printf("*");

        // Move to the next line
        printf("\n");
    }
  }
//\x03

// int main() {
//     char pesan[200];

//     pesan[200] = "Congrats sayangku Yunita Sania Putri";

//     for (int i = 0; )









//     return 0;
// }






  // char nama[100];
  // char nama1[100];
//   int nim[] = {672020175};
// printf("nama saya : ");
// for(int i = 0; i <strlen(nama); i++){
//     printf("%c", nama[i]);
// }

//(STRING COMPARE)///
// printf("nama pertama : ");
// scanf("%[^\n]%*c",nama);

// printf("nama pertama : ");
// scanf("%[^\n]%*c",nama1);

// int hasil = strcmp(nama1, nama);

// if(hasil == 0 ){
//     printf("nama sama");
// }else{
//     printf("nama tidak sama");
// }
// int lenght = sizeof(nim)/sizeof(nim[0]);
// printf("\nnim saya: ");
// for (int j = 0; j < lenght; j++)
// {
//     printf("%d", nim[j]);
// }



//KELIPAN//
// int angka; 
// int angka2 = 2; 
// // int k1,k2;
//   printf("masukan angka peterma : "); 
//   scanf("%d", angka);

//  while (angka != angka2){
//    angka +=angka;
//    angka2 += angka2;
//    if (angka == angka2)
//    {
//      printf("kpk pertama dari angka %d dan %d adalah : %d", angka );
  
//  }
//  }
  

// fungsi hitung dua interger

// int (int a, int b){
//  int max = (a > b) ? a : b;

//  while (1) {
//   if (max % a == 0 && max % b == 0) {      
//          return max;
//          }
//         max++;
//      }
//  }
//      int num1, num2;
// printf("Enter two integers: ");     
// scanf("%d", &num1);

//      int lcm = calculateLCM(num1, num2);

//   printf("The smallest multiple of %d and %d is: %d\n", num1, num2, lcm);


//     return 0;
// }


 