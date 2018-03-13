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
    return OK;
}

//增

Status link_addValue(SingleLink L,ElemType value) {
    LinkNode * node = (LinkNode *)malloc(sizeof(LinkNode));
    if (!node) return ERROR;
    node->data = value;
    node->next = NULL;
    L->next = node;
    printf("####添加数据Single Link成功####\n");
    return OK;
}

//插

//删

//查

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
        buffer[10] = '\n';
        link_addValue(L, buffer);
        printf("%s\n",buffer);
    }
    
    printf("%s\n",L->data);
}
