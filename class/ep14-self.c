/*************************************************************************
	> File Name: ep14-self.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 01时06分11秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 1000000

int num[max + 5] = {0};

int is_even(int step) {
    if(step & 1) return 0;
    return 1;
}
int chain(int64_t step) {
    if(step == 1) return 1;
    if(step <=max && num[step]) return num[step];
    int temp = 0;
    if(is_even(step)) {
        temp = 1 + chain(step >> 1);
    } else {
        temp = 1 + chain(3 * step + 1);
    }
    if(step <= max) num[step] = temp;
    return temp;
}

int main() {
    int ans_len = 1;
    int ans = 1;
    for(int64_t i = 2; i < max; i++) {
         int temp_len = chain(i);
         if(temp_len > ans_len) {
             ans_len = temp_len;
             ans = i;
         }
    }
    printf("%d(%d)\n", ans, ans_len);

    return 0;
}
