//
//  Queue.h
//  DataStructureDemo
//
//  Created by LV on 2018/3/15.
//  Copyright © 2018年 LV. All rights reserved.
//  使用链表结构来实现一个队列

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include "Config.h"

typedef struct qNode{
    ElemType elem;
    struct qNode * next;
}qNode;

typedef struct queue{
    qNode * front;
    qNode * rear;
}queue, * Queue;

Status queue_init(Queue * Q);
Status queue_show(Queue Q);
Status queue_in(Queue Q, ElemType value);
Status queue_out(Queue Q);

//test
void testQueueListOperation(void);

#endif /* Queue_h */
