/**
 * @brief 二叉树，判断是否为完全二叉树
 * @email xueliang2007@qq.com
 * @date  2019.9.10
 */


#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"

using namespace std;


bool complete_tree_by_BFS_without_row(BT_Node *root)
{
    if (root == nullptr){
        return true;
    }

    deque<BT_Node*> dq;
    BT_Node *current = root;
    dq.push_back(current);
    bool leaf = false;
    while (!dq.empty()){
        current = dq.front();
        dq.pop_front();
        cout << current->data << "\t\t";

        BT_Node *left = current->left;
        BT_Node *right = current->right;

        if (leaf && (left != nullptr || right != nullptr)){
            cout << "111" << "\n";
            return false;
        }

        if (left == nullptr && right != nullptr){
            cout << "222" << "\n";
            return false;
        }

        if (left != nullptr){
            dq.push_back(left);
        }
        if (right != nullptr){
            dq.push_back(right);
        } else {
            leaf = true; // 之后的节点全部为空, 叶节点
        }
    }

    return true;
}


int main()
{
    BinaryTree *t = (BinaryTree*)malloc(sizeof(BinaryTree));
    BT_Node *a, *b, *c, *d, *e, *f;

    f = MakeTree(t, 'f'-'a', nullptr, nullptr);
    e = MakeTree(t, 'e'-'a', nullptr, nullptr);
    d = MakeTree(t, 'd'-'a', nullptr, nullptr);
    c = MakeTree(t, 'c'-'a', f, nullptr);
//    c = MakeTree(t, 'c'-'a', nullptr, f);
    b = MakeTree(t, 'b'-'a', d, e);
    a = MakeTree(t, 'a'-'a', b, c);


    bool result = complete_tree_by_BFS_without_row(a);
    cout << "\n" << result << "\n";

    return 0;
}