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
    ElemType * elem;
    int length;
    int listsize;
}SqList;

Status sqlist_init(SqList *L, int len);
Status sqlist_addValue(SqList *L ,ElemType value);
ElemType sqlist_getValue(SqList *L, int index);
Status sqlist_insert(SqList *L, int index, ElemType value);
Status sqlist_delete(SqList *L, int index, ElemType value);
int sqlist_getIndex(SqList *L, ElemType value);

//test
void testSequentialLinkOperation(void);

#endif
