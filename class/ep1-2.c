/*************************************************************************
	> File Name: ep1-2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 14时19分51秒
 ************************************************************************/#include<stdio.h>

int main(){
    int sum3 = (3 + 999)*333 / 2; 
    int sum5 = (5 + 995)*(995 / 5) / 2;
    int sum15 =  (15 + 999/15*15)*(999 / 15) / 2;
    printf("%d\n",sum3 + sum5 - sum15);
    return 0;
}
