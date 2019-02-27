/*************************************************************************
	> File Name: ep45.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 21时48分58秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int64_t tri(int64_t n) {
    return n * (n + 1) / 2;
}

int64_t pen(int64_t n) {
    return n * (3 * n - 1) / 2;
}
int64_t hex(int64_t n) {
    return n * (2 * n - 1);
}
//六边形数包含三角形数
int bin_s(int64_t (*func)(int64_t), int64_t n, int64_t x) {
    int64_t head = 0, tail = n;
    while(head <= tail) {
        int64_t mid = (head + tail) >> 1;
        if(func(mid) == x) return 0;
        else if(func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 1;
}

int main() {
    int64_t n = 144;
    while(bin_s(pen, 2 * n, hex(n)) == 1) n++;
    printf("%"PRId64"hex->%"PRId64"\n", n, hex(n));
    return 0;
}
