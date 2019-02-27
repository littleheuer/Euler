/*************************************************************************
	> File Name: ep24.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月31日 星期四 00时23分24秒
 ************************************************************************/

#include<stdio.h>
int flag[10] = {0};
int jump[10] = {0};

void init() {
    flag[0] = jump[0] = 1;
    for(int i = 1; i < 10; i++) {
        flag[i] = 1;
        jump[i] = jump[i - 1] * i;
    }
    return ;
}

int get_num(int i, int k) {
    int step = (k / jump[i]) + 1;
    int j = -1;
    while(step) {
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
        int num = get_num(i, k);
        printf("%d", num);
        k %= jump[i];
    }
    printf("\n");
    return 0;
}
