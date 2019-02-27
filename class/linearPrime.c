/*************************************************************************
	> File Name: linearPrime.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 15时12分21秒
 ************************************************************************/

#include<stdio.h>
#define max 10000

int prime[max + 5] = {0};

int primeMin(int m){
    for(int i = 2; i * i <= m; i++){
        if(!(m % i)) return i;
    }
}

void init(){
    for(int i = 2; i * i <= max; i++){
        if(prime[i]) continue;
        int tmp = primeMin(i);
        for(int j = 2;j <= tmp; j++){
            if(prime[j]) continue;
            prime[i * j] = 1;
        } 
    }
}

int main(){

    init();
    
    return 0;
}
