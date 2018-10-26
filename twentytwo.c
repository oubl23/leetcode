#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateAdd(char** results, int* count, char* string,int start, int left ,int right, int n){
    if(left == 0 && right == 0){
        results[*count] = malloc(sizeof(char) * 2 * n + 1);
        string[2*n] = 0;
        memcpy(results[*count], string, strlen(string) * sizeof(char));
        (*count)++;
    }
    if( left > right ) {
        return;
    }
    if( left != 0 ){
        string[start] = '(';
        generateAdd(results, count, string  ,start+1,left - 1, right , n); 
    }
    if( right !=0){
        string[start] = ')';
        generateAdd(results, count, string  ,start+1,left, right - 1 , n); 
    }
}

char** generateParenthesis(int n, int* returnSize){
    int cap = 100000;
    char** result = malloc(sizeof(char*) * cap);
    char* string = malloc(sizeof(char) * 2 * n + 1);
    (*returnSize) = 0;
    generateAdd(result, returnSize, string,0, n, n, n);
    return result;
}
int main(){
    int count;
    char** res = generateParenthesis(4,&count);
    printf("%d\n", count);
    int i = 0;
    for(i; i < count; i++){
        printf("%s\n", res[i]);
    }
    
}
