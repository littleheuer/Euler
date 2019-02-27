/*************************************************************************
	> File Name: ep05.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月14日 星期一 00时31分44秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max_n 10000000000

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int64_t ans = 2520;
    for(int i = 2; i <= 20; i++) {
        if(ans % i == 0) continue;
        ans = ans * i / gcd(ans, i);
    }
    printf("%"PRId64"\n", ans);
    return 0;
}

