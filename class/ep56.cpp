/*************************************************************************
	> File Name: ep56.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月29日 星期六 19时49分01秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max 300

int main() {
    int ans = 0;
    for(int a = 2; a < 100; a++) {
        int num[max + 5] = {0};
        num[1] = a;
        num[0] = 1;
        for(int j = 2; j < 100; j++) {
            for(int k = 1; k <= num[0]; k++) num[k] *= a;
            for(int l = 1; l <= num[0]; l++) {
                if(num[l] < 10) continue;
                num[l + 1] += num[j] % 10;
                num[l] /= 10;
                num[0] += (num[0] == l);
            }
            int sum = 0;
            for(int k = 1; k <= num[0]; k++) sum += num[k];
            if(ans < sum) ans = sum;
       }
    }
    cout << ans <<endl;
    return 0;
}
