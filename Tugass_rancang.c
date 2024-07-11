#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define COMPUTER 1 
#define HUMAN 2 
#define SIDE 3 
#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X' 

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
/*PROGRAM 
GAMEGAME*/
struct Move { 
    int row, col; 
}; 
  
char player = 'x', opponent = 'o'; 
//fungsi ini mengembalikan true jika tidak ada value disana begitpula sebaliknya
bool isMovesLeft(char board[3][3]) 
{ 
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            if (board[i][j] == '_') 
                return true; 
    return false; 
} 

int evaluate(char b[3][3]) 
{ 
    // Cek baris siapa yang menang
    for (int row = 0; row < 3; row++) { 
        if (b[row][0] == b[row][1] 
            && b[row][1] == b[row][2]) { 
            if (b[row][0] == player) 
                return +10; 
            else if (b[row][0] == opponent) 
                return -10; 
        } 
    } 
  
    // cek kolom siapa yang menang
    for (int col = 0; col < 3; col++) { 
        if (b[0][col] == b[1][col] 
            && b[1][col] == b[2][col]) { 
            if (b[0][col] == player) 
                return +10; 
  
            else if (b[0][col] == opponent) 
                return -10; 
        } 
    } 
  
    // cek diagonal
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) { 
        if (b[0][0] == player) 
            return +10; 
        else if (b[0][0] == opponent) 
            return -10; 
    } 
  
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) { 
        if (b[0][2] == player) 
            return +10; 
        else if (b[0][2] == opponent) 
            return -10; 
    } 
  
    // return 0 jika salah satu dari mereka menang.
    return 0; 
} 
  
// This is the minimax function. It considers all 
// the possible ways the game can go and returns 
// the value of the board 
int minimax(char board[3][3], int depth, bool isMax) 
{ 
    int score = evaluate(board); 
  
    //jika menang akan mendaptkan skor 10 
    if (score == 10) 
        return score; 

    //jika kalah maka kan dikurangin
    if (score == -10) 
        return score; 
  
    // jika tidak ada moves lagi

    if (isMovesLeft(board) == false) 
        return 0; 
  
    // If this maximizer's move 
    if (isMax) { 
        int best = -1000; 
  
        // telusuri kotak 
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < 3; j++) { 
                // cek kotak jika kosong 
                if (board[i][j] == '_') { 
                    // jalan selanjutnya 
                    board[i][j] = player; 
                    int val 
                        = minimax(board, depth + 1, !isMax); 
                    if (val > best) { 
                        best = val; 
                    } 
  
                    // tarik langka yang dibuat
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    } 
  
    // If this minimizer's move 
    else { 
        int best = 1000; 
  
        // telusi kotak  
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < 3; j++) { 
                // Check if cell is empty 
                if (board[i][j] == '_') { 
                    // Make the move 
                    board[i][j] = opponent; 
  
                    // Call minimax recursively and choose 
                    int val 
                        = minimax(board, depth + 1, !isMax); 
                    if (val < best) { 
                        best = val; 
                    } 
                    // Undo the move 
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    } 
} 
  
//  
struct Move findBestMove(char board[3][3]) 
{ 
    int bestVal = -1000; 
    struct Move bestMove; 
    bestMove.row = -1; 
    bestMove.col = -1; 
  

    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            // Check if cell is empty 
            if (board[i][j] == '_') { 
                // membuat langkah
                board[i][j] = player; 
  
                int moveVal = minimax(board, 0, false); 
  
                board[i][j] = '_'; 
  
               
                if (moveVal > bestVal) { 
                    bestMove.row = i; 
                    bestMove.col = j; 
                    bestVal = moveVal; 
                } 
            } 
        } 
    } 
  
    // printf("The value of the best Move is : %d\n\n", 
    //       bestVal); 
  
    return bestMove; 
} 
  
// -----------------------------------AI selesai menganalisa
  
// Function to display the game board 
void showBoard(char board[][SIDE]) 
{ 
    printf("\n\n"); 
    printf("\t\t\t %c | %c | %c \n", board[0][0], 
           board[0][1], board[0][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t %c | %c | %c \n", board[1][0], 
           board[1][1], board[1][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t %c | %c | %c \n\n", board[2][0], 
           board[2][1], board[2][2]); 
} 
  
// Function to show the instructions 
void showInstructions() 
{ 
    printf("\t\t\t Game Game\n\n"); 
    printf("pilih kotak yang ada dibawah berdasarkan nomor"
           "dan mainkan\n\n"); 
  
    printf("\t\t\t 1 | 2 | 3 \n"); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t 4 | 5 | 6 \n"); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t 7 | 8 | 9 \n\n"); 
  
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n"); 
} 
  
// inisiasi game
void initialise(char board[][SIDE], int moves[]) 
{ 
    srand(time(NULL)); 
  
    // kosongkan kotak
    for (int i = 0; i < SIDE; i++) { 
        for (int j = 0; j < SIDE; j++) 
            board[i][j] = ' '; 
    } 
  
    // masukan langkh
    for (int i = 0; i < SIDE * SIDE; i++) 
        moves[i] = i; 
  
    // random langka
    for (int i = 0; i < SIDE * SIDE; i++) { 
        int randIndex = rand() % (SIDE * SIDE); 
        int temp = moves[i]; 
        moves[i] = moves[randIndex]; 
        moves[randIndex] = temp; 
    } 
} 
  
// funsi menampilka siapa yang menang
void declareWinner(int whoseTurn) 
{ 
    if (whoseTurn == COMPUTER) {
        printf("LEMAH!!!\n"); 
    }else{
        printf("Kesan dan pesan Untuk Asdos\n\n");
        printf("Kelasnya sangat menarik dan tidak menegangkan dan juga tidak pelit nilai\n");
        printf("Akhir kata Terimakasih Vincent dan Hosea selama satu semester ini\n\n");
    }
} 
  
//fungsi cek kotak dimanapun sudah dimasukan player

int rowCrossed(char board[][SIDE]) 
{ 
    for (int i = 0; i < SIDE; i++) { 
        if (board[i][0] == board[i][1] 
            && board[i][1] == board[i][2] 
            && board[i][0] != ' ') 
            return 1; 
    } 
    return 0; 
} 
  
//fungsi cek kolom jika diagonal sudah dimasukan player

int columnCrossed(char board[][SIDE]) 
{ 
    for (int i = 0; i < SIDE; i++) { 
        if (board[0][i] == board[1][i] 
            && board[1][i] == board[2][i] 
            && board[0][i] != ' ') 
            return 1; 
    } 
    return 0; 
} 



//fungsi cek diagonal jika diagonal sudah dimasukan player

int diagonalCrossed(char board[][SIDE]) 
{ 
    if ((board[0][0] == board[1][1] 
         && board[1][1] == board[2][2] 
         && board[0][0] != ' ') 
        || (board[0][2] == board[1][1] 
            && board[1][1] == board[2][0] 
            && board[0][2] != ' ')) 
        return 1; 
  
    return 0; 
} 
  
// cek game over
int gameOver(char board[][SIDE]) 
{ 
    return (rowCrossed(board) || columnCrossed(board) 
            || diagonalCrossed(board)); 
} 
  
void mulaigame(int whoseTurn)
{ 
    // 3 * 3 game
    char board[SIDE][SIDE]; 
    int moves[SIDE * SIDE]; 
  
    //memulai permainan
    initialise(board, moves); 
  
    // innstruksii
    showInstructions(); 
  
    int moveIndex = 0, x, y; 
  
    while (!gameOver(board) && moveIndex != SIDE * SIDE) { 
        if (whoseTurn == COMPUTER) { 
  
            char tempBoard[3][3]; 
            for (int i = 0; i < 3; i++) { 
                for (int j = 0; j < 3; j++) { 
                    if (board[i][j] == 'X') { 
                        tempBoard[i][j] = 'x'; 
                    } 
                    else if (board[i][j] == 'O') { 
                        tempBoard[i][j] = 'o'; 
                    } 
                    else { 
                        tempBoard[i][j] = '_'; 
                    } 
                } 
            } 
            struct Move thisMove = findBestMove(tempBoard); 
            x = thisMove.row; 
            y = thisMove.col; 
  
            board[x][y] = COMPUTERMOVE; 
            printf("COMPUTER meletakan %c didalam cell %d %d\n",COMPUTERMOVE, x, y); 
            showBoard(board); 
            moveIndex++; 
            whoseTurn = HUMAN; 
        } 
        else if (whoseTurn == HUMAN) { 
            int move; 
            printf("masukan langkahmu (1-9): "); 
            scanf("%d", &move); 
            if (move < 1 || move > 9) { 
                printf("Invalid input! Masukan "
                       "angka diantara 1 dan 9.\n"); 
                continue; 
            } 
            x = (move - 1) / SIDE; 
            y = (move - 1) % SIDE; 
            if (board[x][y] == ' ') { 
                board[x][y] = HUMANMOVE; 
                showBoard(board); 
                moveIndex++; 
                if (gameOver(board)) { 
                    declareWinner(HUMAN); 
                    return; 
                } 
                whoseTurn = COMPUTER; 
            } 
            else { 
                printf("Kotak %d sudah dipakai. coba "
                       "lagi.\n", 
                       move); 
            } 
        } 
    } 
  
    
    if (!gameOver(board) && moveIndex == SIDE * SIDE) 
        printf("Draw yak wkwk\n"); 
    else { 
        if (whoseTurn == COMPUTER) 
            whoseTurn = HUMAN; 
        else if (whoseTurn == HUMAN) 
            whoseTurn = COMPUTER; 
        declareWinner(whoseTurn); 
    } 
} 
  










/*PROGRAM 
MENU 
RESTORAN*/
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
                } else {
                    displayInvoiceForOrder(x - 1);
                }
                    }
                else if (choice == 4){
                    system("cls");
                    mulaigame(COMPUTER);                  
                  
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


int main() 
{ 
    login();
    fitur();
  
    return 0; 
}




