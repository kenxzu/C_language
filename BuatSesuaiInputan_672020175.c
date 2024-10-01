#include <stdio.h>

int main() {
    int N;
    printf("Masukkan bilangan bulat: ");
    scanf("%d", &N);

    if (N < 1 || N > 6) {
        printf("Batas inputan: 1 <= N <= 6\n");
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        // Bagian kiri pola
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        // Tanda bintang
        printf("**");
        
        // Bagian kanan pola
        for (int j = i + 3; j <= N+3; j++) {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}
