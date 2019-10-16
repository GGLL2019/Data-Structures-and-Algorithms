/**
 * @brief 二叉树，寻找错误节点
 * @email xueliang2007@qq.com
 * @date  2019.9.10
 */


#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"

using namespace std;


void in_order(BT_Node* root, vector<int> &vec)
{
    if (root == nullptr)
        return;

    in_order(root->left, vec);
    vec.push_back(root->data);
    in_order(root->right, vec);
}

int main()
{
    BinaryTree *t = (BinaryTree*)malloc(sizeof(BinaryTree));
    BT_Node *a, *b, *c, *d, *e, *f;

    f = MakeTree(t, 2, nullptr, nullptr);
    e = MakeTree(t, 3, nullptr, nullptr);
    d = MakeTree(t, 1, nullptr, nullptr);
    c = MakeTree(t, 6, f, nullptr);
    b = MakeTree(t, 5, d, e);
    a = MakeTree(t, 4, b, c);

    vector<int> vec_data;
    in_order(a, vec_data);
    cout_vector(vec_data);
    int num[2] = {0};
    int times = 0;
    for (int i = 0; i < vec_data.size()-1; ++i) {
        if (vec_data[i] > vec_data[i+1]){
            if (times == 0){
                num[0] = vec_data[i];
                num[1] = vec_data[i+1];
                times++;
            } else{
                num[1] = vec_data[i+1];
            }
        }
    }
    cout_array(num, 2);


    return 0;
}

