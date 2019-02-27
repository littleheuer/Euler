/*************************************************************************
	> File Name: ep8-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 16时32分39秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"8.h"

int main() {
    int64_t p = 1, zero = 0, ans = 0;
    for (int i = 0; num[i]; i++){
        if (num[i] == '0') {
            zero++;//13行里的零的个数
        }  else {
            p *= (num[i] - '0');//数字的字符串转换为数值
        }
        if (i >= 13) {//i为13时开始进入该代码块
            if (num[i - 13] == '0') {
                zero --;
            } else {
                p /= (num[i - 13] - '0');
            }
        }
        if (i >= 13 && zero == 0 && p > ans) ans = p;
        /*只有13数字里没有0的时候才更新ans*/
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
