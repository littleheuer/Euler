/*************************************************************************
	> File Name: ep3.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月13日 星期日 23时19分43秒
 ************************************************************************/
//暴力
#include<stdio.h>
#include<inttypes.h>
#define max_n 600851475143


int main() {
    int64_t n = max_n;
    int64_t i = 2, ans = 0;
    while(i * i <= n) {
        if(n % i) {
            ++i;
            continue;
        }
        ans = i;
        while(n % i == 0) n /= i;
    }
    if(n - 1) ans = n;
    printf("%"PRId64"\n", ans);
    return 0;
}
