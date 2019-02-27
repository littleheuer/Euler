/*************************************************************************
	> File Name: ep9.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月14日 星期一 14时15分18秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int main () {
    int64_t a, b, c;
    for(c = 1000; c > 1; c--) {
        for(b = c - 1; b > 1; b--) {
            a = 1000 - c - b;
            if(a >= b || a <= 0) continue;
            if(a * a + b * b == c * c) {
                printf("%"PRId64"\n", a * b * c);
                return 0;
            }
        }
    }
    return 0;
}
