/*************************************************************************
	> File Name: 19.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月24日 星期四 18时54分55秒
 ************************************************************************/

#include<stdio.h>

//要想1号是星期天，必须是7的倍数

int is_leapyear (int year) {
    if(year % 400 == 0) {
        return 1;
    } else if(year % 4 == 0 && year % 100 != 0) {
        return 1;
    }
    return 0;
}

int Month[2][13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int is_sunday (int year, int month, int week, int temp) {
    week += Month[temp][month];
    week %= 7;
    return week;
}

int main() {
    //1900.1.1为星期一,则1901.1.1为星期二
    int week = 365 % 7 + 1;
    int count = 0;
    for (int year = 1901; year <= 2000; year++) {
        for (int month = 1;month <= 12; month++) {
            int temp = is_leapyear (year);
            week = is_sunday (year, month, week, temp);
            count += (!week);
        }
    }
    printf("%d\n", count);
    return 0;

}
