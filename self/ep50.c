/*************************************************************************
	> File Name: ep50.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月26日 星期六 11时20分22秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max_n 1000000



int64_t prime[max_n + 5] = {0};
int64_t isPrime[max_n + 5] = {0};
int64_t fnum[max_n + 5] = {0};
int mnum[max_n + 5] = {0};
int64_t sum[max_n + 5] = {0};
void init() {
    for(int64_t i = 2; i <= max_n; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            fnum[i] = 2;//错误点
            mnum[i] = 1;
        }
        for(int64_t j = 1; j <= prime[0]; j++) {
            //int64_t temp = i * prime[j];
            if(i * prime[j] > max_n) break;
                //printf("%"PRId64"\n" ,i * prime[j]);
            prime[i * prime[j]] = 1;
            //printf("%"PRId64"\n", prime[0]);
            if(i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                fnum[prime[j] * i] = fnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;//错误点
            } else {
                mnum[prime[j] * i] = 1;
                fnum[prime[j] * i] = fnum[i] * fnum[prime[j]];
            }
        }
    }
    return ;
}

void init_2() {
    for(int i = 2; i <= max_n; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            isPrime[i] = 1;
        }       
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}
int is_prime(int x, int n) {
    //if(x >= max_n) return 0;
    int head = 1, tail = n, mid;
    while(head <= tail) {
        mid = (head + tail) / 2;
        if(prime[mid] == x) return 1;
        else if(prime[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}
int main() {
    init_2();
    int ans = 0, len = 0;

   for(int i = 1; i <= prime[0]; i++) {
       sum[i] = prime[i] + sum[i - 1];
   }
   //i为第1～i个素数的和
   for(int i = 1; i <= prime[0]; i++) {
       //加上len就保证一定必len要大，另一方面效率会得到显著提示
       //提升效率的技巧
       for(int j = i + 1 + len; j <= prime[0]; j++) {
           int64_t temp = sum[j] - sum[i - 1];
           if(temp > max_n) break;
           if(is_prime(temp, prime[0]) == 1){
            len = j - i + 1;
            ans = temp;
           }
       }
   }
    printf("%d\n", ans);
    return 0;
}
