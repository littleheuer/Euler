/*************************************************************************
	> File Name: ep11-self.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 00时44分35秒
 ************************************************************************/
//输入重定向：./a.out < input
#include<stdio.h>
int num[30][30] = {0};

int direction[4][2] = {
    0, 1, 1, 1, 1, 0, 1, -1
};

int main() {
    int i, j;
    for(i = 5; i < 25; i++) {
        for(j = 5; j < 25; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    int max = 0;
    for(i = 5; i < 25; i++) {
        for(j = 5; j < 25; j++) {
            for(int k = 0; k < 4; k++) {
                int p = 1; 
                for(int step = 0; step < 4; step++) {
                    int xx = i + step * direction[k][0];
                    int yy = j + step * direction[k][1];
                    p *= num[xx][yy];
                }
            if(p > max) max = p;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
