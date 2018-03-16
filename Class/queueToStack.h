//
//  queueToStack.h
//  DataStructureDemo
//
//  Created by LV on 2018/3/16.
//  Copyright © 2018年 LV. All rights reserved.
//  用两个队列实现一个栈

#ifndef queueToStack_h
#define queueToStack_h

#include "StackLink.h"
#include "Queue.h"

#include <stdio.h>

Status push_qTs(ElemType value, Queue q1, Queue q2);
Status pop_qTs(Queue q1, Queue q2);

//test
void testQueueToStackOperation(void);

#endif
