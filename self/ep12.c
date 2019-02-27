/*************************************************************************
	> File Name: ep12.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 09时09分37秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 1000000

int prime[max_n + 5] = {0};
int fnum[max_n + 5] ={0};
int mnum[max_n + 5] = {0};
void init() {
    for(int i = 2; i <= max_n; i++) {
        while(!prime[i]) {
        prime[++prime[0]] = i;
        fnum[i] = 2;
        mnum[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                fnum[prime[j] * i] = fnum[i] / ( mnum[i] + 1) * ( mnum[i] + 2);
                break;
            }
            else {
                mnum[prime[j] * i] = 1;
                fnum[prime[j] * i] = fnum[prime[j]] * fnum[i];
            }
        }
    }
}

int triangle(int n) {
    return (n + 1) * n / 2;
}

int f(int n ) {
    if(n & 1) return fnum[n] * fnum[(n + 1) / 2];
    else return fnum[n / 2] * fnum[n + 1];
}

int main() {
    init();
    //i代表的是:第i个三角形数
    int i = 10;
    while(f(i) < 500) i++;
    printf("%d\n", triangle(i));
    return 0;
}


