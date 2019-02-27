/*************************************************************************
	> File Name: ep21.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月02日 星期三 18时17分55秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<math.h>
//求所有小于10000的亲和数的和
#define max 10000
int prime[max + 5] = {0};
int fnum[max + 5] = {0};//因子个数
int mnum[max + 5] = {0};//记录i的最小因子的次幂
int snum[max + 5] = {0};//因子和

int quick_pow(int a, int b) {
    int ans = 1,base = a;
    while(b != 0) {
        if(b & 1 != 0)
        ans *= base;
        b >>= 1;
    }
    return ans;
}

void init() {//线性筛，先记素数后筛
    for(int i = 2; i <= max; i++) {//遍历每个数字
        if(!prime[i]){          
            prime[++prime[0]] = i;//记录素数放在之前用过了的地方
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}
void init_count() {
    for(int i = 2; i <= max; i++) {//遍历每个数字
        if(prime[i] == 0){          
            prime[++prime[0]] = i;//记录素数放在之前用过了的地方
            fnum[i] = 2;//边界值
            mnum[i] = 1;//边界值
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                fnum[prime[j] * i] = fnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[prime[j] * i] = 1;
                fnum[prime[j] * i] = fnum[prime[j]] * fnum[i];
            }
        }
    }
    return ;
}
//int fun(int j, int i) {
//    return (quick_pow(prime[j], mnum[i] + 1) - 1) * (quick_pow(prime[j], mnum[i] + 2) - 1);
//}
void init_sum() {
    for(int i = 2; i <= max; i++) {
        if(!prime[0]) {
            prime[++prime[0]] = i;
            snum[i] = i + 1;
            mnum[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                snum[prime[j] * i] = snum[i] / (quick_pow(prime[j], mnum[i] + 1) - 1) * (quick_pow(prime[j], mnum[i] + 2) - 1);//i是较大的数
            } else {
                mnum[prime[j] * i] = 1;
                snum[prime[j] * i] = snum[prime[j]] * snum[i];
            }
        }
    }
}

int main() {
    init_sum();
    int64_t ans = 0;
    for (int i = 1; i <= max; i++) {
        snum[i] -= i;
    }
    for (int i = 1; i < max; i++) {
        for (int j = i + 1; j < 10000; j++) {
            if ((snum[i] == j) && (snum[j] == i)) ans = ans + i + j;
        }
    }

    printf ("%"PRId64"\n", ans);
    return 0;
}
