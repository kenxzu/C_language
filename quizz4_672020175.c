#include <stdio.h>

int Pangkat(int angka, int pangkat) {
    int hasil = 1;
    for (int i = 0; i < pangkat; i++) {
        hasil *= angka;
    }
    return hasil;
}

int main() {
    int bilangan, pangkat;

    printf("Masukan Bilangan: ");
    scanf("%d", &bilangan);
    printf("Masukan Pangkat: ");
    scanf("%d", &pangkat);

    while (getchar() != '\n');
    int hasilPangkat = Pangkat(bilangan, pangkat);
    printf("Hasil Pangkat : %d", hasilPangkat);

    getchar();

    return 0;
}