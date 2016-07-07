//
// Created by wanli on 6/21/16.
//

#include "robot_header.h"

//初始化大脑
int init_head(const int square_size) {

    //-----------------Step 1:初始化大脑内神经元细胞个数--------------------
    Nerve nerves[square_size][square_size];
    brain.p_nerve = nerves;

    //-----------------Step 2:初始化神经元的轴突（发送装置）-----------------
    //初始化个数和位置
    //多线程摆动

    //-----------------Step 3:初始化神经元的树突（接收装置）-----------------
    //初始化个数和位置
    //多线程摆动

    return 0;
}