#include <stdio.h>
//KEN FOSTER MORINTOH//672020175//
int main() {
    int F, B, total; 
    int tiga = 0, empat= 0;

    scanf( "%d %d", &F, &B);

		//inpalit jika F lebih beser
    if (F > B) {
        printf("invalid \n");
        return 1;
    }

    for (int i = F; i <= B; i++) {
        
        int last_digit = i % 10;
		//menhitung angka akhiran 3 dan 4 
        if (last_digit == 3) {
            tiga++; 
        } else if (last_digit == 4) {
            empat++;
        }
    }
    total = tiga + empat; // kalkulasi total kamar yang harus dihindari

	printf("%d",total);

    return 0;
}
//2023
