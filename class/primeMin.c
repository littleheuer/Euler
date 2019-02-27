/*************************************************************************
	> File Name: primeMax.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 14时15分45秒
 ************************************************************************/

#include<stdio.h>
int primeMax(int m){
    int ans;
    for(int i = 2;i*i <= m; i++){
        if(m % i) continue;
        ans = i;
        m = m / i;
    }
   if(m - 1) ans = m;

    return ans;
}
int primeMin(int m){
    int ans;
    for(int i = 2;i <= m; i++){
        if(m % i) continue;
        ans = i;;
    }
    return ans;
}
int main(){
    int m;
    scanf("%d",&m);
    printf("%d", primeMax(m));
    return 0;
}
