#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13


int gotoxy(int x, int y){
    // Input
    COORD c;
    c.X = x;
    c.Y = y;
 
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// Function to check if the provided username and password are valid
int isLoginValid(char username[], char password[]) {
    // Define a valid username and password
    char validUsername[] = "myusername";
    char validPassword[] = "mypassword";

    return (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0);
}


void getPassword(char *password, int maxLength) {
    int i = 0;
    while (i < maxLength - 1) {
        char ch = _getch(); // Windows-specific
        if (ch == 13) { // Enter key
            break;
        } else if (ch == 8) { // Backspace
            if (i > 0) {
                i--;
                printf("\b \b"); // Erase the character from the screen
            }
        } else {
            password[i] = ch;
            printf("*"); // Mask the character with an asterisk
            i++;
        }
    }
    password[i] = '\0'; // Null-terminate the password
}

// Function to perform the login process
void login() {

   
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);
    gotoxy(50, 11);
    printf("Enter password: ");
    getPassword(password, 20);

    if (isLoginValid(username, password)) {
        printf("Login successful!\n");
    } else {
        system("cls");
		printf("Invalid username or password. Please try again.\n");
        login();
		 // Recursively call login() if the credentials are incorrect
    }
}

// void takeint(){

//     int num = 0;
//     char ch;

//     printf("Enter an integer: ");

//     while (1) {
//         ch = _getch();

//         if (ch == 13) {  // Enter key
//             break;
//         }

//         if (ch == 8) {  // Backspace
//             if (num > 0) {
//                 num = num / 10;
//                 printf("\b \b");  // Erase the last character on the screen.
//             }
//         } else if (ch >= '0' && ch <= '9') {
//             num = num * 10 + (ch - '0');
//             printf("%c", ch);  // Display the digit.
//         }
//     }

//     printf("\nYou entered: %d\n");


// }


/*INI DARI CHAT GPT*/
struct Order {
    char namaPembeli[50];
     char menu[50];
    int jumlah; // Assuming a maximum of 100 items in one order
    float harga;
};

struct Order orders[100]; 


struct MenuItem {
    char name[50];//Assuming a maximum of 100 items in one order.
    double price;
};

struct MenuItem menu[] = {
{"Oti Fried chicken", 10.99},
{"Frech fries", 8.49},
{"nashvhille chiken", 12.79},
{"sushi by yunita sania", 15.00}
};


void displayMenu() {
   
    printf("Menu Restoran\n");
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        gotoxy(50, 10 + i+1);
        printf("%d. %s - Harga: %.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}
struct Order orders[100];
int orderCount = 0;

void inputOrder() {
     
    printf("Masukkan nama pembeli: ");
    scanf(" %[^\n]", orders[orderCount].namaPembeli);
    system("cls");

    int menuChoice;
    displayMenu();
    while (1) {
    printf("\n\nPilih Menu : ");
    if (scanf("%d", &menuChoice) == 1) {
        if (menuChoice >= 1 && menuChoice <= sizeof(menu) / sizeof(menu[0])) {
        strcpy(orders[orderCount].menu, menu[menuChoice - 1].name);
        orders[orderCount].harga =menu[menuChoice - 1].price;
            break; // Valid input, exit the loop
        } else {
            system("cls");
            printf("Pilihan menu tidak valid. Harap masukkan nomor menu yang valid.\n");
            displayMenu();
        
        }
    } else {
        system("cls");
             
            printf("Pilihan menu tidak valid. Masukan Angka jangan huruf atau symbol.\n");
            displayMenu();
    }
}

int num = 0;
char ch;
  
printf("Jumlah pesanan: ");
while (1) {
    ch = _getch();

    if (ch == 13) {  // Enter key
        break;
    }

    if (ch == 8) {  // Backspace
        if (num > 0) {
            num = num / 10;
            printf("\b \b");  // Erase the last character on the screen.
        }
    } else if (ch >= '0' && ch <= '9') {
        num = num * 10 + (ch - '0');
        printf("%c", ch);  // Display the digit.
    }
}
   orders[orderCount].jumlah = num;

//printf("\nYou entered: %d\n", num);


//     int num = 0;
//     char ch;

//     printf("Enter an integer: ");

//     while (1) {
//         ch = _getch();

//         if (ch == 13) {  // Enter key
//             break;
//         }

//         if (ch == 8) {  // Backspace
//             if (num > 0) {
//                 num = num / 10;
//                 printf("\b \b");  // Erase the last character on the screen.
//             }
//         } else if (ch >= '0' && ch <= '9') {
//             num = num * 10 + (ch - '0');
//             printf("%c", ch);  // Display the digit.
//         }


//     printf("\nYou entered: %d\n");

// }
    
    // printf("Harga per item: ");  
     
      system("cls");
       
    printf("\n\nOrderMu\n");
        printf("Menu: %s\n", menu[menuChoice - 1].name);
        printf("Price per item (per porsi): %.2f\n", menu[menuChoice - 1].price);
        printf("Quantity: %d\n", orders[orderCount].jumlah);
        printf("Total Price: %.2f\n", orders[orderCount].jumlah * menu[menuChoice - 1].price);
        printf("\n");

    printf("Konfirmasi pilihan : ");
    char konfirmasi;
    scanf(" %c", &konfirmasi);

    if (konfirmasi == 'Y' || konfirmasi == 'y') {
    // The customer confirmed the order
    orderCount++;
    printf("Order confirmed and added to the list.\n");
    } else {
    // The customer did not confirm the order
    printf("Order not confirmed. It won't be added to the list.\n");
    }
    // scanf("%f", &orders[orderCount].harga);
    // Access the price per item (per porsi) and total price for each order
// for (int i = 0; i < orderCount; i++) {
//     printf("Order %d:\n", i + 1);
//     printf("Menu: %s\n", orders[i].menu);
//     printf("Price per item (per porsi): %.2f\n", menu[i].price);
//     printf("Quantity: %d\n", orders[i].jumlah);
//     printf("Total Price: %.2f\n", orders[i].harga * orders[i].jumlah);
//     printf("\n");
// }
    char pesanLagi;
    printf("Pesan lagi? (Y/N): ");
    scanf(" %c", &pesanLagi);
    if (pesanLagi == 'Y' || pesanLagi == 'y') {
        inputOrder();
    }
}

void displayNamaPelanggan() {
    if(orderCount == 0){
        printf("Tidak ada data\n\n");
    }else{
    for (int i = 0; i < orderCount; i++) {
        char namaUpper[50];
        strcpy(namaUpper, orders[i].namaPembeli);
        for (int j = 0; namaUpper[j]; j++) {
            namaUpper[j] = toupper(namaUpper[j]);
        }
        printf("Nama Pelanggan: %s\n", namaUpper);
    }
    }
}

void displayOrderan() {
    if (orderCount == 0){
        printf("Tidak ada data\n\n");
    }else{
         for (int i = 0; i < orderCount; i++) {
        printf("%d. %s\n", i+1, orders[i].namaPembeli);
        printf("Menu   : %s\n",orders[i].menu);
        printf("Jumlah : %d\n\n", orders[i].jumlah);
    }
}
}


void cetakStruck(int x){
    if ( x >= 0 && x <= orderCount) {
     printf("Pelanggan: %s, Menu: %s, Jumlah: %d, Harga per pcs : %0.2f, Total : %0.2f\n",
               orders[x-1].namaPembeli, orders[x-1].menu, orders[x-1].jumlah, menu[x-1].price, orders[x-1].jumlah * menu[x - 1].price);
    } else {
        printf("Nomor pelanggan tidak valid.\n");
    }

}


// void printOrders(struct MenuItem menu[], struct Order orders[], int orderCount) {
//     printf("SAVED ORDERS:\n");
//     for (int i = 0; i < orderCount; i++) {
//         printf("Visitor: %s\n", orders[i].visitorName);
//         printf("ORDER:\n");
//         for (int j = 0; j < orders[i].itemCount; j++) {
//             int index = orders[i].items[j];
//             printf("%s - $%.2f\n", menu[index].name, menu[index].price);
//         }
//         printf("\n");
//     }
// }
// void takeOrder(struct MenuItem menu[], int itemCount, struct Order orders[], int *orderCount) {
//     struct Order order;
//     printf("Enter your name: ");
//     scanf("%[^\n]s", order.visitorName);
    
//     system("cls");
//     displayMenu(menu, itemCount);
//     order.itemCount = 0;

//     while (1) {
//         int choice;
//         printf("Enter the item number (0 to finish order): ");
//         scanf("%d", &choice);

//         if (choice == 0) {
//             break;
//         }

//         if (choice < 1 || choice > itemCount) {
//             printf("Invalid choice. Please select a valid item.\n");
//         } else {
//             order.items[order.itemCount] = choice - 1; // Store the index of the selected item
//             order.itemCount++;
//         }
//     }

//     orders[(*orderCount)++] = order;
// }

void fitur(){ 
 int choice = 0;
    int maxChoice = 6;
	char*  menuOptions[] = {
        "Pesan Menu",
        "Data Pengunjung",
        "Semua Data",
        "Cetak Struck",
		"Pesan dan Kesan Asdos",
        "Exit"
    };

    while (1) {
        system("cls");  // Clear the screen (Windows specific)
        
        printf("Select an option:\n");
        for (int i = 0; i < maxChoice; i++) {
            gotoxy(50,11);
            if (i == choice) {
                 gotoxy(50,11+i);
                printf("--> %d.%s\n", i+1, menuOptions[i]);
            } else {
                 gotoxy(50,11+i);
                printf("   %d.%s\n", i+1, menuOptions[i]);
            } 
		
        }
        

    

    
        int ch = _getch();  // Capture a single character

        //Check the key pressed
    
        
        switch (ch) {
            case KEY_UP:
                choice = (choice - 1 + maxChoice) % maxChoice;
                break;
            case KEY_DOWN:
                choice = (choice + 1) % maxChoice;
                break;
            case KEY_ENTER:
                system("cls");
                printf("You selected Menu Item %d\n", choice + 1);
				 if(choice == 0){ 
                        inputOrder();

                    
                        //  struct MenuItem menu[] = {
                        // {"Oti Fried chicken", 10.99},
                        // {"Frech fries", 8.49},
                        // {"nashvhille chiken", 12.79},
                        // };
				// 		 int itemCount = sizeof(menu) / sizeof(menu[0]);
                         // Assuming a maximum of 100 orders
                //         int orderCount = 0;
               
                // takeOrder(menu, itemCount, orders, &orderCount);
              

                 
				}else if(choice == 1){
                    displayNamaPelanggan();
				}else if(choice ==2){
                        displayOrderan();
                    
				}else if(choice == 3) { 
                     int x;
                      if (orderCount == 0){
                        printf("Tidak ada data\n\n");
                    }else{
                            for (int i = 0; i < orderCount; i++) {
                            printf("%d. %s\n", i + 1, orders[i].namaPembeli);

                         }
				}
                printf("\n\nMasukkan nomor pelanggan: ");
                    scanf("%d", &x);
                    cetakStruck(x);}
                else if (choice == 4){
					
				}else if(choice == 5){
                    printf("Nama\n");
					printf("NIM\n");
                    printf("Press any key to continuee");
					getch();
					exit(0);
                }
			
                //Add your code to handle the selected menu item here
				printf("Press any key to continue ...");
                _getch(); // Wait for a key press before returning to the menu
                break;
            default:
                break;
        }
	}
}
	

        // if (ch == 72 && choice > 1) {  // Up arrow key (ASCII 72)
        //     choice--;
        // } else if (ch == 80 && choice < maxChoice) {  // Down arrow key (ASCII 80)
        //     choice++;
        // } else if (ch == 13) {  // Enter key (ASCII 13) to select an option
        //     printf("\nYou selected Option %d. Press any key to continue...", choice);
        //     _getch();  // Wait for a key press
        // }
  



// Function to display the menu

//main functionnnnn... 
int main() {
  
    login(); 
    // Start the login process
    //takeint();
	fitur();

    //   struct Person people[50]; // Array of structs to store names
    // int count = 0;


    // takeName(people, &count); // Enter names
    
    // int specificIndex; // Index of the specific person you want to print
    // printf("Enter the index of the person you want to print: ");
    // scanf("%d", &specificIndex);

    // if (specificIndex >= 0 && specificIndex < count) {
    //     displayPerson(&people[specificIndex]);
    // } else {
    //     printf("Invalid index. Person not found.\n");
    // }

    return 0;
}




