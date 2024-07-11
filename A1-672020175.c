#include <stdio.h>

int bagiDua(int a);

int main (){
    int x;
    printf("\n\nMasukan nilai interger : ");
    scanf("%d",&x);
    bagiDua(x);

    return 0;
}

int bagiDua(int a){
    int hasil;
    if (a % 2 == 0){
        hasil = a/2;
        printf("\n\nBilangan dibagi 2 dari %d adalah %d \n\n", a, hasil);
    }else{
        hasil = a * a * a;
        printf("\n\nBilangan dikalikan dengan 3 nilai=  %d\n\n", hasil);
    }

}



