/*************************************************************************
	> File Name: ep22.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 11时16分20秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<inttypes.h>
#include"22_names.h"
#define max_n 6000

char *ptr[max_n + 5];
int co[max_n + 5] = {0};

void sort(char *ptr[max_n + 5], char name[6000][20]) {
    //char *p;

    for(int i = 0; name + i; i++) {
        //p = name[i];
        for(int j = i + 1; name + j; j++) {
            if(strcmp(name[i], name[j]) > 0) {
                char *p = name[i];
                name[i] = name[j];
                name[j] = p;
            }
            //ptr[i] = p;
        }
    }
    p = NULL;
    return ;
}

void count(char *ptr[max_n + 5], int64_t sum) {
    for(int i = 0; ptr + i; i++) {
        int len = strlen(ptr[i]);
        for(int j = 0; j < len; j++) {
            co[i + 1] += ptr[i][j] - 'A' + 1;
        }
        co[i + 1] += i + 1;
    }
    for(int i = 1; co[i] != 0; i++) {
        sum += co[i];
    }
    return ;
}

int main() {
    int64_t sum = 0;
    sort(ptr, name);
    count(ptr, sum);
    printf("%"PRId64"\n", sum);
    return 0;
}
