#include <stdio.h>


int main(){

// program cek angak itu habis dibagi 2(x) dan 3(y)

int n, x = 2 , y =3 ;
printf("Masukan angka : ");
scanf("%d", &n);

if(n % 2 == 0 && n % 3 >= 1){
    printf("%d habis dibagi %d tetapi tidak habis dibagi %d\n\n" , n,x,y);
}else if(n % 2 >= 1 && n % 3 == 0 ){
    printf("%d tidak habis dibagi %d tetapi habis dibagi %d\n\n", n,x,y);
}else if(n % 2 == 0 && n % 3 == 0){
    
    printf("%d habis dibagi %d dan %d\n\n", n, x, y);

}else{
    printf("%d tidak habis dibagi %d maupun %d\n\n", n, x, y);
}


return 0;
}
