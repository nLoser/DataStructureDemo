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
        printf("Init failed!\n");
        return OVERFLOW;
    }
    (*Q)->rear = (*Q)->front;
    (*Q)->front->elem = "Front";
    return OK;
}

int queue_elemNumber(Queue Q) {
    if (queue_isEmpty(Q) == OK) {
        return 0;
    }
    qNode * node = Q->front->next;
    int i = 0;
    while (node != NULL) {
        i++;
        node = node->next;
    }
    return i;
}

Status queue_isEmpty(Queue Q) {
    if (Q->front == Q->rear) {
        return OK;
    }
    return ERROR;
}

Status queue_show(Queue Q) {
    if (Q->front == Q->rear) {
        printf("\nShow queue failed cause queue is null!\n");
        return ERROR;
    }
    qNode * node = Q->front->next;
    int i = 0;
    printf("\n<Front>%s\n",Q->front->elem);
    while (node != NULL) {
        i++;
        printf("put<< %s\n",node->elem);
        node = node->next;
    }
    return OK;
}

Status queue_in(Queue Q, ElemType value) {
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

Status queue_out(Queue Q) {
    if (Q->front == Q->rear) {
        printf("Out failed cause queue is null!");
        return ERROR;
    }
    qNode * freeNode = Q->front->next;
    Q->front->next = Q->front->next->next;
    free(freeNode);
    return OK;
}

void testQueueListOperation(void) {
    Queue q;
    queue_init(&q);
    printf("\n\n");
    
    for (int i = 0; i < 2; i ++) {
        char * buffer;
        GetRandomString(&buffer);
        queue_in(q, buffer);
    }
    printf("增加之后\n");
    queue_show(q);
    printf("\n\n");
    
    printf("移除之后\n");
    queue_out(q);
    queue_show(q);
}
