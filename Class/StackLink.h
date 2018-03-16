//
//  StackLink.h
//  DataStructureDemo
//
//  Created by LV on 2018/3/15.
//  Copyright © 2018年 LV. All rights reserved.
//

#ifndef StackLink_h
#define StackLink_h

#include <stdio.h>
#include "Config.h"

//ADT:

typedef struct sNode{
    ElemType elem;
    struct sNode * next;
}sNode;

typedef struct Stack{
    sNode * top;     ///< 栈顶
    sNode * bottom;  ///< 栈的头结点(栈尾下个结点)
}Stack, *StackList;

Status stack_init(StackList * stack);
Status stack_push(StackList stack, ElemType elem);
Status stack_pop(StackList stack);
Status stack_output(StackList stack);
Status stack_clean(StackList stack);

//test
void testStackListOperation(void);

#endif /* StackLink_h */
