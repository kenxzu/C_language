#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13


void delay(int x){
    int miliseken = 1000 * x;
    clock_t start_time = clock();
    while (clock() < start_time + miliseken);
    
}

int gotoxy(int x, int y){
    // Input
    COORD c;
    c.X = x;
    c.Y = y;
 
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// valadasi
int isLoginValid(char username[], char password[]) {
    // membuat usernama atau password
    char validUsername[] = "kenken";
    char validPassword[] = "admin";

    return (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0);
}


void getPassword(char *password, int maxLength) {
    int i = 0;
    while (i < maxLength - 1) {
        char ch = _getch(); 
        if (ch == 13) { 
            break;
        } else if (ch == 8) { 
            if (i > 0) {
                i--;
                printf("\b \b"); 
            }
        } else {
            password[i] = ch;
            printf("*"); 
            i++;
        }
    }
    password[i] = '\0'; 
}

// fungsi loginku
void login() {

   
    char username[20];
    char password[20];
     gotoxy(50, 10);
    printf("Enter username: ");
    scanf("%s", username);
    gotoxy(50, 11);
    printf("Enter password: ");
    getPassword(password, 20);

    if (isLoginValid(username, password)) {
        system("cls");
        gotoxy(50, 7);
        printf("Login Berhasil\n");
        delay(1);
    } else {
        system("cls");
         gotoxy(50, 7);
		printf("Masukan Username dan Password dengan Benar\n");
        login();
		 // memanggil login secara rekursiff jika username dan password salah
    }
}

#define MAX_MENU_ITEMS 100
#define MAX_ORDER_ITEMS 100

struct Order {
    char namaPembeli[50];
    char menu[MAX_MENU_ITEMS][50];
    int jumlah[MAX_MENU_ITEMS]; // misalkan 100 item untuk maksimal pemesanan
    float harga[MAX_MENU_ITEMS];
};

struct Order orders[100]; //misalkan max order 100 dulu

struct MenuItem {
    char name[50];
    double price;
};

struct MenuItem menu[] = {
{"Hors d'oeuvres", 90.000},
{"Amuse-bouhce", 100.000},
{"Salad", 200.000},
{"Coca-Cola", 150.000},
{"Palate Cleanser", 50.000}
};


void displayMenu() {
    gotoxy(50, 10);
    printf("Menu Restoran\n");
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        gotoxy(50, 11 + i);
        printf("%d. %s - Harga: Rp. %.3f\n", i + 1, menu[i].name, menu[i].price);
    }
}
struct Order orders[100];
int orderCount = 0;
void inputOrder() {
    printf("Masukkan nama pembeli: ");
    scanf(" %[^\n]", orders[orderCount].namaPembeli);
    system("cls");

    int selectedMenuCount = 0; // untuk menyimpan jumlah satu menu 

    while (selectedMenuCount < sizeof(orders[orderCount].menu) / sizeof(orders[orderCount].menu[0])) {
       
        pilih :
        displayMenu();
        gotoxy(50, 17);
        int menuChoice;
        int amount = 0;
        bool validInput = false;
        
        printf("Pilih Menu (tekan 0 untuk selesai memesan): ");
        if (scanf("%d", &menuChoice) == 1) {
            if (menuChoice == 0) {
                 gotoxy(50, 18);
                break; // Keluar dari menu
            } else if (menuChoice >= 1 && menuChoice <= sizeof(menu) / sizeof(menu[0])) {
                 inputjumlah :
                 gotoxy(50, 18);
                printf("Masukkan jumlah untuk menu %s: ", menu[menuChoice - 1].name);
              char ch;  
            bool enteredZero = false; // untuk menjaga-jaga user mengisikan 0;
        while (!validInput) {
        ch = _getch();

        if (ch == 13) {  // Enter key
            if (amount > 0) {
                validInput = true; // memberhentikan loop jika jumlah yang dimasukan > 0
            } else {
                 gotoxy(50, 19);
                printf("Jumlah Tidak Boleh 0");
                goto inputjumlah;
            }
        }

        if (ch == 8) {  // Backspace
            if (amount > 0) {
                amount = amount / 10;
                printf("\b \b");  // menghapus character
            }
        } else if (ch >= '0' && ch <= '9') { // menerima angka 0 - 9;
            amount = amount * 10 + (ch - '0');
            printf("%c", ch);  // Display the digit.
        }
    }
                       
 
            
                system("cls");
                int found = 0;
                // cek menu sudah dipilih?
                for (int i = 0; i < selectedMenuCount; ++i) {
                    if (strcmp(orders[orderCount].menu[i], menu[menuChoice - 1].name) == 0) {
                        // Menu telah dipilih sebelumnya, mengupdate jumlah/quantity dan harga
                        orders[orderCount].jumlah[i] += amount; //increment ajah
                        orders[orderCount].harga[i] += menu[menuChoice - 1].price * amount; // mengupdate harga total bang
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    // Mane belum dipilih tambahakan ke orderan
                    strcpy(orders[orderCount].menu[selectedMenuCount], menu[menuChoice - 1].name);
                    orders[orderCount].jumlah[selectedMenuCount] = amount; // Set jumlah/quatntity
                    orders[orderCount].harga[selectedMenuCount] = menu[menuChoice - 1].price * amount; // Set total price
                    selectedMenuCount++;
                }
            } else {
                system("cls");
                gotoxy(50, 7);
                printf("Pilihan menu tidak valid. Harap masukkan nomor menu yang valid.\n");
                goto pilih;
            }
        } else {
            int hindariloop;
            system("cls");
            gotoxy(50, 7);
            printf("Pilihan menu tidak valid. Masukan Angka jangan huruf atau symbol.\n");
            while ((hindariloop = getchar()) != '\n' && hindariloop != EOF) { }
            goto pilih;
        }
    }
    orderCount++; // lanjuuut ke order berikutnya. 
}

void displayNamaPelanggan() {
    if(orderCount == 0){
        gotoxy(50,10);
        printf("Tidak ada data\n");
        gotoxy(50, 13);
    }else{
    for (int i = 0; i < orderCount; i++) {
        char namaUpper[50];
        strcpy(namaUpper, orders[i].namaPembeli);
        for (int j = 0; namaUpper[j]; j++) {
            namaUpper[j] = toupper(namaUpper[j]);
        }
        gotoxy(50, 9+i);
        printf("Nama Pelanggan %d: %s\n",i+1, namaUpper);
    }
    gotoxy(50, 9+orderCount+2);
    }
}


void displayAllOrders() {

    if (orderCount == 0 ){
        gotoxy(50, 10);
        printf("Tidak Ada Data");
        gotoxy(50,13);
    }else{
            
            int Yitem = 10; //koordinat y order pertama
        for (int i = 0; i < orderCount; i++) {
            gotoxy(50, Yitem);
        printf("Order #%d - Nama: %s\n", i + 1, orders[i].namaPembeli);
        gotoxy(50, Yitem+1);
        printf("Items:\n");

        for (int j = 0; j < sizeof(orders[i].menu) / sizeof(orders[i].menu[0]); j++) {
            if (orders[i].menu[j][0] != '\0') { // Check if the menu item exists
                gotoxy(50,Yitem+2);
                printf("%s - Quantity: %d ", orders[i].menu[j], orders[i].jumlah[j]);
                Yitem++;
                gotoxy(50, Yitem);
            }
            
        }
        Yitem += 3;
    }

    gotoxy(50, Yitem + 2);

}
}
void displayInvoiceForOrder(int orderIndex) {
    system("cls");
        gotoxy(50, 7);
        printf("==========================================\n");
        gotoxy(50, 8);
        printf("       O'Oliver Restourant - Order #%d\n", orderIndex + 1);
        gotoxy(50, 9);
        printf("==========================================\n");
        gotoxy(50, 10);
        printf("Customer Name: %s\n", orders[orderIndex].namaPembeli);
        gotoxy(50, 11);
        printf("------------------------------------------\n");
        gotoxy(50, 12);
        printf(" Menu\t\t    Quantity    Price\n");
        gotoxy(50, 13);
        printf("------------------------------------------\n");

        int yPos = 14;

        //menampilkna rincian order dengan quantity dan harga totalnya
        for (int j = 0; j < sizeof(orders[orderIndex].menu) / sizeof(orders[orderIndex].menu[0]); j++) {
            gotoxy(50, yPos);
            if (orders[orderIndex].menu[j][0] != '\0') {
                printf(" %-20s%-4dRp%.3f,00-\n", orders[orderIndex].menu[j], orders[orderIndex].jumlah[j], orders[orderIndex].harga[j]);
                yPos++; //pindah baris
            }
        }

        gotoxy(50, yPos);
        printf("------------------------------------------\n");

        //hitung dan tampilkan harga total order
        float total = 0;
        for (int j = 0; j < sizeof(orders[orderIndex].harga) / sizeof(orders[orderIndex].harga[0]); j++) {
            total += orders[orderIndex].harga[j];
        }
        gotoxy(50, yPos + 1);
        printf("Total: \t\tRp%.3f,00-\n", total);
        gotoxy(50, yPos + 2);
        printf("------------------------------------------\n");
         
        gotoxy(50, yPos + 4);

}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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
        system("cls");
        gotoxy(50,7);
        printf("Pilih Fitur:\n");
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
        int ch = _getch();  // manengkap satu karakter
    
        switch (ch) {
            case KEY_UP:
                choice = (choice - 1 + maxChoice) % maxChoice;
                break;
            case KEY_DOWN:
                choice = (choice + 1) % maxChoice;
                break;
            case KEY_ENTER:

                system("cls");
                gotoxy(50,7);
                printf("Menu Pesan");
				 if(choice == 0){ 
              
                    gotoxy(50,10);
                        inputOrder();

				}else if(choice == 1){
                    gotoxy(50,7);
                    printf("Riwayat Pelanggan");
                    displayNamaPelanggan();
				}else if(choice ==2){
                    gotoxy(50,7);
                    printf("Semua Pesanan");
                    displayAllOrders();
                    
				}else if(choice == 3) { 
                      menucetak :
                    gotoxy(50,7);
                    printf("Menu Cetak Struk");
                    int x;
                      if (orderCount == 0){
                        gotoxy(50,10);
                        printf("Tidak ada data");
                        gotoxy(50, 13);
                    }else{
                            for (int i = 0; i < orderCount; i++) {
                                gotoxy(50, 10+i);
                                printf("%d. %s\n", i + 1, orders[i].namaPembeli);
                         }
				}
                gotoxy(50, 10 + orderCount + 2);
                printf("Masukkan nomor pelanggan: ");
                if (scanf("%d", &x) != 1 || x <= 0 || x > orderCount) {
                    gotoxy(50, 10 + orderCount + 4);
                    printf("Invalid input\n");
                    clearBuffer();
                    goto menucetak;
                } else {
                    displayInvoiceForOrder(x - 1);
                }
                    }
                else if (choice == 4){
					gotoxy(50,7);                    
                    printf("Kesan dan pesan Untuk Asdos\n\n");
                    gotoxy(50,10);  
                     printf("Kelasnya sangat menarik dan tidak menegangkan dan juga tidak pelit nilai\n");
                    gotoxy(50,11);  
                    printf("Akhir kata Terimakasih Vincent dan Hosea selama satu semester\n\n");
                     gotoxy(50,12); 
				}else if(choice == 5){
                       gotoxy(50,7);
                    printf("Developer");
                    gotoxy(50,10);
                    printf("Nama\t: KEN FOSTER MORINTOH\n");
                    gotoxy(50,11);
					printf("NIM\t: 672020175\n\n\n\n");
                    delay(5);
                    exit(0);
                }
			
				printf("Press any key to continue ...");
                _getch(); 
                break;
            default:
                break;
        }
	}
}
int main() {
  
    login(); 
	fitur();
    return 0;
}




