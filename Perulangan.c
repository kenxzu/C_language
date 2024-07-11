//for loop
#include<stdio.h> 

int main(){ 
int n;
printf("n : ");
scanf("%d", &n);
printf("\n");
    for (int i = 1; i < n;i++){
        for(int j = n; j>i; j--){
            printf("%d", i);
        }
        printf("\n");
    } 
}