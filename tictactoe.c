#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define COMPUTER 1 
#define HUMAN 2 
#define SIDE 3 
#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X' 
  
// ---------------- Intelligent  
  
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
    if (whoseTurn == COMPUTER) 
        printf("Kenken menang\n"); 
    else
        printf("Mantap\n"); 
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
            printf("COMPUTER meletakan %c didalam cell %d %d\n", 
                   COMPUTERMOVE, x, y); 
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
  

int main() 
{ 
    system("cls");
    mulaigame(COMPUTER); 
  
    return 0; 
}