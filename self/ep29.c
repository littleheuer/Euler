/*************************************************************************
	> File Name: ep29.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 23时17分17秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max_n 10000
typedef struct tulple {
    int a, b;
} Tuple;

Tuple M[max_n][4];
int M_sum = 0;

int prime[105] = {0};
//直接修改M里的存储值
void get_M(int a, int b, Tuple *M) {
    int m_len = 0;
    while(a != 1) {
        //pri 为相应a的最小素因子
        int p_num = 0, pri = prime[a];
        while(a % pri == 0) {
            a /= pri;
            p_num++;
        }
        M[m_len].a = pri;
        M[m_len].b = b * p_num;
        m_len++;
    }
    return ;
}

int main() {
    for(int i = 2; i <= 100; i++) {
        if(prime[i]) continue;
        for(int j = i; j <= 100; j += i) {
                if(prime[j]) continue;
                prime[j] = i;
        }
    }
    for(int a = 2; a <= 100; a++) {
        for(int b = 2; b <= 100; b++) {
            //没有初始化tmp会出错!
            Tuple tmp[4] = {0};
            //传的是tmp的指针，所以能存储值
            get_M(a, b, tmp);
            int flag = 1;
            //flag为0则找到重复的并退出
            for(int i = 0;flag && i <= M_sum; i++) {
                flag = memcmp(M[i], tmp, sizeof(tmp));
            }
            if(flag) {
                memcpy(M[M_sum++], tmp, sizeof(tmp));
            }
        }
    }
    printf("%d\n", M_sum);
    return 0;
}

