/*************************************************************************
	> File Name: ep1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 14时52分51秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 4000000

int fib[55] = {0};
int n = 2;

int main(){
    fib[0] = 1;fib[1] = 2;
    while(fib[n-1] + fib[n-2] < MAX_N){
       fib[n] = fib[n - 1]  + fib[n - 2];
        n ++;
    }
       int ans = 0;
    for(int i = 0;i < n;i++){
        if(fib[i]&1) continue;
        ans += fib[i];
    }
    printf("%d\n", ans);
    return 0;
}
