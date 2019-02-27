/*************************************************************************
	> File Name: ep21.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月24日 星期四 20时59分29秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<inttypes.h>
#define max_n 10000

int prime[max_n + 5] = {0};
int64_t f[max_n + 5] = {0};
int m[max_n + 5] = {0};


void init() {
    for(int i = 2; i <= max_n; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 1 + i;
            m[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > max_n) break;

            prime[i * prime[j]] = 1;

            if(i % prime[j] == 0) {
                m[i * prime[j]] = m[i] + 1;
                f[i * prime[j]] = f[i] / (pow(prime[j], m[i] + 1) - 1) * (pow(prime[j], m[i] + 2) - 1);
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                m[i * prime[j]] = 1;
            }
        }
    }
    return ;
}

int main() {
    init();
    int64_t ans = 0;
    int flag[max_n] = {0};
    for(int i = 1; i <= max_n; i++) {
        f[i] -= i;
    }
    for(int i = 1; i <= max_n; i++) {
        if(flag[i] || f[i] > max_n) continue;
        //a != b得成立
        if(i == f[f[i]] && i != f[i]) {
            ans = ans + i + f[i];
            flag[i] = flag[f[i]] = 1;
        }
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
