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
    if (*stack) {
        (*stack)->top = (sNode*)malloc(sizeof(sNode));
    }
    if ((*stack) == NULL || (*stack)->top == NULL) {
        printf("Init failed cause OVERFLOW");
        return OVERFLOW;
    }
    printf("Init success!\n");
    (*stack)->bottom = (*stack)->top;
    (*stack)->bottom->elem = "bottom";
    (*stack)->top->elem = "top";
    (*stack)->top->next = NULL;
    return OK;
}

Status stack_push(StackList stack, ElemType elem) {
    if (stack == NULL) {
        printf("Stack is null");
        return ERROR;
    }
    sNode * node = (sNode*)malloc(sizeof(sNode));
    if(node == NULL) {
        printf("Push failed!\n");
        return OVERFLOW;
    }
    node->elem = elem;
    node->next = stack->top;
    stack->top = node;
    return OK;
}

Status stack_pop(StackList stack) {
    if (stack == NULL) {
        printf("Pop failed cause stack is not exit\n");
        return ERROR;
    }
    if (stack->top == stack->bottom) {
        printf("Pop failed casuse stack is null\n");
        return ERROR;
    }
    sNode * freeNode = stack->top;
    stack->top = stack->top->next;
    free(freeNode);
    printf("Pop Success\n");
    return OK;
}

Status stack_output(StackList stack) {
    if (stack == NULL) {
        printf("Show failed cause stack is not exit\n");
        return ERROR;
    }
    if (stack->top == stack->bottom) {
        printf("Stack is null\n");
        return ERROR;
    }
    sNode* curNode = stack->top;
    while (curNode->next != NULL) {
        printf("put<< %s\n",curNode->elem);
        curNode = curNode->next;
    }
    return OK;
}

//test
void testStackListOperation(void) {
    StackList stack;
    stack_init(&stack);
    
    stack_push(stack, "吕洪阳");
    stack_push(stack, "Stay foolish, stay hungry");
    stack_output(stack);
    printf("\n\n");
    
    stack_pop(stack);
    stack_output(stack);
    printf("\n\n");

    for (int i = 0; i < 10; i++) {
        char * str;
        GetRandomString(&str);
        stack_push(stack, str);
    }
    stack_output(stack);
    printf("\n\n");
}
