/*************************************************************************
	> File Name: 24-1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 18时48分05秒
 ************************************************************************/

#include<stdio.h>
#define max 10

int flag[10] = {0};
//jnum里存i！
int jnum[10] = {0};

void init() {
    flag[0] = jnum[0] = 1;
    for(int i = 1; i < max; i++) {
        flag[i] = 1;
        jnum[i] = i * jnum[i - 1];
    }
    return ;
}

int get_num(int n, int k) {
    int step = (k / jnum[n]) + 1, i = -1;
    while(step > 0) {
        i++;
        step -= flag[i];
    }
    flag[i] = 0;
    return i;
}

int main() {
    int n, k;
    init();
    scanf("%d%d", &n, &k);
    k -= 1;
    //改变k - 1种状态
    for(int i = n - 1; i >= 0; i--) {
        int num = get_num(i, k);
        printf("%d", num);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}
