//
//  Global.c
//  DataStructureDemo
//
//  Created by LV on 2018/3/14.
//  Copyright © 2018年 LV. All rights reserved.
//

#include "Global.h"
#include <stdlib.h>

static char * sourceString = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

void GetRandomString(char**buffer) {
    *buffer = malloc(sizeof(char)*10);
    for (int i = 0; i < 10; i ++) {
        (*buffer)[i] = sourceString[rand()%62];
    }
    (*buffer)[10] = '\0';
    printf("<< %s\n",*buffer);
}
