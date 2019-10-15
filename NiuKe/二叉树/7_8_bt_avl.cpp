/**
 * @brief 判断是否为平衡二叉树
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */

#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"


using namespace std;

int getHeight(BT_Node* head, int level, bool* res)
{
    if (head == nullptr){
        return level;
    }
    int lh = getHeight(head->left, level+1, res);
    if (!res[0]){
        return level;
    }
    int rh = getHeight(head->right, level+1, res);
    if (!res[0]){
        return level;
    }
    if (abs(lh - rh) > 1){
        res[0] = false;
    }
    return max(lh, rh);
}

bool is_balance(BT_Node* head)
{
    bool* res = new bool(1);
    res[0] = true;
    getHeight(head, 1, res);
    return res[0];
}


int main()
{
    BinaryTree *t = (BinaryTree*)malloc(sizeof(BinaryTree));
    BT_Node *a, *b, *c, *d, *e, *f;

    f = MakeTree(t, 'f'-'a', nullptr, nullptr);
    e = MakeTree(t, 'e'-'a', nullptr, nullptr);
    d = MakeTree(t, 'd'-'a', nullptr, nullptr);
    c = MakeTree(t, 'c'-'a', f, nullptr);
    b = MakeTree(t, 'b'-'a', d, e);
    a = MakeTree(t, 'a'-'a', b, c);


    cout << is_balance(a) << endl;

    return 0;
}

