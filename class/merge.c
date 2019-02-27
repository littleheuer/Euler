/*************************************************************************
	> File Name: /sort/merge_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 16时01分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
#define swap(a,b) {\
    _typeof(a) _temp = a;\
    a = b; b = _temp;\
}
void mergeSort(int *num,int l, int r) {
    if (r - l <= 1) {
        if(r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return ;
    }
    int mid = l +r >> 1;
    mergeSort(num, l, mid);
    mergeSort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r -  l + 1));

    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if(p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l +1));//覆盖num里相应的位置
    free(temp);
    return;
}

void output(int *a, int n) {
    printf("%d", a[0]);
    for(int i = 1; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[max +5] = {0};
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        mergeSort(a, 0, n - 1);
        output(a, n);
    }

    return 0;
}
