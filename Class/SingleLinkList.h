//
//  SingleLinkList.h
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
// 增 删 改 查

#ifndef SingleLinkList_h
#define SingleLinkList_h

#include <stdio.h>
#include "Config.h"

typedef struct Node{
    ElemType elem;
    struct Node * next;
} Node, * SingleLink;

void testSingleLinkListOperation(void);

#endif 
