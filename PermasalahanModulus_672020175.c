#include <stdio.h>

int main() {
    int M, N;
    int E;
    int total_modulus = 0;

    // Masukkan nilai pembagi M dan bilangan N 
    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++) {
        // Masukkan angka E sebagai test casenyaa
        scanf("%d", &E);
        // menghitung modulus dari E terhadap M dan tambahkan ke total_modulus
        total_modulus += E % M;
    }

    //total_modulus
    printf("%d\n", total_modulus);

    return 0;
}

