/*************************************************************************
	> File Name: ep24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月30日 星期三 22时51分24秒
 ************************************************************************/
#include<stdio.h>

int flag[10] = {0};
int jnum[10] = {0};

void init() {
    flag[0] = 1;
    jnum[0] = 1;
    for(int i = 1; i < 10; i++) {
        flag[i] = 1;
        jnum[i] = i * jnum[i - 1];
        printf("%d ", jnum[i]);
    }
    return ;
}

int get_num(int i, int k) {
    int step = (k / jnum[i]) + 1;
    int j = -1;
    while(step > 0) {
        j++;
        step -= flag[j];
    }
    flag[j] = 0;
    return j;
}

int main() {
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    k -= 1;
    for(int i = n - 1; i >= 0; i--) {
        int ans = get_num(i, k);
        printf("%d", ans);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}
