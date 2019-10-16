/**
 * @brief 排序
 * @email xueliang2007@qq.com
 * @date  2019.9.12
 */

#include "sort_tools.h"

using namespace std;

void shell_sort(int *a, int n)
{
    for (int gap = n; gap > 1; ) {
        gap = gap/3 + 1;
        printf("gap:%d|\t", gap);
        for (int i = gap; i < n; ++i) {
            for (int j = i-gap; j >= 0; j-=gap) {
                if (a[j] > a[j+gap])
                    swap_xl(a, j, j+gap);
            }
        }
        array_out(a, n);
    }
}



int main()
{
    int a[] = {1, 8, 9, 2, 6, 4, 5, 7, 0, 5, 9, 7, 3, 9, 5, 8, 4, 3, 1, 0};
    int n = sizeof(a)/ sizeof(int);
    printf("array size is %d\ninit:\n", n);

    shell_sort(a, n);
}