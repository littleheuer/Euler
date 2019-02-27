/*************************************************************************
	> File Name: ep14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 20时08分20秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 1000000

#define keep_range 1000000//与缓存命中率有关，并不是越大越好

int num[max + 5] = {0};

int get_length(int64_t x){
    if (x == 1) return 1;
    if(x <= keep_range && num[x]) return num[x];
    int temp = 0;
    if (x & 1) temp = get_length(3 *x + 1) + 1;
    else temp = get_length(x >> 1) + 1;
    if(x <= keep_range) num[x] = temp;//填表记录
    return temp;
    
}
int main() {
    int ans, ans_len = 1;
    for (int i = 1; i < max; i++){
        int temp_len = get_length(i);
        if (temp_len > ans_len){
            ans = i;
            ans_len = temp_len;
        }
    }
    printf("%d(%d)\n", ans, ans_len);
    return 0;
}
