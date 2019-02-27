/*************************************************************************
	> File Name: ep7-3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 15时37分56秒
 ************************************************************************/
//线性筛算法
#include<stdio.h>
#define max 200000

int prime[max + 5] = {0};

int init() {
    for(int i = 2; i <= max; i ++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i > max) break;//以防指针越界
            prime[prime[j] * i] = 1;//标记之后的合数
            if(i % prime[j] == 0) break;//一旦模为0，则到达了prime[j]里的最小素数因子
        }
    }
}
int init_2(){
    for(int i = 2; i <= max; i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <=prime[0] && prime[j] * i <= max; j++){
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
