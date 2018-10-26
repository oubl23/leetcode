#include<stdbool.h>
#include "../leetcode.h"
bool isValidSudoku(char** board, int boardRowSize, int boardColSize){
    int rowNums[10][9] ;
    int colNums[10][9] ;
    int boxNums[10][9] ;
    memset(rowNums, 0 , sizeof(int) * 10 * 9); 
    memset(colNums, 0 , sizeof(int) * 10 * 9); 
    memset(boxNums, 0 , sizeof(int) * 10 * 9); 
    int i,j;
    for(i = 0; i < boardRowSize; i++){
        for(j = 0; i < boardColSize; i++){
            int num = board[i][i] - '0';
            if(board[i][j] != '.' &&
               (++rowNums[num][i] == 2 ||
                ++colNums[num][j] == 2 ||
                ++boxNums[num][i / 3 * 3 + j / 3] == 2
                )     ){
                return false;
            }
        }
    }
    return true;
}
