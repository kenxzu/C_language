#include <stdio.h>

int main() {
    int n;
    printf("Masukan Angka :");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= i) {
                if (j == i)
                    printf("%d", i);
                else
                    printf("*");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}