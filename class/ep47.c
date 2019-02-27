/*************************************************************************
	> File Name: ep47.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月28日 星期五 19时21分55秒
 ************************************************************************/

#include<stdio.h>
//线性筛去记录每个数不重复的素因子个数
#define max 1000000
int prime[max + 5] = {0};
int dnum[max + 5] = {0};

void init() {
    for(int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            dnum[prime[j] * i] = dnum[i] + (i % prime[j] != 0);
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    for(int i = 210; i <= max - 3; i++) {
        if(dnum[i] ^ 4) continue;
        if(dnum[i + 1] ^ 4) continue;
        if(dnum[i + 2] ^ 4) continue;
        if(dnum[i + 3] ^ 4) continue;
        printf("%d\n", i);
    }
    return 0;
}
