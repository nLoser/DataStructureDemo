//
//  SingleLinkList.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "SingleLinkList.h"
#include <time.h>

Status InitList(SingleLink * L) {
    * L = (Node *)malloc(sizeof(Node));
    if (!(*L)) {
        printf("Init faied cause OVERFLOW");
        return OVERFLOW;
    }
    (*L)->next = NULL;
    return OK;
}

void linkAdd(SingleLink L, ElemType value) {
    Node * node = L;
    while (node->next != NULL) {
        node = node->next;
    }
    if (node) {
        Node * tempNode = (Node *)malloc(sizeof(Node));
        tempNode->elem = value;
        tempNode->next = NULL;
        node->next = tempNode;
    }
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

void getLinkList(SingleLink L) {
    Node * node = L;
    while (node->next != NULL) {
        printf("put<< %s\n",node->elem);
        node = node->next;
    }
    printf("put<< %s\n",node->elem);
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

Status ListDelete(SingleLink * L, int index) {
    SingleLink newL = *L;
    int i = 0;
    while (newL->next && i < index-1) { //头结点不可删除
        newL = newL->next;
        ++i;
    }
    if(!(newL->next) || i > index-1) {
        printf("Delete element failed!\n");
        return OVERFLOW;
    }
    SingleLink newS = newL->next;
    newL->next = newS->next;
    free(newS);
    return OK;
}

void listReverse(SingleLink head) {
    SingleLink cur, temp, new;
    cur = head->next;
    new = NULL;
    while (cur) {
        temp = cur->next;
        cur->next = new;
        new = cur;
        cur = temp;
    }
    head->next = new;
}

#pragma mark - Test

void testSingleLinkListOperation(void){
    SingleLink L;
    Status rt = InitList(&L);
    if(rt != OK) return;
    
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 4; i ++) {
        char * buffer;
        GetRandomString(&buffer);
        linkAdd(L, buffer);
    }
    
    ListInsert(&L, 1, "插入Node");
    getLinkList(L);
    printf("\n\n");
    listReverse(L);
    getLinkList(L);
}


