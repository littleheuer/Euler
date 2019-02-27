/*************************************************************************
	> File Name: ep8.c
	> Author: 
	> Mnum[i]l: 
	> Created Time: 2019年01月14日 星期一 01时15分35秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"8.h"
#define max_n 1000

int main() {
    int zero = 0;
    int64_t ans = 1, temp = 1;
    int i = 0;
    int num[max_n + 5] = {0};
    for(int j = 0; j <= max_n; j++){
        num[j] = a[j] - '0';
    }
    while(i <= 1000) {
        if(i <= 12) {
            if(num[i] == 0) {
                zero++;
                i++;
                continue;
            } 
            else {
                temp *= num[i++];
                ans = temp;
                continue;
            }
        }
        if(num[i - 13] == 0) {
            zero--;
        } 
        else {
            temp /= num[i - 13];
        }
        if(num[i] == 0) {
            zero++;
            i++;
            continue;
        }
        else {
            temp *= num[i++];
        } 
        if(zero == 0) ans = temp > ans ? temp : ans;
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
