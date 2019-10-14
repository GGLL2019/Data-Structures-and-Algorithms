/**
 * @brief 排序, 基数排序
 * @email xueliang2007@qq.com
 * @date  2019.9.12
 */

#include "sort_tools.h"
#include <deque>

using namespace std;

class RadixSort {
public:

    // 计算num为第位数
    int get_pos(int num,int n){
        int pos=0;
        for(int i=0;i<=n;i++){
            pos=num%10;
            num=num/10;
        }
        return pos;
    }

    // 计算num为几位数
    int get_e_cnt(int num){
        int i = 1;
        while(num/10){
            num /= 10;
            i++;
        }
        return i;
    }

    int *radixSort(int* arr, int n) {
        if (arr == nullptr){
            return nullptr;
        }

        int *res = new int[n];
        vector<deque<int>> di_container(10);
        int max_val = -1e6;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > max_val)
                max_val = arr[i];
            res[i] = arr[i];
        }

        int digitals = get_e_cnt(max_val);
        for (int iter = 0; iter < digitals; iter++) {  // 第iter次迭代，对第iter位进行排序
            for (int i = 0; i < n; i++) {
                int class_id = get_pos(res[i], iter);
                di_container[class_id].push_back(res[i]);
            }
            for (int i = 0, j = 0; i < 10; i++) {
                while (!di_container[i].empty()){
                    int front = di_container[i].front();
                    di_container[i].pop_front();
                    res[j] = front;
                    j++;
                }
            }

            for (int i = 0; i < n; ++i) {
                std::cout << res[i] << "\t";
            }
            std::cout << std::endl;
        }

        return res;
    }
};



int main()
{
    int a[] = {54,35,48,36,27,12,44,44,8,14,26,17,28};
    int n = sizeof(a) / sizeof(int);
    printf("array size is %d\ninit:\n", n);

    RadixSort radixSort;
    int *res = radixSort.radixSort(a, n);
    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << "\t";
    }
    std::cout << std::endl;

    return 0;
}