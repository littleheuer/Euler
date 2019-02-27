/*************************************************************************
	> File Name: ep24.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 18时24分55秒
 ************************************************************************/

#include<stdio.h>

//存i的阶乘,0!~9!
int jnum[10] = {0};
//i表示某个数字
int flag[10] = {0};

void init() {
    jnum[0] = flag[0] = 1;
    for(int i = 1; i < 10; i++) {
        flag[i] = 1;
        jnum[i] = i * jnum[i - 1];
    }
    return ;
}

int get_num(int n, int k) {
    //+1是原本的数,如0123456789，ind是要跳到的数字
    int  ind = (k / jnum[n]) + 1, i = -1;
    while (ind > 0) {
        i++;
        //标记为1的时候步数才减少
        //i从0开始选择
        ind -= flag[i];
    }
    //标记用过的数字
    flag[i] = 0;
    return i;
}
int main() {
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    k--;
    for(int i = n - 1; i >= 0; i--) {
        //9到0,i + 1为位数,k为第几个排列方式
        int num = get_num(i, k);
        printf("%d", num);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}
