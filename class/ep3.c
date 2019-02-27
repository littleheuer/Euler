/*************************************************************************
	> File Name: ep03.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 16时26分35秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
//int 十位数
//inttypes.h c99推出的头文件

int main(){
    int64_t num = 600851475143, x = 2, ans;
    while (x * x <= num){
        if(num % x){
            x++;
            continue;
            printf("%" PRId64 "\n", x);
        }
        //证明：x一定是素数
        //答:素因子
        ans = x;
        while (num % x == 0) num /= x;
        //x+= 1;
    }
    if(num - 1) ans = num;//证明：这行代码是必要的
    //答：可能本身是素数.
    printf("%" PRId64 "\n", ans);
    return 0;
}
