/*************************************************************************
	> File Name: ep25.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月16日 星期三 21时21分31秒
 ************************************************************************/

#include<stdio.h>

int fib[2][2000] = {0};

int main() {
    fib[0][0] = fib[1][0] = 1;
    fib[0][1] = 0;
    fib[1][1] = 1;
    int i = 1;
    //for循环的话条件就是fib[(i - 1) % 2][0] < 1000
    while(fib[i % 2][0]  < 1000) {
        ++i;
        fib[i % 2][0] = fib[(i - 1) % 2][0];
        for(int j = 1; j <= fib[i % 2][0]; j++) {
            fib[i % 2][j] = fib[(i - 1) % 2][j] + fib[(i - 2) % 2][j];
        }
        for(int j = 1; j <= fib[i % 2][0]; j++) {
            if(fib[i % 2][j] < 10) continue;
            fib[i % 2][j + 1] += fib[i % 2][j] / 10;
            fib[i % 2][j] %= 10;
            fib[i % 2][0] += (j == fib[i % 2][0]);
        }
    }
    printf("%d\n", i);
    return 0;
}
