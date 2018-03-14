//
//  SingleLinkList.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "SingleLinkList.h"
#include <time.h>

//初始化链头
Status link_init(LinkNode * L) {
    if (!L) return OVERFLOW;
    L->data = "链头";
    L->next = NULL;
    L->length = 0;
    return OK;
}

Status link_addValue(SingleLink L,ElemType value) {
    LinkNode * node = (LinkNode *)malloc(sizeof(LinkNode));
    if (!node) return ERROR;
    node->data = value;
    node->next = NULL;
    
    LinkNode * currentNode = L;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = node;
    
    ++L->length;
    //printf("####添加数据(%s)成功%d####\n",node->data,L->length);
    return OK;
}

/// 插入
Status link_insert(SingleLink L, int index, ElemType value) {
    LinkNode * node = L;
    int j = 0;
    while (node && j < index-1) {
        node = node->next;
        ++j;
    }
    if(!node || j > index) return ERROR;
    LinkNode * tempNode = node->next;
    
    LinkNode * valueNode = (LinkNode *)malloc(sizeof(LinkNode));
    valueNode->data = value;
    valueNode->next = tempNode;
    
    node->next = valueNode;
    
    return ERROR;
}

LinkNode * link_getNode(SingleLink L, int index) {
    int i = 1;
    LinkNode * currentNode = L;
    while (currentNode->next != NULL) {
        if (index == i) {
            return currentNode;
        }
        currentNode = currentNode->next;
        ++i;
    }
    return NULL;
}

void testSingleLinkListOperation(void){
    SingleLink L = (LinkNode *)malloc(sizeof(LinkNode));
    if (link_init(L) != 1) {
        printf("初始化失败");
        return;
    }
    
    char * sourceString = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i ++) {
        char * buffer = malloc(sizeof(char) * 10);
        for (int j = 0; j < 10; j ++) {
            buffer[j] = sourceString[rand()%62];
        }
        buffer[10] = '\0';
        link_addValue(L, buffer);
    }
    link_insert(L, 3, "新版本链头");
    
    LinkNode * currentNode = L;
    while (currentNode->next != NULL) {
        printf("----%s\n",currentNode->data);
        currentNode = currentNode->next;
    }
    printf("----%s\n",currentNode->data);
    
    //malloc
    //内存动态存储区申请一个length = size 字节的连续空间；
    //calloc
    //内存动态存储区申请n个length = size 字节的连续空间；
}
