/*************************************************************************
	> File Name: ep2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月13日 星期日 22时59分02秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max_n 4000000

int is_even(int a) {
    if(a & 1) return 0;
    return 1;
}

int main() {
    int fib[3] = {0};
    fib[0] = fib[1] = 1;
    int64_t sum = 0;
    for(int i = 2; i <= max_n; i++) {
        fib[i % 3] = fib[(i - 1) % 3] + fib[(i - 2) % 3];
        if(fib[i % 3] > max_n) break;
        if(is_even(fib[i % 3])) {
            sum += fib[i % 3];
        }
    }
    printf("%"PRId64"\n", sum);
    return 0;
}
