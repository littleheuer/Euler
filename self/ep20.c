/*************************************************************************
	> File Name: ep20.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月24日 星期四 20时46分36秒
 ************************************************************************/

#include<stdio.h>
#define max_n 10000
int num[max_n + 5] = {0};

int main() {
    num[0] = num[1] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <=num[0]; j++) {
            num[j] *= i;
        }
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= num[0]; i++) {
        ans += num[i];
    }
    printf("%d\n", ans);
}
