#include "../leetcode.h"

int devide(int dividend, int divisor){
    int MAXINT = 2147483647;
    int MININT = -2147483648;
    if( divisor == 0 || (dividend == MININT && divisor == 1)){
        return MAXINT;
    }
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long d = (((long)dividend) > 0) ? (long)dividend : (-1) * ((long) dividend);
    long r = (divisor > 0) ? divisor : (-1) * divisor;
    int res = 0;
    while( d >= r){
        long tmp = r;
        long m = 1;
        while(d >= (tmp << 1)){
            tmp <<= 1;
            m <<= 1;
        }
        d -= tmp;
        res += m;
    }
    return res * sign;
}

int main(){
    printf("%d,", devide(-2147483648,2));
}
