/*************************************************************************
	> File Name: ep45.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 11时01分10秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int hex(int m) {
    return m * (2 * m - 1);
}

int pen(int m) {
    return m * (3 * m - 1) / 2;
}

int main() {
    int ans = 40755;
    int i, j;
    while(ans == 40755) {
        int m, n;
        i = 3;
        j = i - 1;
        while(j > 1) {
            m = hex(i);
            n = pen(j);
            if(m == n) ans = m;
            j--;   
        }
        i++;
    }
    printf("%d\n", ans);
    return 0;
}
