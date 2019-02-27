/*************************************************************************
	> File Name: ep11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 19时04分40秒
 ************************************************************************/

#include<stdio.h>
//表方向和x，y维度
int dir[4][2] = {
    0, 1, 1, 1, 1, 0, 1, -1
};
int main() {
    int num[30][30] = {0};
    for(int i = 5; i < 25; i++){//在数组外面包了一层
        for(int j = 5; j < 25; j++){
            scanf("%d", &num[i][j]);
        }
    }
    int ans = 0;
    for(int x = 5; x < 25; x++){
        for(int y = 5; y < 25; y++){
            for(int k = 0; k < 4; k++){//移动方向
                int p = 1;//暂存值
                for(int step = 0; step < 4; step++){//该方向移动步数
                    int xx = x + step * dir[k][0];
                    int yy = y + step * dir[k][1];
                    p *= num[xx][yy];
                }
                if(p > ans) ans = p;//更新ans
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
