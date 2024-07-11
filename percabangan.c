#include <stdio.h> 

/*
A >= 85
AB >= 80
B >=  75
BC >=65
C >=55
CD >= 45
D >=35
E>35
*/


int main(){ 
int a ; 
printf("masukan angka : ");
scanf("%d",&a);


if(a >= 100){
    printf("umur panjang");
} 
    else if (a <  18)
{
    printf("remaja");
}else if (a >= 18 && a < 100)
{
 printf("dewasa");

}else{
    printf("masukan salah");
}

}





