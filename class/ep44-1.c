/*************************************************************************
	> File Name: ep44-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 09时36分15秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int64_t pentagonal(int n) {
    return n * (3 * n - 1) - 2;
}
//不用数组的原因为：多边形数与x是单调递增的
int64_t is_pentagonal(int x) {
    int head = 1, tail = 10000, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;//位运算相当于除以2
        if(pentagonal(mid) == x) return 1;
        if(pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    int64_t ans = INT64_MAX;
    for (int i = 1; i < 100000; i++) {
        for (int j = i + 1; j < 100000; j++) {
            int64_t m = pentagonal(i),n = pentagonal(j);
            if(is_pentagonal(m + n) && is_pentagonal(n - m)) {
                int64_t temp = n - m;
                if(temp < ans) ans = temp;
            }
        }
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
