//
//  main.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
//

#include <stdio.h>
#include "SequentialLink.h"
#include "SingleLinkList.h"

int main(int argc, const char * argv[]) {
    //testSequentialLinkOperation();
    
    LinkNode * link = (LinkNode *)malloc(sizeof(LinkNode));;
    link_init(link);
    
    printf("%d - %p\n",link->data,&(link->next));
    
    
    int * b;
    b = (int *)100;
    printf("b : %d\n",&b);
    
    int * a = NULL;
    printf("a 地址: %p\n",&a);
    
    return 0;
}
