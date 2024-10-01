#include <stdio.h>

int main() {
    int X, Y, N;

    scanf("%d %d %d", &X, &Y, &N);
	// habis dibahagi x dan y (ganti BOMDUARR)
	//habis dibahagi x (ganti bom ya ken)
	//habis dibahagi y (gantiDuarrr)
    for (int i = 1; i <= N; i++) {
        if (i % X == 0 && i % Y == 0) { 
            printf("BOMDUARR\n");
        } else if (i % X == 0) { 
            printf("BOM\n"); 
        } else if (i % Y == 0) {
            printf("DUARR\n"); 
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}


