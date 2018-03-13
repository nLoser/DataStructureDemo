//
//  SequentialLink.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "SequentialLink.h"
#include <time.h>

Status sqlist_init(SqList *L, int len) {
    L->elem = (ElemType *)malloc(sizeof(ElemType) * len);
    if (!L->elem) {
        printf("####创建squential link失败####\n");
        return OVERFLOW;
    }
    L->length = 0;
    L->listsize = len;
    printf("####创建sequential link成功####\n");
    return OK;
}

Status sqlist_addValue(SqList *L ,ElemType value) {
    if (L->length == L->listsize) {
        printf("####增加数据squential link失败####\n");
        return OVERFLOW;
    }
    L->elem[L->length] = value;
    ++L->length;
    printf("####增加数据squential link成功####\n");
    return OK;
}

int sqlist_getIndex(SqList *L, ElemType value) {
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == value) {
            return i+1;
        }
    }
    return ERROR;
}

ElemType sqlist_getValue(SqList *L, int index) {
    if (index < 1 || index > L->length+1 ) {
        return ERROR;
    }
    return L->elem[index-1];
}

Status sqlist_insert(SqList *L, int index, ElemType value) {
    if(index < 1 || index > L->length+1) return ERROR;
    if(L->length == L->listsize) return ERROR;
    for (int j = L->length-1; j>=index-1; j--) {
        L->elem[j+1] = L->elem[j];
    }
    L->elem[index-1] = value;
    ++L->length;
    printf("####插入数据squential link成功####\n");
    return OK;
}

Status sqlist_delete(SqList *L, int index, ElemType value) {
    if (index <1 || index > L->length+1) return ERROR;
    for (int j = index; j < L->length-1; j++) {
        L->elem[j-1] = L->elem[j];
    }
    --L->length;
    printf("####删除数据squential link成功####\n");
    return OK;
}

//test
void testSequentialLinkOperation(void){
    SqList * L = (SqList *)malloc(sizeof(SqList));
    sqlist_init(L, 1000);
    
    char * sourceString = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++) {
        char * buffer = malloc(sizeof(char) * 10);
        for (int i = 0; i < 10; i ++) {
            buffer[i] = sourceString[rand()%62];
        }
        buffer[10] = '\0';
        sqlist_addValue(L, buffer);
        printf("--%s\n",buffer);
    }
    printf("当前长度%d\n",L->length);
    sqlist_insert(L, 1, "这是我插入的一个数");
    printf("现在长度%d\n",L->length);
    printf("%s\n",sqlist_getValue(L, 1));
}
