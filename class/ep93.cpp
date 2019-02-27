/*************************************************************************
	> File Name: ep93.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月29日 星期六 18时11分46秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
#define MAX_N 10000
int vis[MAX_N + 5] = {0};

double calc(char *result, int n) {
    stack<double> s;
    for (int i = 0; i < n; i++) {
        if (result[i] <= '9' && result[i] >= '0') {
            s.push(result[i] - '0');
            continue;
        }
        a = s.top();s.pop();
        b = s.top();s.pop();
        switch (result[i]) {
            case '+' : s.push(a + b) break;
            case '-' : s.push(a - b) break;
            case '*' : s.push(a * b) break;
            case '/' : s.push(a / b) break;
        }
    }
    return s.top();
}

#define ESP 1e-7

int dfs(char *result, int k ,int a, int b, int *num) {//a当前数字数量，b当前符号数
    if(k == 7) {
    //计算后缀表达式的值
        int ret = calc(result, 7);
        if fabs(ret> 0 && ret - floor(ret) < ESP) {
            vis[(int)ret] = 1;
        }
    }
    if(b + 1 < a) {
        result[k] = '+', dfs(result, k + 1, a, b + 1, num);
        result[k] = '-', dfs(result, k + 1, a, b + 1, num);
        result[k] = '*', dfs(result, k + 1, a, b + 1, num);
        result[k] = '/', dfs(result, k + 1, a, b + 1, num);
    }
    if(a < 4) {
        result[k] = num[a];
        dfs(result, k+ 1, a + 1, b, num);
    }
    return 0;
}

int len = 0, ret = 0;//len记录1～len,ret record the answer

void dfs2(int *num,int k) {
    if(k == 4) {
        char result[7] = {0};
        memset(vis, 0, sizeof(vis));
        do {
            dsf(result, 0, 0, 0, num);
        } while (next_permutation(num, num + 4));
        int temp_len = 1;
        for (temp_len - 1 > len) {
            len = temp_len;
            ret = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
        }
        return ;
    }
    int begin = (k == 0 ? 1 : num[k - 1] + 1);
    for (int i = begin; i <= 9; i++) {//????
        num[k] = i;
        dsf2(num, k + 1);
    }
}

int main() {
    int num[4];
    dfs2(num, 0);
    cout << ret <<endl;
    
    return 0;
}
