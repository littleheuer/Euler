/*************************************************************************
	> File Name: ep49.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年02月01日 星期五 23时27分37秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<inttypes.h>
using namespace std;

#define max_n 10000

typedef struct {
    //num为原数字，rnum为数字表示法
    int num,rnum;
} Sint;
//pSint记录i对应的数字表示法
int prime[max_n + 5] = {0};
int pSint[max_n + 5] = {0};
int dlen = 0;
Sint d[max_n + 5] = {0};

int IntToSint(int n) {
    int rnum = 0, x = n;
    while(n) {
        rnum += 1 << (2 * (n % 10));
        n /= 10;
    }
    return rnum;
}

bool cmp(Sint a, Sint b) {
    if(a.rnum < b.rnum) return true;
    if(a.rnum == b.rnum && a.num < b.num) return true;
    return false;
}

void initData() {
    for(int i = 2; i <= max_n; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            if(i >= 1000) {
                d[dlen].num = i;
                d[dlen].rnum = IntToSint(i);
                pSint[i] = d[dlen].rnum;
                dlen++;
            }
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    initData();
    sort(d, d + dlen, cmp);
    for(int i = 0; i < dlen - 2; i++) {
        int j = i + 1, nextNum;
        while(d[j].rnum == d[i].rnum) {
            nextNum = 2 * d[j].num - d[i].num;
            if(nextNum >= 10000) break;
            if(pSint[nextNum] == d[i].rnum) {
                printf("%d%d%d\n", d[i].num, d[j].num, nextNum);
            }
            //在rnum相同的连续数附近找,若rnum不相等则i++
            j++;
        }
    }
    return 0;
}
