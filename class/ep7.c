/*************************************************************************
	> File Name: ep07.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 10时05分41秒
 ************************************************************************/

#include<stdio.h>

int prime(int num){
    for(int i = 2; i * i <= num;i ++){
        if(!(num % i)) return 0;
    }
    return 1;
}

int main(){
    int n = 0,num = 2;
    do{
        while(prime(num)) n ++;
        num += 1;
    } while (n < 10001) ;
    printf("%d\n%d\n",n,num);

    return 0;
}
