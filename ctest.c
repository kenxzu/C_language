
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void delay (int number_of_second){
    //converting to mili_second
    int mili_second = 1000 * number_of_second;
    // stroring start time 
    clock_t start_time = clock();

    // loopin till time requiered not achieved 
    while (clock()< start_time + mili_second);
    
    }

int main(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED);

    for (int i=1; i<=300;i++){

        printf(" i love yun \x03");

    delay(1);
}
}





    

