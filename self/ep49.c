/*************************************************************************
	> File Name: ep49.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月01日 星期五 21时40分46秒
 ************************************************************************/
//找一个三项的等差数列，每一项都是素数，并且两两都是重新排列的
//关系
//二进制法,每一位用二位的二进制表示，并且最多存三位
//次数表示法：m+=1<<(2*i)是在m的2*i+1位加上1
//m为次数表示数,1的位数右移2i位
#include<stdio.h>
#define max_n 10000

int prime[max_n + 5] = {0};

void init() {
    for(int i = 2; i <= max_n; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[i] > max_n) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}



int main() {
    for(int i = 1000; i < max_n; i++) {
        
    }
    return 0;
}
