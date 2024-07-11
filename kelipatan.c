#include <stdio.h>

int hitungkelipatan(int a, int b) {
    int max = (a > b) ? a : b;

    while (1) {
        if (max % a == 0 && max % b == 0) {
            return max;
        }
        max++;
    }
}

int main() {
    int num1, num2=2;
    printf("Enter two integers: ");

    scanf("%d", &num1);

    int lcm = hitungkelipatan(num1, num2);

    printf("kelipatan terkecil %d and %d is: %d\n", num1, num2, lcm);

    return 0;
}
