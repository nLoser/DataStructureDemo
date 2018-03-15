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
    (*stack)->bottom = (*stack)->top;
    (*stack)->bottom->elem = "#BOTTOM#";
    (*stack)->top->next = NULL;
    return OK;
}

Status stack_push(StackList stack, ElemType elem) {
    if (stack == NULL) {
        printf("Stack is null");
        return ERROR;
    }
    sNode * newNode = (sNode*)malloc(sizeof(sNode));
    if(newNode == NULL) {
        printf("Push failed!\n");
        return OVERFLOW;
    }
    newNode->elem = elem;
    newNode->next = stack->top;
    stack->top = newNode; //top永远指的是栈顶
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
    printf("%s\n",curNode->elem);
    return OK;
}

Status stack_clean(StackList stack) {
    if (stack == NULL) {
        printf("Stack clean failed cause stack is not exit\n");
        return ERROR;
    }
    if (stack->top == stack->bottom) {
        printf("Stack is null\n");
        return ERROR;
    }
    
    sNode * freeNode = stack->top;
    sNode * curNode = stack->top;
    
    while (freeNode->next != NULL) {
        curNode = curNode->next;
        free(freeNode);
        freeNode = curNode;
    }
    stack->top = curNode;
    return OK;
}

//test
void testStackListOperation(void) {
    StackList stack;
    stack_init(&stack);
    
    stack_push(stack, "吕洪阳");
    stack_push(stack, "Stay foolish, stay hungry.");
    stack_push(stack, "Of course!");
    for (int i = 0; i < 2; i++) {
        char * str;
        GetRandomString(&str);
        stack_push(stack, str);
    }
    stack_output(stack);
    printf("\n\n");
    
    stack_clean(stack);
    stack_output(stack);
    printf("\n\n");
}
