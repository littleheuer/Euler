/*************************************************************************
	> File Name: ep16.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月19日 星期六 10时57分30秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max_n 1000

int num[max_n + 5] = {0};


int main() {
    num[0] = num[1] = 1;
    for(int i = 0; i < max_n; i++) {
        for(int j = 1; j <= num[0]; j++) {
            num[j] *= 2;
        }
        for(int j = 1; j <= num[0]; j++) {
            if(num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }
    int64_t ans = 0;
    for(int i = 1; i <= num[0]; i++) {
        ans += num[i];
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
