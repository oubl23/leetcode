#include "../leetcode.h"

int longestVaildParentheses(char* s){
    int len = strlen(s);
    char* stack = malloc(sizeof(char) * len);
    int* num = malloc(sizeof(int) * len);
    int length = 0;
    int i;
    int count = 0;
    int j = 0;
    for(i = 0 ; i < len; i++){
        if( length > 0 && stack[length - 1] == '(' && s[i] == ')'){
            length--;
            count++;
        }else{
            stack[length] = s[i];
            num[length] = j++;
            length++;
        }
    }
    int max = 0;
    for(i = 0 ; i < length; i++){
        printf("%d\t", num[i]);
    }
    printf("\n", num[i]);
    printf("%d\n", count);
    for(i = 0 ; i < length; i++){
        int n;
        if( i == 0){
            n = num[i];
        }else
             n = num[i] - num[i-1] -1 ;
        if( max < n){
            max = n;
        }
        count -= n;
    }
    if( count > max){
        max = count;
    }
    return 2 * max;
}

int longestValidParenthesesSimple(char* s){
    int res = 0, start =0;
    int len = strlen(s);
    int* stack = malloc(sizeof(int) * len);
    int top = -1;
    int i;
    for( i = 0; i < len; i++){
        if(s[i] == '('){
            stack[++top] = i;
        } else{
            if(top == -1){
                start = i + 1;
            }else{
                top--;
                int r1 = res > (i - start + 1) ? res : (i -start + 1);
                int r2 = res > (i - stack[top]) ? res :(i - stack[top]);
                res = top == -1 ? r1 : r2;
            }
        }
    }
    return res;
}
int main() {
    char s[] = "(()";
    printf("%d\n",longestValidParenthesesSimple(s));
}
