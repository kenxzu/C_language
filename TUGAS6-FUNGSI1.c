#include <stdio.h>
//prototipe fungsi
int cekganjil(int x);
int main(){
int input, hasil;
printf("Masukan Input bilangan bulat : ");
scanf("%d",&input);
hasil = cekganjil(input);
if (hasil == 1){
printf("%d adalah bilangan ganjil", input);
}else{
printf("%d adalah bilangan genap", input);
}
return 0;
}
//defenisi fungsi
int cekganjil(int x){
if (x % 2 != 0){
return 1;
}else{
return 0;
}
}