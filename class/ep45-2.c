/*************************************************************************
	> File Name: ep45-2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 11时18分09秒
 ************************************************************************/
//ep45的tri包含hex，则寻找是否是pen就行。
#include<stdio.h>
#include<inttypes.h>

typedef int64_t int1;

int1 hex(int1 n) {
    return n * (2 * n - 1);
}

int1 pen(int1 n) {
    return n * (3 * n - 1) / 2;
}

int1 bin_s(int1 (*num)(int1), int1 n, int1 h) {
    int1 head = 0, tail = n - 1, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(num(mid) == h) return mid;
        if(num(mid) < h) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    int1 n = 144;
    while (bin_s(pen, 2 * n, hex(n)) == -1) n++;//此时的n是hex的角标，不是pen的角标
    printf("%"PRId64"\n", hex(n));
    return 0;
}
