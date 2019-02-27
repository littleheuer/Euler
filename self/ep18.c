/*************************************************************************
	> File Name: ep18.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月19日 星期六 20时49分01秒
 ************************************************************************/

#include<stdio.h>
#define max_18 15
#define max_67 100
#define max(a, b) ((a) > (b) ? (a) : (b))

int num[max_18 + 5][max_18 + 5] = {0};

int triangle() {
    for(int i = max_18 - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            num[i][j] = max(num[i + 1][j], num[i + 1][j + 1]) + num[i][j];
        }
    }
    return num[0][0];
}



int main() {
    
    int ans = 0;
    for(int i = 0; i < max_18; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    ans = triangle();
    printf("%d\n", ans);
    return 0;
}
