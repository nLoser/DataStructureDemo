//
//  SequentialLink.h
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
//

#ifndef SequentialLink_h
#define SequentialLink_h

#include <stdio.h>
#include "Config.h"

typedef struct {
    ElemType * elem; ///< 存储空间
    int length; ///< 当前长度
    int listsize; ///< 当前分配的存储容量
}SqList;

Status sqlist_init(SqList *L, int len);

Status sqlist_addValue(SqList *L ,ElemType value);

int sqlist_getIndex(SqList *L, ElemType value);
ElemType sqlist_getValue(SqList *L, int index);

Status sqlist_insert(SqList *L, int index, ElemType value);
Status sqlist_delete(SqList *L, int index, ElemType value);

//test
void testSequentialLinkOperation(void);

#endif
