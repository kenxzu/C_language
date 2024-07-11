#include <stdio.h> 

//welcome to operrasi matrik 






int main (){


int arrayku[2][3];

printf ("ini adalah arraykyy\n\n");

for (int i = 0; i < 2; i++){
    for(int j = 0; j  < 3 ; j++)
    {
        printf("matriks elemen [%i][%i] = ", i, j);
        scanf("%d",&arrayku[i][j]);
    }
    
}

printf("\n\n\arraymu adalah \n\n");
for (int i = 0; i < 2; i++)
{
    for(int j =  0; j < 3; j++){
        printf("matriks M[%d][%d] = %d\n", i,j, arrayku[i][j]);
    } 
}











return 0;    
}