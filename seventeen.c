#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** letterCombinations(char* digits, int* returnSize){
    char*  digitMapper[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int letterLen[] = {0,0,3,3,3,3,3,4,3,4};
    int i, j, k;
    int count = 1;
    int empty = 1;
    int digit_len = strlen(digits);
    for(i = 0 ; i < digit_len; i++){
        int index = digits[i] - '0';
        if(letterLen[index] > 0){
            empty = 0;
            count *=letterLen[index];
        }
    }
    if(empty){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = count;
    char **letters = malloc(sizeof(char *) * count);

    for(i = 0; i < count; i++){
        letters[i] = malloc(digit_len + 1);
        memset(letters[i], 0 , digit_len + 1);
    }
    int den = count;

    int col = 0;
    for(i = 0 ; i < digit_len; i++){
        int index = digits[i] - '0';
        if(letterLen[index] > 0){
            if(letterLen[index] > 0){
                den /= letterLen[index];
                printf("den = %d\n",den);
            }
            for(j = 0 ; j < count; j++){
                k = j / den % letterLen[index];
                letters[j][col] = digitMapper[index][k];
            }
            col++;
        }
    }
    return letters;
}
int main(){
    int i, size = 0;
    char ** letters = letterCombinations("222", &size);

    for (i = 0; i < size; i++) {
        printf("%s\n", letters[i]);
        free(letters[i]);
    }
    free(letters);
    return 0;
}
