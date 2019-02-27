/*************************************************************************
	> File Name: random_prime.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月29日 星期六 10时14分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define max 15000 

int prime[max + 5] = {0};
int rs;
int a_num, b_num;

void init() {
    for(int i = 2; i <= max; i++) {
        if(prime[i]) continue;
        for(int j = 2*i; j <= max; j += i) {
            if(prime[j]) continue;
            prime[j] = 1;
        }
    }
    for(int i = 2; i <= max; i++) {
        if(prime[i]) continue;
        prime[++prime[0]] = i;
    }
    return ;
}
void my_seed(int x) {
    rs = x;
}

rs = 34;
int my_rand(){
    do {
        rs = rs * a_num % b_num;       
    } while(rs > 10000);
    return rs;
}

//int prime_s(){
  //  int i = 50;
    //while(prime[++i] <= 10005) continue;
    //return i;

//}

int quick_mod(int a, int b, int c) {//快速幂取摸公式
    int ans = 1, temp = a % c;//取模公式
    while (b) {
        if (b & 1) ans = ans * temp % c;
        temp =temp * temp % c;
        b >>= 1;
    }
    return ans;
}

int get_len(int a, int b) {//循环节长度
    for(int i = 1; i < b - 1; i++) {
        if((b - 1) % i) continue;
        if(quick_mod(a, i, b) == 1) return i;
    }
    return b - 1;
}
void get_a_and_b() {
    int i = 1;
    int pri = prime[i];
    for(int i = 10000; i < 12000; i++) {
        if(get_len(pri, i) == i - 1){
            a_num = pri;
            b_num = i;
            break;
        } else {
            pri = prime[++i];
        }
    }
    return ;
}

void get_a_and_b_2(int *a, int *b) {
    for(int i = 1; i <= prime[0]; i++) {
        if(prime[i] <= 12000) continue;
        *b = prime[i];
        break;
    }
    for(int i = 1; i < *b; i++) {
        if(get_len(i, *b) != *b - 1) continue;
        *a = i;
        break;
    }
    return ;
}

void check(int a, int b) {
    a_num = a; b_num = b;
    int vis[10001] = {0};
    for(int i = 0; i < 10000; i++) {
        int temp = my_rand();
        if(vis[temp]) {
            printf("error\n");
            return ;
        } else {
            vis[temp] = 1;
        }
    }
    printf("%d %d ok", a, b);
    return ;
}

int main() {
    int a, b;
    init();
    get_a_and_b_2(&a, &b);
    printf("%d, %d\n", a_num, b_num);
    check(a_num, b_num);
}
