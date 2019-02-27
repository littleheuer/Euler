/*************************************************************************
	> File Name: ep10.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 11时19分08秒
 ************************************************************************/
#include<stdio.h>
#include<inttypes.h>
#define MAX 2000000
int64_t sum = 0;//int 最大表示范围为10位数

int prime[MAX + 5] = {0};
void init(){
    for (int i = 2;i <= MAX; i++){
        if(prime[i]) continue;
        for(int j = 2 * i;j <= MAX; j +=i){
            prime[j] = 1;
        }
    }
    for (int i = 2;i <= MAX; i++){
        if(prime[i]) continue;
        prime[++prime[0]] = i;
    }
    for (int i = 1;i <= prime[0]; i++){
        sum +=prime[i];
    }

}

int main(){
    init();
    printf("%"PRId64"\n",sum);
    return 0;
}
