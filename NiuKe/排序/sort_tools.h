//
// Created by snow on 19-8-30.
//

#ifndef SORT_TOOLS_H
#define SORT_TOOLS_H

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>

void array_out(int *a, int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d\t", a[i]);
    }
    printf("\n\n");
}


void swap_xl(int *a, int index0, int index1)
{
    assert(a != NULL);

    int temp = a[index0];
    a[index0] = a[index1];
    a[index1] = temp;
}

#endif //SORT_TOOLS_H
