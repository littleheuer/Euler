/*************************************************************************
	> File Name: primeMax.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 14时40分37秒
 ************************************************************************/

#include<stdio.h>
#define Max 10000

int prime[Max + 5] = {0};

int primeMax(){
    for(int i = 2; i * i <= Max; i++){
        if(prime[i]) continue;
        for(int j = i; j <= Max; j+=i){
            prime[j] = i;//不断刷新最大素数因子
        }
    }
}

int main(){
    int m;
    primeMax();
    while (~scanf("%d", &m)){
        printf("%d(%d)\n", m, prime[m]);
    }
    return 0;
}
