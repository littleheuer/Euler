/*************************************************************************
	> File Name: primePick.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 14时28分21秒
 ************************************************************************/

#include<stdio.h>
#define MAX 10000

int prime[MAX + 5] = {0};

void primeMin(){
    for(int i = 2; i * i <= MAX; i++){
        if(prime[i]) continue;
        for(int j = i; j <= MAX; j += i){
            if(prime[j]) continue;//过滤掉已经标记的
            prime[j] = i;
        }
    }
    return ;
}


int main(){
    int m;
    primeMin();
    while(~scanf("%d", &m)) {//输入正确为0；错误为1
        printf("%d(%d)\n", m, prime[m]);
    }
    return 0;
}
