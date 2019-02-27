/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 11时00分36秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = b;
    char *q;
    printf("%d\n", *b);
    printf("%ld %ld %ld\n",sizeof(p), sizeof(b), sizeof(q));
    return 0;
}
