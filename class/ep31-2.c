/*************************************************************************
	> File Name: ep31-2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月21日 星期五 19时18分35秒
 ************************************************************************/

#include<stdio.h>
int log[2000][2000] = {0};

//记忆化
int w(int k) {
    static int arr [8] = {
        1, 2, 5, 10, 20,100, 200
    };
    return arr[k - 1];
}
int f(int k, int n) {
    //if(k == 1) return 1;
    //if(n == 0) return 1;减去自身后为0
    if (n < 0) return 0;
    if(log[k][n]) return log[k][n];
    return f(k - 1, n) + f(k, n - w(k));
}

int main() {
    for(int i = 0; i < 2000; i++) {
        log[1][i] = log[i][0] = 1;
    }

    printf("%d\n", f(8, 200));
    return 0;
}
