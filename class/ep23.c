/*************************************************************************
	> File Name: ep23.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月05日 星期六 08时59分31秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<inttypes.h>
#include<math.h>
#define max 28123

int prime[max + 5] = {0};
int fnum[max + 5] = {0};//真因数不包括本身
int mnum[max + 5] = {0};
int snum[max + 5] = {0};
int anum[max + 5] = {0};
int quick_pow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

void init() {
    for(int i = 2; i <= max; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            fnum[i] = 1 + i;
            mnum[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j ++) {
            int64_t temp = prime[j] * i;
            if(temp > max) break;
            prime[temp] = 1;
            if(i % prime[j] == 0) {
                mnum[temp] = mnum[i] + 1;
                fnum[temp] = fnum[i] / (pow(prime[j], mnum[i] + 1) - 1) * (pow(prime[j], mnum[i] + 2) - 1);
                break;
            } else {
                mnum[temp] = 1;
                fnum[temp] = fnum[prime[j]] * fnum[i];
            }
        }
    }
    return ;
}

void init_anum() {
    for(int i = 1; i <= max; i++) {
        fnum[i] = fnum[i] - i;
    }
    for(int i = 2; i <= max; i++) {
        if(fnum[i] > i) {
          //  printf("fnum[%d] = %d\n", i, fnum[i]);
            snum[++snum[0]] = i;
        }
    }
    for(int i = 1; i <= snum[0]; i++) {
        for(int j = 1; j <= i; j++) {
            if(snum[i] + snum[j] > max) continue;
            anum[snum[i] + snum[j]] = 1;
        }
    }
}

int main() {
    init();
    init_anum();
    int64_t sum = 0;
    for(int i = 1; i <= max; i++) {
        if(anum[i]) continue;
        sum += i;
    }
    printf("%d\n",snum[snum[0]]);
    printf("%"PRId64"\n", sum);
    printf("%d\n", snum[0]);
    return 0;
}
