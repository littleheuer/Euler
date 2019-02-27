/*************************************************************************
	> File Name: ep14.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月17日 星期四 10时45分11秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max_n 1000000

int chain[max_n + 5] = {0};

int64_t iter(int64_t n) {
    if(n & 1) return 3 * n + 1;
    else return n / 2;
}
//递归一定要写边界；
//chain过程中数据可能超过10位数，发生段错误
int64_t seq(int64_t i) {
    if(i == 1) return 1;
    if(i <= max_n && chain[i]) return chain[i];
    int64_t temp = seq(iter(i)) + 1;
    if(i <= max_n) chain[i] = temp;
    return temp;
}

int seq2(int i) {
    if(i == 1) return 1;
    int temp = seq2(iter(i)) + 1;
    return temp;
}

int main() {
    int ans = 1;
    int sum = 1;
    for(int i = 1; i <= max_n; i++) {
        int temp = seq(i);
        if(temp > sum) {
            ans = i;
            sum = temp;
        }
    }
    printf("(%d) length=%d\n", ans, sum);
    return 0;
}
