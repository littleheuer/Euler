/*************************************************************************
	> File Name: ep44-2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 21时18分22秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int64_t pen(int64_t n) {
    return n * (3 * n - 1) / 2;
}

//binary search
int is_pen(int64_t x) {
    int head = 0, tail = 500000000;
    while(head <= tail) {
        int mid = (head + tail) >> 1;
        if(pen(mid) == x) return 1;
        else if(pen(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}


int main() {
    int64_t ans = INT64_MAX;
    int64_t j = 1, i = 1;
    while(pen(j + 1) - pen(j) < ans) {
        j++;
        i = j - 1;
        do{
            if(is_pen(pen(j) + pen(i))) {
                if(is_pen(pen(j) - pen(i))) {
                    if(ans > pen(j) - pen(i)) {
                        ans = pen(j) - pen(i);
                        //printf("%"PRId64"->")
                    }
                }
        }
        i--;
        } while(i && pen(j + 1) - pen(i) < ans);
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
