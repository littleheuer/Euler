/*************************************************************************
	> File Name: ep05.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 09时48分12秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a,int b){
    return (b ? gcd(b,a % b): a);
}


int main(){
    int ans = 1;
    for(int i = 1;i <=20;i ++){
        if(ans % i == 0) continue;
        ans = ans * i / gcd(ans,i);
    }
    printf("%d\n",ans);
    return 0;
}
