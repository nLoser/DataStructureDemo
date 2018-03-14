//
//  SingleLinkList.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "SingleLinkList.h"
#include <time.h>

/*! 注意检查分配到的动态内存是否为空
 1.初始化单链表
 */

Status InitList(SingleLink * L) {
    * L = (Node *)malloc(sizeof(Node));
    if (!(*L)) {
        printf("Init faied cause OVERFLOW");
        return OVERFLOW;
    }
    (*L)->next = NULL;
    return OK;
}

Node* GetElem(SingleLink L, int index) {
    Node * node = L;
    int i = 1;
    while (node && i < index) {
        node = node->next;
        ++index;
    }
    if (!node || i > index) {
        printf("Get element failed cause the index node is non-existent\n");
        return ERROR;
    }
    printf("Get the node element:%s\n",node->elem);
    return node;
}

Status ListInsert(SingleLink * L, int index, ElemType elem) {
    SingleLink newL = *L;
    int i = 0;
    while (newL && i < index-1) {
        newL = newL->next;
        ++i;
    }
    if(!newL || i>index-1) {
        printf("Inset element failed!\n");
        return ERROR;
    }
    SingleLink newS = (Node *)malloc(sizeof(Node));
    newS->elem = elem;
    newS->next = newL->next;
    newL->next = newS;
    return OK;
}

void getLinkList(SingleLink L) {
    Node * node = L;
    while (node->next != NULL) {
        printf("get<< %s\n",node->elem);
        node = node->next;
    }
    printf("get<< %s\n",node->elem);
}

#pragma mark - Test

void testSingleLinkListOperation(void){
    SingleLink L;
    Status rt = InitList(&L);
    if(rt != OK) return;
    
    srand((unsigned int)time(NULL));
    for (int i = 1; i < 10; i ++) {
        char * buffer;
        GetRandomString(&buffer);
        ListInsert(&L, i, buffer);
    }
    
    ListInsert(&L, 1, "插入一个值");
    
    getLinkList(L);
}


