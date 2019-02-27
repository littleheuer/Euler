/*************************************************************************
	> File Name: ep27.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月29日 星期六 15时42分26秒
 ************************************************************************/
//欧拉函数
#include<iostream>
using namespace std;
#define max_n 100000


int prime[ma_n + 5] = {0};
int phi[max_n + 5] = {0};//

void init() {
    for(int i = 2; i <= max; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > max_n) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                    phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    return ;
}


int main() {
    init();
    long long sum = 0;
    for(int i = 2; i <= max; i++) sum +=ph[i];
    cout << sum << endl;
    return 0;
}
