/*************************************************************************
	> File Name: ep53.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月29日 星期六 19时27分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max 100
int num[max + 5][max + 5] = {0};
int p[100][100] = {0};
void init() {
    for (int i = 0; i < 100; i++) {
        num[i][0] = num[i][i] = 1;
    }
}

void point() {
    for(int i = 2; i < 100; i++) {
        for(int j = 1; j < i; j++) {
            if(num[i][j]) continue;
            if(p[i - 1][j - 1] || p[i - 1][j]) {
                p[i][j] = 1;
                continue;
            }
            num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
        }
    }
}

int main() {
    int count = 0;
    init();
    point();

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(p[i][j]) count++;
        }
    }
    cout << count << endl;
    return 0;
}
