/*************************************************************************
	> File Name: ep13.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月16日 星期三 15时18分09秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
char read_line[55];

int main() {
    int ans[55] = {0};
    while(scanf("%s", read_line) != EOF) {
        int len = strlen(read_line);
        if(len > ans[0]) ans[0] = len;
        for(int i = 0; read_line[i]; i++) {
            ans[len - i] += read_line[i] - '0';
        }
        for(int i = 1; i <= ans[0]; i++) {
            if(ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    for(int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
        if(i == ans[0] - 9) printf("\n");
    }
    return 0;
}
