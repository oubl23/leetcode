#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* longestPalindrom(char* s);
char* substring(char* ch,int pos,int length)  
{  
    char* pch=ch;  
//定义一个字符指针，指向传递进来的ch地址。  
    char* subch=(char*)calloc(sizeof(char),length+1);  
//通过calloc来分配一个length长度的字符数组，返回的是字符指针。  
    int i;  
//只有在C99下for循环中才可以声明变量，这里写在外面，提高兼容性。  
    pch=pch+pos;  
//是pch指针指向pos位置。  
    for(i=0;i<length;i++)  
    {  
        subch[i]=*(pch++);  
//循环遍历赋值数组。  
    }  
    subch[length]='\0';//加上字符串结束符。  
    return subch;       //返回分配的字符数组地址。  
} 
int main(){
    printf("%s\n",longestPalindrom("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"));
    return 0;
}

char* longestPalindrom(char* s){
    int len = strlen(s);
    int dp[1001][1001] = {0};
    int maxlength = 1;
    int start = 0;
    int i,j,l;
    for(i = 0; i < len - 1; i++){
        dp[i][i] = 1;
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            start = i;
            maxlength = 2;
        }
    }

    for(l = 3 ; l <= len ; l++){
        for(i = 0 ; i <= len - l; i++){
            j = i + l - 1;
            if( dp[i+1][j-1] == 1 && s[i] == s[j]){
                dp[i][j] = 1;
                maxlength = l;
                start = i;
            }
        }
    }
    char* r =(char*) malloc((maxlength+1) * sizeof(char));
    for(i = 0; i < maxlength; i++){
        r[i] = s[start+i];
    }
    printf("%d\n",r[1000]);
    r[maxlength] = '\0';
    printf("%d\n",r[1000]);
    printf("%d\n",strlen(r));
    return substring(s, start, maxlength);
}
