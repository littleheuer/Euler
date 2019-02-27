/*************************************************************************
	> File Name: ep12-2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 14时26分51秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100000

int prime[max_n + 5] = {0};
int dnum[max_n + 5] = {0};//记录所有小于max_n的数的因子个数
//i表示当前数字，prime[j]为第j个质数，且i>j
void init() {
    for(int i = 2; i <= max_n; i++) {//遍历
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;//每个数至少包括2个因子
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                //~~~~
                int temp = i, bj = 0;
                while (temp % prime[j] == 0) {//计算因子次方
                    temp /= prime[j];
                    bj++;//充当prime[j]的次方
                }
                dnum[prime[j] * i] = dnum[i] / (bj + 1) * (bj + 2);
                //相当于次方从bj变为bj+1，计算的时候从(bj)+1变为(bj+1)+1
                break;
            } else {//保证了prime[j]与i互质之后，直接使用公式
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
            }
        }
    }
    return ;
}

int num(int n) {//triangle number
    return n * (n + 1) >> 1;
}

int fac_num(int n) {//求因子个数,使用公式
    if(n & 1) {//奇数判断
        return dnum[n] * dnum[(n + 1) >> 1];
    }
    return dnum[n >> 1] * dnum[n + 1];
}
int main() {
    init();//建表
    int n = 1;
    while(fac_num(n) < 500) n++;//查表
    printf("%d\n", num(n));
    return 0;
}
