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

Status push_qTs(Queue q1, Queue q2, ElemType elem) {
    if ((queue_isEmpty(q1) == OK) && (queue_isEmpty(q2) == OK)) {
        queue_in(q1, elem);
        return OK;
    }
    if (queue_elemNumber(q1) > 0) {
        queue_in(q1, elem);
        return OK;
    }
    if (queue_elemNumber(q2) > 0) {
        queue_in(q2, elem);
        return OK;
    }
    return OK;
}

Status pop_qTs(Queue q1, Queue q2) {
    if ((queue_isEmpty(q1) == OK) && (queue_isEmpty(q2) == OK)) {
        printf("Pop failed because both q1 and q2 are null!\n");
        return ERROR;
    }
    
    int q1num = queue_elemNumber(q1);
    int q2num = queue_elemNumber(q2);
    
    if (q1num == 1) {
        queue_out(q1);
        return OK;
    }
    if (q2num == 1) {
        queue_out(q2);
        return OK;
    }
    
    if (q1num > 1) {
        qNode * currentNode = q1->front->next;
        while (currentNode->next != NULL) {
            queue_in(q2, currentNode->elem);
            queue_out(q1);
            currentNode = currentNode->next;
        }
        queue_out(q1);
        
        queue_isEmpty(q1);
    }else if (q2num > 1) {
        qNode * currentNode = q2->front->next;
        while (currentNode->next != NULL) {
            queue_in(q1, currentNode->elem);
            queue_out(q2);
            currentNode = currentNode->next;
        }
        queue_out(q2);
    }
    return OK;
}

void testQueueToStackOperation(void) {
    Queue q1, q2;
    queue_init(&q1);
    queue_init(&q2);
    
    push_qTs(q1, q2, "压栈1");
    push_qTs(q1, q2, "压栈2");
    push_qTs(q1, q2, "压栈3");
    
    pop_qTs(q1, q2);
    //pop_qTs(q1, q2);
    
    queue_show(q1);
    queue_show(q2);
    
    printf("\n\n\n\n");
}
