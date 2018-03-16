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

Status pop_qTs(Queue q1, Queue q2) {
    if ((queue_isEmpty(q1) == OK) && (queue_isEmpty(q2) == OK)) {
        printf("Pop failed because both q1 and q2 are null!\n");
        return ERROR;
    }
    
    int q1num = queue_elemNumber(q1);
    int q2num = queue_elemNumber(q2);
    if (q1num == 1) {
        queue_out(q1);
        printf("pop stack : q1\n");
        return OK;
    }
    if (q2num == 1) {
        queue_out(q2);
        printf("pop stack : q2\n");
        return OK;
    }
    
    Queue stackq;
    Queue queue;
    if (q1num > 1) {
        stackq = q1;
        queue = q2;
    }else {
        stackq = q2;
        queue = q1;
    }
    qNode * currentNode = stackq->front->next;
    while (currentNode->next->next != NULL) {
        queue_in(queue, currentNode->elem);
        queue_out(stackq);
        currentNode = stackq->front->next;
    }
    queue_out(stackq);
    return OK;
}

Status push_qTs(ElemType value, Queue q1, Queue q2) {
    
    return OK;
}

void testQueueToStackOperation(void) {
    Queue q1, q2;
    queue_init(&q1);
    queue_init(&q2);
    queue_in(q1, "压栈1");
    queue_in(q1, "压栈2");

    pop_qTs(q1, q2);
    
    printf("\nQ1\n");
    queue_show(q1);
    
    printf("\nQ2\n");
    queue_show(q2);
}
