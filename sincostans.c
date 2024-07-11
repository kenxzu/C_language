// #include <stdio.h>
// #include <windows.h>

           
// int main() {     

//            int n;
//             printf("Masukan Tinggi : ");
//             scanf("%d",&n); 
//         for(int i = 0; i <= n ; i++){
//                 for (int j = 0; j <= n - i; j++){
//                     printf("* ");
//                 }
//                 printf("\n");
//            }
// } 

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

int main() {
    int choice = 0;
    int totalItems = 3; // Change this to match the number of menu items
    int key;

    while (1) {
        system("cls"); // Clear the screen

        // Print menu items
        for (int i = 0; i < totalItems; i++) {
            if (i == choice) {
                printf("-> Menu Item %d\n", i + 1);
            } else {
                printf("   Menu Item %d\n", i + 1);
            }
        }

        key = _getch(); // Get a key press

        // Check the key pressed
        switch (key) {
            case KEY_UP:
                choice = (choice - 1 + totalItems) % totalItems;
                break;
            case KEY_DOWN:
                choice = (choice + 1) % totalItems;
                break;
            case KEY_ENTER:
                system("cls");
                printf("You selected Menu Item %d\n", choice + 1);
                // Add your code to handle the selected menu item here
                _getch(); // Wait for a key press before returning to the menu
                break;
            default:
                break;
        }
    }

    return 0;
}
