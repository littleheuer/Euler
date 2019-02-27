/*************************************************************************
	> File Name: ep13.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 19时08分02秒
 ************************************************************************/
//大整数运算
#include<stdio.h>
#include<string.h>

int main() {
    char read_num[55];
    int ans[55] = {0};
    while (scanf("%s", read_num) != EOF) {//每次读入一行字符串
        int len = strlen(read_num);
        if(len > ans[0]) ans[0] = len;//位数最大的数为准
        for(int i = 0; read_num[i]; i++) {//读到num没有位数为止
            ans[len - i] += read_num[i] - '0';//read_num里的i为从前往后的
        }//ansl里的len - i为数字的当前所在位数
        for (int i = 1; i <= ans[0]; i++) {
            if(ans[i] < 10) continue;    
            ans[i + 1] += ans[i] / 10;//进位
            ans[i] %= 10;
            ans[0] += (i == ans[0]);//位数加1
            
        }
    }
    for(int i = ans[0]; i > ans[0] - 10; i--) {//从最高位读，取前10位
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
