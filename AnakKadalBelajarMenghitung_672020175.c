
#include <stdio.h>
int main() {

    int T; // Jumlah test case yang akan dilakukan.
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        //mengambil input user
        int N; 
        scanf("%d", &N);

        // Cetak tiga angka ganjil berurutan setelah N
        for (int i = 1; i <= 3; i++) {
            if (N % 2 == 0) {
                // Jika N adalah angka genap, tambahkan 1 untuk mendapatkan angka ganjil berikutnya
                N++;
            }

            //CETAK OUTPUT ITALIC
            /*note : code ANSI escape untuk text formating ansi escape bisa bervariasi tergantung terminal dan 
             consol yang kita gunakan atau bahkan ada yang belum support*/
             /* Dalam kontes ini saya menggunakan terminal vscode(support ansi escape text formating) 
             */
            
            printf("\033[3m"); //escape code untuk italic output
            printf("%d ", N);   //print output
             printf("\033[0m"); //reset format kesemula
            N += 2; // Pindah ke angka ganjil berikutnya
        }

        printf("\n");
    }

    return 0;
}