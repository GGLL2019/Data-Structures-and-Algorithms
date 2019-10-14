/**
 * @brief 排序
 * @email xueliang2007@qq.com
 * @date  2019.9.12
 */

#include "sort_tools.h"

using namespace std;

void select_sorted(int *a, int n)
{
    for (int i = 0; i < n-1; ++i) {
        int min = i;
        for (int j = i+1; j < n; ++j) {
            if (a[min] > a[j]){
                min = j;
            }
        }
        // swap
        swap_xl(a, min, i);

        printf("cnt:%d\t\t", i);
        array_out(a, n);
    }
}

void select_sorted_improved(int *a, int n)
{
    for (int i = 0; i < n-1; ++i) {
        int min = i;
        int changed = 0;
        for (int j = i+1; j < n; ++j) {
            if (a[min] > a[j]){
                min = j;
                changed = 1;
            }
        }
        // swap
        swap_xl(a, min, i);

        printf("cnt:%d\t\t", i);
        array_out(a, n);

        if (!changed){
            break;
        }
    }
}

int main()
{
    int a[] = {1, 8, 9, 2, 6, 4, 5, 7, 0, 5, 9, 7, 3, 9, 8};
    int n = sizeof(a)/ sizeof(int);
    printf("array size is %d\ninit:\n", n);

    select_sorted_improved(a, n);
}