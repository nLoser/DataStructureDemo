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
    L->data = "我是链头";
    L->next = NULL;
    L->length = 0;
    return OK;
}

//增

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
    printf("####添加数据(%s)成功%d####\n",node->data,L->length);
    return OK;
}

//插
Status link_insert(SingleLink L, int index, ElemType value) {
    LinkNode * node = (LinkNode *)malloc(sizeof(LinkNode));
    if (!node) return ERROR;
    node->data = value;
    
    int i = 1;
    LinkNode * currentNode = L;
    while (currentNode->next != NULL) {
        if (i == index) {
            LinkNode * tempNode = currentNode->next;
            currentNode->next = node;
            node->next = tempNode;
            ++L->length;
            printf("插入\"%s\"成功index:%d\n",value,index);
            break;
        }
        currentNode = currentNode->next;
        ++i;
    }
    return OK;
}

//查

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

//删

//改

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
    
    link_insert(L, 1, "无心胭脂");
    printf("获取%s\n",link_getNode(L, 1)->data);
    
    LinkNode * currentNode = L;
    while (currentNode->next != NULL) {
        printf("----%s\n",currentNode->data);
        currentNode = currentNode->next;
    }
    
    printf("%s\n",L->data);
}
