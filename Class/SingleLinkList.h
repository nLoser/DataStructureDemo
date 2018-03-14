//
//  SingleLinkList.h
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
//

#ifndef SingleLinkList_h
#define SingleLinkList_h

#include <stdio.h>
#include "Config.h"

typedef struct Node{
    ElemType elem;
    struct Node * next;
} Node, * SingleLink;

void testSingleLinkListOperation(void);

Status InitList(SingleLink * L);
void linkAdd(SingleLink L, ElemType value);
void getLinkList(SingleLink L);
Node* GetElem(SingleLink L, int index);
Status ListInsert(SingleLink * L, int index, ElemType elem);
Status ListDelete(SingleLink * L, int index);

#endif 
