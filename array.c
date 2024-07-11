#include <stdio.h>



int main()
{
    
   printf("index");
    printf ("\tNilai\t");
    printf("Bintang\n");
    for(int i = 0; i < 9; i++){
        printf("%d", i);
        int nilai;
       printf("\t");
        scanf("%d", &nilai);
        //int x[3][nilai];
        for(int j = 0; j<nilai; j++){ 
            //printf("\t\t");
          printf("*");
        }
    
        printf("\n");
    }
}
    
    