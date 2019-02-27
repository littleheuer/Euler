/*************************************************************************
	> File Name: ep32.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 22时42分50秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 10000

int digit(int x) {
    return floor(log10(x)) + 1;
}
int get_digit(int a, int *num) {
    while(a) {
        if(a % 10 == 0) return 0;
        if(num[a % 10]) return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    return 1;
}
int is_digit(int a, int b, int c) {
    int num[10] = {0};
    if(!get_digit(a, num)) return 0;
    if(!get_digit(b, num)) return 0;
    if(!get_digit(c, num)) return 0;
    return 1;

}

int valid[max_n] = {0};

int main() {
    int ans;
    for(int a = 2; digit(a) + digit(a) + digit(a * a) <= 9; a++) {
        for(int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {
            if(digit(a) + digit(b) + digit(a * b) < 9) continue;
            if (is_digit(a, b, a * b)) {
                ans += a * b * (1 - valid[a * b]);
                valid[a * b] = 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
