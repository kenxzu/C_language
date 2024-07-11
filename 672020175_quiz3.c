#include <stdio.h>

int main() {
    int n;
    
    printf("Masukan angka : ");
    scanf("%d", &n);

    int a = 0, b = 1;
    
    for (int i = 0; a <= n; i++) {
        printf("%d ", a);
        int sum = a + b;
        a = b;
        b = sum;
    }
    
    return 0;
}
