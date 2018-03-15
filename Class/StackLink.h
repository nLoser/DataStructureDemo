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

//Operation
//1.入栈
//2.出栈
//3.便利输出
//4.清栈
//5.栈是否为空/满(顺序存储设计到满的问题，而随机存储不涉及满的情况)

//test
void testStackListOperation(void);

#endif /* StackLink_h */
