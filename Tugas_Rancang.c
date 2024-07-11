#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct MenuItems {
    char name[50]; //Assuming a maximum of 100 items in one order.
    double price;
};

struct MenuItems menu[] = {
{"Oti Fried chicken", 10.99},
{"Frech fries", 8.49},
{"nashvhille chiken", 12.79},
{"sushi by yunita sania", 15.00}
};

void displayMenu() {
    printf("\nMenu Restoran\n");
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        printf("%d. %s - Harga: %.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}
struct Order {
    char namaPembeli[50];
    char menu[50];
    int jumlah;
    float harga;
};

struct Order orders[100];
int orderCount = 0;

void inputOrder() {
    printf("Masukkan nama pembeli: ");
    scanf(" %[^\n]", orders[orderCount].namaPembeli);
    system("cls");

    int menuChoice;
    displayMenu();
    printf("\n\nPilih Menu");
    scanf("%d", &menuChoice);
    if (menuChoice >= 1 && menuChoice <= sizeof(menu) / sizeof(menu[0])) {
        strcpy(orders[orderCount].menu, menu[menuChoice - 1].name);
        orders[orderCount].harga =menu[menuChoice - 1].price;
    } else {
        printf("Pilihan menu tidak valid.\n");
        return;
    }
    printf("Jumlah pesanan: ");
    scanf("%d", &orders[orderCount].jumlah);
    printf("Harga per item: ");
    scanf("%f", &orders[orderCount].harga);
    orderCount++;
    char pesanLagi;
    printf("Pesan lagi? (Y/N): ");
    scanf(" %c", &pesanLagi);
    if (pesanLagi == 'Y' || pesanLagi == 'y') {
        inputOrder();
    }
}

void displayNamaPelanggan() {
    for (int i = 0; i < orderCount; i++) {
        char namaUpper[50];
        strcpy(namaUpper, orders[i].namaPembeli);
        for (int j = 0; namaUpper[j]; j++) {
            namaUpper[j] = toupper(namaUpper[j]);
        }
        printf("Nama Pelanggan: %s\n", namaUpper);
    }
}

void displayOrderan() {
    for (int i = 0; i < orderCount; i++) {
        printf("Pelanggan: %s, Menu: %s, Jumlah: %d, Harga: %.2f\n",
               orders[i].namaPembeli, orders[i].menu, orders[i].jumlah, orders[i].harga);
    }
}

void cetakStruk(int index) {
    printf("Struk untuk Pelanggan: %s\n", orders[index].namaPembeli);
    printf("Menu: %s, Jumlah: %d\n", orders[index].menu, orders[index].jumlah);
    printf("Harga Total: %.2f\n", orders[index].harga * orders[index].jumlah);
}

int main() {
    int choice;
    do {
        printf("\nMenu Restoran\n");
        printf("1. Order\n");
        printf("2. Tampilkan Nama Pelanggan\n");
        printf("3. Tampilkan Orderan\n");
        printf("4. Cetak Struk\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputOrder();
                break;
            case 2:
                displayNamaPelanggan();
                break;
            case 3:
                displayOrderan();
                break;
            case 4:
             {
    int pelangganIndex;
    printf("Masukkan nomor pelanggan: ");
    scanf("%d", &pelangganIndex);
    if (pelangganIndex >= 0 && pelangganIndex < orderCount) {
        cetakStruk(pelangganIndex);
    } else {
        printf("Nomor pelanggan tidak valid.\n");
    }
    break;
}

            case 5:
                printf("Terima kasih!");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (choice != 5);

    return 0;
}




// void menuPesanan(){
//     int code, jumlah, harga_total, harga_satuan ;
//     harga_total = code * jumlah; 
//     char lagi;
//     do{
//     printf("Menu\n");
//     printf("1. spicy fried chicken\n");
//     printf("2. spicy fried chicken\n");
//     printf("3. spicy fried chicken\n");
//     printf("4. spicy fried chicken\n\n");
//     printf("masukan code menu : ");
//     scanf("%d", &code);
//     printf("\nMau Pesan Berapa : " );
//     scanf("%d",&jumlah);
//     switch (code)
//     {
//     case 1 :
//         harga_satuan  = 12000;
//         break;
//          case 2 :
//         harga_satuan  = 12000;
//         break;
//          case 3 :
//         harga_satuan  = 12000;
//         break;
//          case 4 :
//         harga_satuan  = 12000;
//         break;
    
//     default:
//         printf("Masukan inputan yang benar");
//         break;
//     }
//     harga_total = harga_satuan * jumlah;
//     printf("Harga total %d * %d = %d\n\n", jumlah, harga_satuan, harga_total);
//     printf("Apakah mau pesan lagi (y/n) ? ");
//     scanf("%d", &lagi);
//     }while(lagi != 1 || lagi >=1);

// }

// struct Person {
//     char name[50];
//     char alamat[20];
// };

// void takeName(struct Person people[], int* count) {
//     char name[50];
//     char alamat[50];
//     int n;
//         do{
//         printf("Masukan Nama: ");
//         scanf(" %[^\n]", name);
//         strcpy(people[(*count)].name, name);
        
//           printf("Masukan Alamat: ");
//         scanf(" %[^\n]", alamat); // Use %[^\n] to read the whole line as address
//         strcpy(people[(*count)].alamat, alamat);
//         (*count)++;

//         printf("Lagi? (0 for no, any other number for yes): ");
//         scanf("%d", &n);
//         }while (n != 0);
// } 


// void displayNama(struct Person people[], int count) {
//  printf("Daftar Orang:\n");

//     for (int i = 0; i < count; i++) {
//         printf("Nama: %s\n", people[i].name);
//         printf("Alamat: %s\n", people[i].alamat);
//         printf("\n");
//     }
// }