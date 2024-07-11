#include <stdio.h>


int main(){
    //(---FOR LOOP---)//
// for ( int i = 10; i > 0; i--)
// {
//     printf("%d\n", i);
// }

//(---WHILE LOOP---)//
// int n = 10;
// while (n<0)
// {
    
//     printf("%d\n",n);
//     n--;
    
// }


 //(---DO WHILE---)//
//  int n = 10; 
//  do {
//     printf("%d\n",n);
//     n--;
//  }while (n>0);



/*(--NESTED FOR--)*/
// int n;
// printf("masukan n : ");
// scanf("%d",&n);

// for (int i = 1; i<=n; i++)
// {
//     for (int j = 1; j <= i; j++)
//     {
//         printf("*");
//     }
//     printf("\n");
// }
// SEGITA NUMERIC
 int n; 
    printf("\033[3m"); 
            printf("ini dalah akuu");
             printf("\033[0m");
 printf("masukan angka : ");
 scanf("%d", &n);
 
 for (int i = 1; i<=n; i++){
     for(int j = n-1; j>=i; j--){
         printf("%d", i);
     }
     printf("\n");
 }
 


 return 0;

}