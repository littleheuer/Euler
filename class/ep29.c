/*************************************************************************
	> File Name: ep29.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月28日 星期五 18时10分35秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max 10000
struct Tuple{
    int p, a;
};
//p素因子，a次幂
//4存储各个分解的素因子个数a最大为100,2*3*5*7就大于100了
struct Tuple M[max][4] = {0};
//不重复的个数M_num
int M_num = 0;

int prime[105] = {0};

void get_M(int a, int b, struct Tuple *M) {
    //m_len为对应素因子个数,从0开始
    int m_len = 0;
    while(a != 1) {
        //p_num为素因子次幂,pre记录素因子
        int p_num = 0, pre = prime[a];//pre 为最小质因子
        while (a % pre == 0) {
            a /= pre;
            p_num++;//次幂 
        }
        M[m_len].p = pre;//底数
        //b为a的大次幂,分解a之后的次幂要乘以b
        M[m_len].a = p_num * b;//总次幂
        m_len++;//后移
    }  
    return ;
}


int main() {
    int ans = 0;
    //素数筛
    for(int i = 2; i <= 100; i++) {
        if(prime[i]) continue;
        //i到此必为素数
        for(int j = i; j <= 100; j += i) {
            if(prime[j]) continue;
            prime[j] = i;//记录j的最小素因子
        }
    }
    
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            //temp_m存储单个a^b的分解形式
            struct Tuple temp_m[4] = {0};
            //解析a^b 为pi^ai的形式
            get_M(a, b, temp_m);
            int flag = 1;
            //在不重复的M_num范围里遍历一遍查看是否重复
            for(int i = 0; i < M_num && flag; i++) {
                //memcmp比较两个存储空间的值是否完全相同
                //,没找到返回1，找到了返回0.
                flag = memcmp(M[i], temp_m, sizeof(temp_m));
            }
            //尾部加入
            if(flag) {
                memcpy(M[M_num++], temp_m, sizeof(temp_m));
            }
        }
    }
    printf("%d\n", M_num);
    return 0;
}
