//
// Created by wanli on 7/6/16.
//

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/soundcard.h>
#include <alsa/asoundlib.h>

#include "util/robot_util.h"

int testFunction(int a) {
    return a + 1;
}

typedef int (*func)(int);

//测试函数指针
void test1() {
    long addr = &testFunction;
    int ret_value = ((func) (addr))(3);
    printf(" value is %d", ret_value);
}

//测试音频播放
void test2() {
    play_sound("/home/wanli/code/test/MFM8_BONUS/MFM8_108_BonusPerc_18.wav", 44100, 24, 3, 3);
}

int main() {
    test2();
    return 0;
}