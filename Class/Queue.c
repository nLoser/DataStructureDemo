//
//  Queue.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/15.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "Queue.h"

Status queue_init(Queue * Q) {
    (*Q) = (queue *)malloc(sizeof(queue));
    if (*Q) {
        (*Q)->front = (qNode *)malloc(sizeof(qNode));
    }
    if ((*Q) == NULL || ((*Q)->front) == NULL) {
        return OVERFLOW;
    }
    (*Q)->rear = (*Q)->front;
    (*Q)->front->elem = "Front";
    printf("Init success.\n");
    return OK;
}

Status queue_add(Queue Q, ElemType value) {
    qNode * newRearNode = (qNode *)malloc(sizeof(qNode));
    if (newRearNode == NULL) {
        return OVERFLOW;
    }
    newRearNode->elem = value;
    newRearNode->next = NULL;
    Q->rear->next = newRearNode;
    Q->rear = Q->rear->next;
    return OK;
}

Status queue_show(Queue Q) {
    if (Q->front == Q->rear) {
        printf("Show queue failed cause queue is null");
        return ERROR;
    }
    qNode * node = Q->front->next;
    while (node->next != NULL) {
        printf("put<< %s\n",node->elem);
        node = node->next;
    }
    return OK;
}

void testQueueListOperation(void) {
    Queue q;
    queue_init(&q);
    printf("\n\n");
    
    for (int i = 0; i < 10; i ++) {
        char * buffer;
        GetRandomString(&buffer);
        queue_add(q, buffer);
    }
    queue_show(q);
}
