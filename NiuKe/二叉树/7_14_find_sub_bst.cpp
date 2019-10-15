/**
 * @brief 二叉树，最大二叉搜索子树
 * @email xueliang2007@qq.com
 * @date  2019.9.10
 */


#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"

using namespace std;


struct bst_info{
    BT_Node* max_bst_h;
    int max_bst_size;
    int min;
    int max;
    bst_info(BT_Node* max_bst_node, int max_bst_size, int min, int max)
            :max_bst_h(max_bst_node),max_bst_size(max_bst_size), min(min), max(max){
        ;
    }
};

void in_order(BT_Node *node)
{
    if (node!= nullptr){
        in_order(node->left);
        std::cout << node->data << "\t\t";
        in_order(node->right);
    }
}

bst_info process(BT_Node* x_node)
{
    if (x_node == nullptr)
        return bst_info(x_node, 0, INT_MAX, INT_MIN);

    int data = x_node->data;
    cout << data << endl;

    // 左子树的全部信息
    bst_info l_info = process(x_node->left);
    bst_info r_info = process(x_node->right);

    // 信息整合
    int min_data = min(x_node->data, min(l_info.min, r_info.min));
    int max_data = max(x_node->data, max(l_info.max, r_info.max));

    int max_bst_size = max(l_info.max_bst_size, r_info.max_bst_size);
    BT_Node* max_bst_node = l_info.max_bst_size > r_info.max_bst_size ? l_info.max_bst_h : r_info.max_bst_h;

    // 第三种情况
    if (l_info.max_bst_h == x_node->left && r_info.max_bst_h == x_node->right && x_node->data > l_info.max && x_node->data < r_info.min){
        max_bst_size = l_info.max_bst_size + r_info.max_bst_size + 1;
        max_bst_node = x_node;
    }

    return bst_info(max_bst_node, max_bst_size, min_data, max_data);

}

BT_Node* get_max_bst(BT_Node* head){
    return process(head).max_bst_h;
}

int main()
{
    BinaryTree *t = (BinaryTree*)malloc(sizeof(BinaryTree));
    BT_Node *a, *b, *c, *d, *e, *f;

    f = MakeTree(t, 5, nullptr, nullptr);
    e = MakeTree(t, 4, nullptr, nullptr);
    d = MakeTree(t, 1, nullptr, nullptr);
    c = MakeTree(t, 2, f, nullptr);
    b = MakeTree(t, 3, d, e);
    a = MakeTree(t, 0, b, c);
    in_order(a);
    cout << endl;

    BT_Node *sub_bst_root = get_max_bst(a);
    in_order(sub_bst_root);
    cout << endl;

    return 0;
}

