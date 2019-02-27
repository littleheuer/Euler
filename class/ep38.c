/*************************************************************************
	> File Name: ep38.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月21日 星期五 20时50分10秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int is_valid(int x) {
    int num[10] = {0};
    int n = 0,digit = 0;//积和位数
    int y;
    do {
        n += 1;
        y = x * n;
        while(y) {
            if(y % 10 == 0) return 0;
            if(num[y % 10]) return 0;
            num[y % 10] = 1;
            y /= 10;
            digit += 1;
        }
    } while(digit < 9);
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        y = x * i;
        ret = ret * (int) pow(10, floor(log10(y)) + 1) + y;//移位
    }
    return ret;
}

int main() {
    int ans = 0;
    for ( int i = 1; i < 10000; i++) {
        int temp = is_valid(i);//是全数
        if(temp > ans) ans = temp;
    }
    printf("%d\n", ans);
    return 0;
}
