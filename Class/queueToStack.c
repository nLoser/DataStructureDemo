//
//  queueToStack.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/16.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "queueToStack.h"

/*
 两个队列模拟一个栈的思路:
 q1 q2
 
 出栈:
 1.首先，判断q1和q2是否是空的，空的返回失败；
 2.如果其中有一个队列只有一个元素，则出栈这个元素；
 4.如果其中有一个队列A有多个元素，且另一个队列B没有元素，然后把A的元素依次压入B队列且只留下最后一个元素，最后出栈这个元素；
 入栈:
 1.首先，判断q1和q2都空时，就把元素插入q1中；
 2.如果其中一个队列A有元素，则在这个队列后入栈将要入栈的元素；
 */

Status push_qTs(ElemType value, Queue q1, Queue q2) {
    
    return OK;
}

Status pop_qTs(Queue q1, Queue q2) {
    
    return OK;
}

void testQueueToStackOperation(void) {
    Queue q1, q2;
    queue_init(&q1);
    queue_init(&q2);

    push_qTs("入栈", q1, q2);
    pop_qTs(q1, q2);
}
