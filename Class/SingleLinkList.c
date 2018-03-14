//
//  SingleLinkList.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "SingleLinkList.h"
#include <time.h>

/*! 注意检查分配到的动态内存是否为空
 1.初始化线性表，即置单链表的表头指针为空
 */

Status InitList(SingleLink * L) {
    * L = (Node *)malloc(sizeof(Node));
    if (!(*L)) {
        printf("Init faied cause OVERFLOW");
        return OVERFLOW;
    }
    (*L)->next = NULL;
    return OK;
}

#pragma mark - Test



void testSingleLinkListOperation(void){
    SingleLink L;
    Status rt = InitList(&L);
    if(rt != OK) return;
    
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i ++) {
        char * buffer;
        GetRandomString(&buffer);
    }
}


