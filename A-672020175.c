#include <stdio.h>

void tampilkanarray(int array[], int panjang){
    for (int i = 0; i < panjang; i++){
        printf("Array index [%d] : %d \n", i, array[i]);
    }
}

void HitungNol(int array[], int panjang){
        int jumlah = 0;
        for (int i = 0; i < panjang; i++){
            if(array[i] == 0){
                jumlah++;
            }
    }
    printf("Jumlah Elemen 0 dalam array adalah : %d", jumlah);
}

void hasilkali3(int array[], int panjang){
    for (int i = 0; i < panjang; i++)
    {
     printf("Array index [%d] x 3 : %d \n", i, array[i]*3);
    }
}
int main(){ 

int array[5];

int panjang = sizeof(array)/sizeof(array[0]);
printf("\n");
for (int i = 0; i < panjang ; i++){ 
printf("Masukan Array index [%d] : ", i);
scanf("%d", &array[i]);
}
printf("\n");
tampilkanarray(array, panjang);
printf("\n");
hasilkali3(array, panjang);
printf("\n");
HitungNol(array, panjang);
printf("\n\n");
    return 0;
}