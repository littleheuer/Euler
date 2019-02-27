/*************************************************************************
	> File Name: ep11.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月14日 星期一 14时30分49秒
 ************************************************************************/

#include<stdio.h>

int dir[4][2] = {
    0,1,
    1,1,
    1,0,
    1,-1
};
int main() {
    int num[30][30] = {0};
    for(int i = 5; i < 25; i++) {//不是<=，因为最后一个也算的话是26X26了
        for(int j = 5; j < 25; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    int ans = 0;
    for(int i = 5; i <= 25; i++) {
        for(int j = 5; j <= 25; j++) {
            for(int d = 0; d < 4; d++) {
                int temp = 1;
                for(int step = 0; step < 4; step++) {
                    temp *= num[i + dir[d][0] * step][j + dir[d][1] * step];
                }
                if(temp > ans) ans = temp;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
