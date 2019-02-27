/*************************************************************************
	> File Name: sum_fac.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月28日 星期五 20时17分03秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 10000
//素因子和F(c)=F(a)*F(b)

int prime[max + 5] = {0};
int Snum[max + 5] = {0};//素因子和
int mnum[max +5] = {0};//最小素因子の次幂
void init() {
    for(int i = 2; i <= max; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            Snum[i] = 1 + i;//质数因子和
            mnum[i] = 1;//次幂为一
        }
        for(int j = 1; j<= prime[0]; j++) {
            if(prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if((i % prime[j]) == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                Snum[prime[j] * i] = Snum[i] / (pow(prime[j], mnum[i] + 1) - 1) * (pow(prime[j], mnum[i] + 2) - 1);
                break;
            } else {
                mnum[prime[j] * i] = 1;
                Snum[prime[j] * i] = Snum[prime[j]] * Snum[i];
            }

        }
    }
    return ;
}

int main() {
    int n ;
    init();
    while(~scanf("%d", &n)) {
        printf("%d - > %d\n", n, Snum[n]);
    }
    
    return 0;
}
