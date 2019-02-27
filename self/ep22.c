/*************************************************************************
	> File Name: ep22.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月25日 星期五 11时16分20秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<inttypes.h>
#include"p022_names.h"
#define max_n 6000
#define p(d) {\
    printf("%d\n", d);\
}
#define ps(p) {\
    printf("%s\n", p);\
}

char *ptr[max_n + 5];
int co[max_n + 5] = {0};

void sort(char *ptr[], int count) {
    char *temp;
    for(int i = 0; i < count; i++) {
        //temp = ptr[i];
        for(int j = i + 1; j < count; j++) {
            if(strcmp(ptr[i], ptr[j]) > 0) {
                temp = ptr[j];
                ptr[j] = ptr[i];
                ptr[i] = temp;
            }
        }
    }
    return ;
}

int64_t num_count(char *ptr[], int count) {
    int64_t sum = 0;
    for(int i = 0; i < count; i++) {
        int len = strlen(ptr[i]);
        for(int j = 0; j < len; j++) {
            co[i + 1] += ptr[i][j] - 'A' + 1;
        }
        co[i + 1] =(i + 1) * co[i + 1];
        if(co[i + 1] == 49714) {p(co[i + 1])ps(ptr[i])}
    }
    for(int i = 0; i < count; i++) {
        sum += co[i + 1];
    }
    return sum;
}

int main() {
    int64_t sum = 0;
    int count = 0;
    char *pstr[max_n + 5];
    while(*name[count] != '\0') {
        pstr[count] = name[count];
        //printf("%d %s\n", count, pstr[count]);
        count++;
    }
    sort(pstr, count);
    sum = num_count(pstr, count);
    printf("%"PRId64"\n", sum);
    return 0;
}
