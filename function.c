 #include <stdio.h>

float kuadrat (float a);

int max(int a, int b );

int main(){
    int num1, num2,  output;

    printf("Find the max number of two interger \n");
    printf("Masukan Num 1 : ");
    scanf("%d", &num1);
     printf("Masukan Num 1 : ");
    scanf("%d", &num2);
   output = max(num1, num2);
    printf("Nilai terbesar adalah %d", output);

    return 0;
}

float kuadrat(float a){
    float hasil;
    hasil = a * a;
    return(hasil);
}

int max(int a, int b){
    int hasil;
    if (a > b){
        return a;
    }else if (a < b) {
        return b;
    }else{
        printf("salah inputan");
    }
   
}
