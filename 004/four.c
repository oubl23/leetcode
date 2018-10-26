#include <stdio.h>

double soultion(int* a, int m, int*b, int n);
int main(){
    int a[] = {1};
    int b[] = {2,3};
    double s = soultion(a,1, b,2);
    printf("%f",s);
}

double soultion(int* a, int m, int* b, int n){
    if( m > n)
    {
        return soultion(b, n , a, m);
    }
    int l1,l2,r1,r2,c1,c2,lo = 0, hi = 2 * m;
    int MAX = (((1 << (sizeof(int)*8 - 2)) - 1) * 2) + 1;
    int MIN = -MAX - 1;
    double s;

    while(lo <= m ){
        c1 = (lo + hi - 1) / 2;
        c2 = m + n -c1;
        
        printf("c1 = %d\n", c1);
        printf("c2 = %d\n", c2);
        l1 = (c1 == 0) ? MIN : a[(c1-1)/2];
        r1 = (c1 == 2*m) ? MAX : a[(c1)/2];
        l2 = (c2 == 0) ? MIN : b[(c2-1)/2];
        r2 = (c2 == 2*n) ? MAX : b[(c2)/2];

        printf("%d\n",l1);
        printf("%d\n",r1);
        printf("%d\n",l2);
        printf("%d\n",r2);
        if(l1 > r2) {
            hi = c1 - 1; 
        }else if(l2 > r1){
            lo = c1 + 1;
        }else{
            break;
        }
            
    }
    s = (double)(l1 > l2 ? l1 : l2);
    s += (double)(r1 < r2 ? r1 :r2);
    s = s / 2.0;
    return s;
}
