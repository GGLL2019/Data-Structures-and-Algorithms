/**
 * @brief 排序
 * @email xueliang2007@qq.com
 * @date  2019.9.12
 */

#include "sort_tools.h"

using namespace std;

void merge(int *a0, int s0, int *a1, int s1, int max_size)
{
    int i, j, k;
    i = j = k = 0;
    int temp[max_size];
    while (i < s0 && j < s1){
        if (a0[i] <= a1[j]){
            temp[k++] = a0[i++];
        } else{
            temp[k++] = a1[j++];
        }
    }

    while (i < s0){
        temp[k++] = a0[i++];
    }

    while (j < s1){
        temp[k++] = a1[j++];
    }
    std::memcpy(a0, temp, (s0+s1)* sizeof(int));
}



void merge_sort(int *a, int n)
{
    if(n > 1){
        int *a0 = a;
        int s0 = n/2;
        int *a1 = a + s0;
        int s1 = n - s0;
        merge_sort(a0, s0);
        merge_sort(a1, s1);
        merge(a0, s0, a1, s1, n);
    }
}



int main()
{
    int a[] = {1, 8, 9, 2, 6, 4, 5, 7, 0, 5, 9, 7, 3, 9, 5, 8, 4, 3, 1, 0};
    int n = sizeof(a)/ sizeof(int);
    printf("array size is %d\ninit:\n", n);

    merge_sort(a, n);
    array_out(a, n);
}