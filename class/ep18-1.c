/*************************************************************************
	> File Name: ep18-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 19时37分56秒
 ************************************************************************/

#include<stdio.h>
#define max_n 15

int  map[max_n + 5][max_n + 5] = {0};
int  keep[max_n + 5][max_n + 5] = {0};
int solve(int i, int j) {
    if(i == max_n) return 0;
    if(keep[i][j]) return keep[i][j];
    int lmax = solve(i + 1,j), rmax = solve(i, j + 1);
    keep[i][j] = (lmax > rmax ? lmax : rmax) + map[i][j];
    return keep[i][j];
}

int main() {
    int ans = 0;
    for(int i = 0; i < max_n; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", map[i] + j);
        }
    }
    ans = solve(0, 0);
    scanf("%d\n", ans);
    return 0;
}
