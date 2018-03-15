//
//  StackLink.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/15.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "StackLink.h"

Status stack_init(StackList * stack) {
    *stack = (Stack *)malloc(sizeof(Stack));
    if ((*stack) == NULL) {
        printf("Init failed cause OVERFLOW");
        return OVERFLOW;
    }
    printf("Init success!\n");
    (*stack)->top = (*stack)->bottom;
    return OK;
}

//test
void testStackListOperation(void) {
    StackList stack;
    stack_init(&stack);
}
