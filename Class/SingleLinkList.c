//
//  SingleLinkList.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/11.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "SingleLinkList.h"

Status link_init(LinkNode * L) {
    if (!L) return OVERFLOW;
    L->data = 99999999;
    L->next = NULL;
    return OK;
}



