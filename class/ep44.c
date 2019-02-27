/*************************************************************************
	> File Name: ep44.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 09时24分46秒
 ************************************************************************/
//二分查找
#include<stdio.h>

int bin_s(int *arr, int x) {
    int len = sizeof(arr) / sizeof(int);
    int l = 1, r = len;
    int mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if(arr[mid] == x) return 0;
        if(arr[mid] > x) {
            r = mid - 1;
            continue;
        } else {
            l = mid - 1;
        }
    }
    return 0;
}
