/*************************************************************************
	> File Name: ep44-2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 09时53分11秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}
//不用数组的原因为：多边形数与x是单调递增的
int64_t is_pentagonal(int64_t x) {
    int64_t head = 1, tail = 5000000000, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;//位运算相当于除以2
        if (pentagonal(mid) == x) return 1;
        if (pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    int64_t i = 1,j = 1, ans = INT64_MAX;
    while(pentagonal(j + 1) - pentagonal(j) < ans) {//类似于分支限界
        j++;
        i = j - 1;//确定j，用i--来查找
        do {
            if (is_pentagonal(pentagonal(i) + pentagonal(j))) {
                if (is_pentagonal(pentagonal(j) - pentagonal(i))) {
                    if(pentagonal(j) - pentagonal(i) < ans) {
                        ans = pentagonal(j) - pentagonal(i);
                        printf("%"PRId64" -> %"PRId64"\n", pentagonal(j),pentagonal(i));
                    }
                }
            }
            i--;
        } while (i && pentagonal(j) - pentagonal(i) < ans);
        
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
