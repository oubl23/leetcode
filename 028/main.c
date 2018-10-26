#include "../leetcode.h"

int strStr(char* s, char* r){
    int x = strlen(s);
    int y = strlen(r);
    int i, j;
    for(i = 0 ; i < x ;i++){
        if ( i > x - y) {
            return -1;
        }
        for(j = 0; j < y;j++){
            if( s[i + j] != r[j]){
                break;
            }
            if (j == y-1){
                return i;
            }
        }
    }
}

int* getNext(char* p){
    int len = strlen(p);
    int* next = malloc(sizeof(int) * len);
    next[0] = -1;
    int j = 0;
    int k = -1;
    while(j < len -1)
    {
        if(k == -1 || p[j] == p[k]){
            next[++j] = ++k;
        } else {
            k = next[k];
        }
    }
    return next;
}

int KMP(char* ts , char* ps){
    int i = 0;
    int j = 0;
    int* next = getNext(ps);
    int x = strlen(ts);
    int y = strlen(ps);
    while( i < x && j < y) {
        if( j == -1 || ts[i] == ps[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }

    if( i == x - 1){
        return i - j;
    }
    return -1;
}

int main(){
    char s[] = "llo";
    char r[] = "ll";
    int i = KMP(s,r);
    printf("%d\n",i);
}
