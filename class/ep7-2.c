/*************************************************************************
	> File Name: ep07-2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 10时27分24秒
 ************************************************************************/

#include<stdio.h>
#define MAX 200000
int prime[MAX + 5] = {0};//估计10001需要20万

void init() {
    //素数筛选法，此时prime为表格,合数标记为1，素数标记为0；
    for (int i = 2;i * i <= MAX; i++){
        if(prime[i]) continue;//找素数
            for(int j = 2*i; j <= MAX;j += i){
            prime[j] = 1;
            }
    }
    for (int i = 2;i <= MAX; i++){
        if(prime[i]) continue；//找素数所在的下标
        prime[++prime[0]] = i;/*这里的prime序列已经变成素数集合，下标为第多少个素数，存储相应素*/
    }
    return ;
}


int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
