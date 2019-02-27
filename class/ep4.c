/*************************************************************************
	> File Name: ep04.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 18时04分54秒
 ************************************************************************/

#include<stdio.h>
   
int is_valid(int x){
    int temp = x, num = 0;
    while(x){//将x倒置并赋值给temp
        num = num * 10 + x % 10;
        x /= 10;
    }
    return temp == num;
}

int main(){
    int ans = 0;
    for(int a = 100; a < 1000;a ++){
        for(int b = ans / a + 1; b <= a; b++){//保证b从上一个大于b开始算
            if(!is_valid(a * b)) continue;//使axb为回数
            if(ans >= a * b) continue;//导致a×b大于ans
            printf("%d * %d = %d\n", a, b, a*b);
            ans = a * b;
        }
    }

    printf("%d\n", ans);
    return 0;
}//还可倒置去找,但是也不能直接找到最大的。
