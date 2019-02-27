/*************************************************************************
	> File Name: quick_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 17时56分12秒
 ************************************************************************/

#include<stdio.h>
#define max 1000
void quick_sort(int *arr, int l, int r) {
    int x = l, y = r, temp = arr[l];
    if(l >= r) return;
    while(x < y) {
        while(x < y && arr[y] >= temp) --y;
        if(x < y) arr[x++] = arr[y];
        while(x < y && arr[x] <= temp) ++x;
        if(x < y) arr[y--] = arr[x];
    }
    arr[x] = temp;
    quick_sort(arr, l, x - 1);
    quick_sort(arr, x + 1, r);
}

int main() {
    int arr[max] = {0};
    for(int i = 0; i < max; i++) {
        scanf("%d", arr + i);
    }
    quick_sort(arr, 0, max - 1);
    for(int i = 0; i < max; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}
