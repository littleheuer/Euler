/*************************************************************************
	> File Name: ep8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 16时18分47秒
 ************************************************************************/

#include<stdio.h>
#define max 1000

int num[max];

int find(){
    int ans = 0;
    for(int i = 1; i <= max - 9; i ++){
        for(int j = i; j <= 9 + i; j++){
            num[i] *= num[j];
        }
    }
    ans = num[i];
    for(int i = 2; i <= max; i++){
        if(ans < num[i]) ans = num[i];
    }
    return ans;
}

int main(){
    printf("%d", find());
    return 0;
}
