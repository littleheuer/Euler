/*************************************************************************
	> File Name: ep8-1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月14日 星期一 13时51分31秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"8.h"

int main() {
    int64_t ans = 0, temp = 1;
    int zero = 0;
    for(int i = 0; a[i]; i++) {
        if(a[i] == '0') {
            zero++;
        }
        else {
            temp *=(a[i] - '0');
        }
        if(i >= 13) {
            if(a[i - 13] == '0') {
                zero--;
            }
            else {
                temp /= (a[i - 13] - '0');
            }
        }
        if(zero == 0 && temp > ans && i >=13) ans = temp;
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
