/*************************************************************************
	> File Name: jiecheng.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月21日 星期五 18时21分20秒
 ************************************************************************/

#include<stdio.h>

#define max 1000000

void carry(int *ans) {

    for(i = 1; i <= ans[0]; i++) {
        if(ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] = ans[i] % 10;
        ans[0] += (i == ans[i]);
       
}

int main() {
    int ans[max] = {0};
    int num[502][502] = {0};
    num[0] = num[1] = 1;
    int i;
    for(i = 1; i <= n; i++) {
       num[i];
    }
    
}
