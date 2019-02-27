/*************************************************************************
	> File Name: ep4.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月13日 星期日 23时58分15秒
 ************************************************************************/

#include<stdio.h>

int is_pan(int a) {
    int as[6], i = 0;
    while(a) {
        as[i] = a % 10;
        a /= 10;
        i++;
    }
    if((as[0] == as[5]) && (as[1] == as[4]) && (as[2] == as[3])) return 1;
    return 0;
}
int main() {
    int ans = 0;
    for(int i = 999; i >= 100; i--) {
        for(int j = i; j >= 100; j--) {
            if(is_pan(i * j)) {
                ans = i * j > ans ? i * j : ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
