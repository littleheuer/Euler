/*************************************************************************
	> File Name: ep34.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 20时28分40秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 2540160
int is_valid(int x){
   int sum = 0,temp = x;
    
    while(x){
        int temp1 = 1;
        for(int i = x % 10;i > 1; i --){
            temp1 *= i;
        }
        sum += temp1;
          
    x /= 10;
    }
    return sum == temp;


}
int main(){

    int sum = 0;
    for(int i = 3;i <= MAX_N; i ++){
        if(!is_valid(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);

    return 0;

}
