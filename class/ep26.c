/*************************************************************************
	> File Name: ep26.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 19时24分21秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max 1000

int flag[max + 5];



int get_len(int d) {
    //n为长度,y余数
    int y = 1, n = 1;
    memset(flag, 0, sizeof(flag));
    while(y && flag[y] == 0) {
        //先标记再求余
        flag[y] = n;
        y = y * 10 % d;
        n++;
    }
    return y ? n - flag[y] : 0;
}

int main() {
    int max_len = 0, ans = 0;
    for(int d = 2; d < max; d++) {
        int temp_len = get_len(d);
        if(temp_len > max_len) {
            max_len = temp_len;
            ans = d;
        }
    }
    printf("%d\n", ans);

    return 0;
}
