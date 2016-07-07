//
// Created by wanli on 6/21/16.
//

#ifndef ROBOT_ROBOT_HEADER_H
#define ROBOT_ROBOT_HEADER_H

//square_size
int init_head(const int square_size);


typedef struct _Position {
    int x;    //所在的位置X值
    int y; //所在的位置Y值
} Position;

/**
 * 接收蛋白质类型，用于蛋白质匹配
 * */
typedef struct _MatchingProtein {
    int type;
    //蛋白质类型，首选匹配，也可以作为索引使用
    char *proteinStr;//需要计算数据块之间的相似度之类的算法
} MatchingProtein;

/**
 * 所释放的递质（此处为蛋白质，实际为乙酰胆碱等）
 * */
typedef struct _NeurotransmitterProtein {
    MatchingProtein protein_type;
    //类型
    char *message;
    //附带的消息
    long receiver;//接收接口
};

/**
 * 神经细胞的接收装置（树突，每个细胞有多个树突）
 * 包含：
 * 1. 其所在的位置
 * 2. 接收接口（都必须有个默认的接口来接收都无法接收的信息）
 * */
typedef struct _Receiver {
    Position position;
    //所在的位置
    long receive;
    //接收函数接口
    MatchingProtein *matching_proteins;//所附带的可以接收蛋白质的接口
} Receiver;

/**
 * 神经细胞的发送装置（轴突，每个细胞只有一个轴突）
 * 包含其所在的位置、发送接口
 * */
typedef struct _Sender {
    Position position;
    long send;//发送函数接口
} Sender;

/**
 * 仿神经细胞，包含如下：
 * 1、接收装置
 * 2、发送装置
 * 3、表达装置（即将所得结论表达出来）
 * 4、处理逻辑
 * */
typedef struct _Nerve {
    Receiver *receiver;    //接收装置
    Sender *sender;         //发送装置
} Nerve;

/**
 * the brain structure
 * */
typedef struct _Brain {
    Nerve **p_nerve;
} Brain;

/**
 * 全局变量
 * */
Brain brain;

#endif //ROBOT_ROBOT_HEADER_H
