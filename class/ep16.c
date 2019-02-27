/*************************************************************************
	> File Name: 2^n.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 18时33分02秒
 ************************************************************************/
//ep16
#include<stdio.h>
#define max 10000

int num[max + 5] = {0};

void mul(int *num) {
    num[0] = num[1] = 1;
    int count = 1;
    for(int j = 0; j < 1000; j++) {
        for(int i = 1; i <= num[0]; i++) num[i] *= 2;
            for(int i = 1; i <= num[0]; i++) {
                if(num[i] < 10) continue;
                num[i + 1] += num[i] / 10;
                num[i] %= 10;
                num[0] += (i == num[0]);
            }
    }
    return ;
}

int main() {
    int ans = 0;
    mul(num); 
    for(int i = 1; i <= num[0]; i++) {
        ans += num[i];
    }
    printf("\n%d", ans);
    return 0;
}
