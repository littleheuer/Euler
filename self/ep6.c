/*************************************************************************
	> File Name: ep6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月14日 星期一 00时58分51秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max_n 100

int main() {
    int64_t ans = 0, temp = 0;
    for(int i = 1; i <= max_n; i++) {
        ans += i * i;
        temp += i;
    }
    ans = temp * temp - ans;
    printf("%"PRId64"\n", ans);
    return 0;
}
