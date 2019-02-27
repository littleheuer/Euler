/*************************************************************************
	> File Name: ep7.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月12日 星期六 18时26分45秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100000001

int prime[max_n] = {0};

void init() {
    for(int i = 2; i <= max_n; i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    printf("%d\n",prime[10001]);
    return 0;
}
