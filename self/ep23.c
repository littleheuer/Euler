/*************************************************************************
	> File Name: ep23.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 14时37分35秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 28123

int prime[max_n + 5] = {0};
int fnum[max_n + 5] = {0};
int mnum[max_n + 5] = {0};

void init() {
    for(int i = 2; i <= max_n; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            fnum[i] = i + 1;
            mnum[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++) {
            int temp = i * prime[j];
            if(temp > max_n) break;
            prime[temp] = 1;
            if(i % prime[j] == 0) {
                mnum[temp] = mnum[i] + 1;
                fnum[temp] = fnum[i] / (pow(prime[j], mnum[i] + 1) - 1) * (pow(prime[j], mnum[i] + 2) - 1);
                break;
            } else {
                fnum[temp] = fnum[i] * fnum[prime[j]];
                mnum[temp] = 1;
            }
        }
    }
}

int main() {
    init();
    int flag[max_n + 5] = {0};
    //标记淫数
    for(int i = 1; i <= max_n; i++) {
        if(fnum[i] - i > i) {
            flag[++flag[0]] = i;
            //printf("%d\n", i);
        }
    }
    int num[max_n + 5] = {0};
    for(int i = 1; i <= flag[0]; i++) {
        for(int j = 1; j <= i;j++) {
            //防越界
            if(flag[i] + flag[j] > max_n) continue;
            num[flag[i] + flag[j]] = 1;
            //printf("%d\n", flag[i] + flag[j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= max_n; i++) {
        if(num[i]) continue;
        ans += i;
        //if(i < 100) printf("%d\n", i);
    }
    
    printf("flag[0]:%dans: %d\n",flag[0], ans);
    return 0;
}
