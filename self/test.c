/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 12时07分54秒
 ************************************************************************/

#include<stdio.h>
typedef struct Num {
    int x, y;
}Num;

Num m_num[4];

int main() {
    char a[6][4] = {
        "00", "01", "10", "11", "20"
    };
    printf("%s\n", (*a + 8));//?
    for(int i = 0; i < 4; i++) {
        printf("x->%d||y->%d\n", m_num[i].x, m_num[i].y);
    }
    return 0;

}
