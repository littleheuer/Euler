/*************************************************************************
	> File Name: ep58.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月29日 星期六 20时35分26秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max 10000

double num[max + 10][max + 10] = {0};



int main() {
    int i = 3;
    int sum_prime = 3;
    int sum = 4;
    while (sum_prime / sum > 0.1) {
        i++;
        int k = (max + 10) / 2 + i;
        num[k][k] = 
    }
    cout << i << endl;

    return 0;
}
