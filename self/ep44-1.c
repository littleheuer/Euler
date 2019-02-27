/*************************************************************************
	> File Name: ep44-1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 19时48分21秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<limits.h>
#define max_n 100000
// 效率太低跑不出来
int64_t pen(int n) {
    return n * (3 * n - 1) / 2;
}

int is_pen(int64_t x) {
    int head = 1, tail = max_n;
    while(head <= tail) {
        int mid = (head + tail) / 2;
        if(pen(mid) == x) return 1;
        else if(pen(mid) > x) {
            tail = mid - 1;
        }
        else {
            head = mid + 1;
        }
    }
    return 0;
}

int main() {
    int64_t ans = INT64_MAX;
    for(int i = 1; i <= 100; i++) {
        for(int j = i + 1; j <= 100; j++) {
            int m = pen(i), n = pen(j);
            if(is_pen(n - m) && is_pen(n + m)) {
                if(n - m < ans) {
                    ans = n - m;
                }
            }
        }
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
