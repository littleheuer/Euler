/*************************************************************************
	> File Name: ep13-x.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 20时02分44秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
        int ans[50] = {0};
        ans[0] = ans[1] = 1;
        for(int i = 1;i <= m; i++) {//下标为位数
            ans[i] *= n;
        }
        for (int i = 1; i <= ans[0]; i++) {//进位
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        
        }
        for (int i = ans[0]; i > 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
