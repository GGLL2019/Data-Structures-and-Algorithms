/**
 * @brief 二叉树问题，广度优先遍历和深度优先遍历
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */

#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"

using namespace std;

void BFS_without_row_num(BT_Node *root)
{
    deque<BT_Node*> dq;
    BT_Node *current = root;
    dq.push_back(current);
    while (!dq.empty()){
        current = dq.front();
        dq.pop_front();
        cout << current->data << "\t\t";

        if (current->left != nullptr){
            dq.push_back(current->left);
        }
        if (current->right != nullptr){
            dq.push_back(current->right);
        }
    }
    cout << endl << endl;
}

vector<vector<int>> BFS_with_row_num(BT_Node *root)
{
    vector<int> vec_bt;
    vector<vector<int>> vec_bts;
    deque<BT_Node*> dq;
    BT_Node *current = root;
    BT_Node *last, *nlast;
    last = current;

    dq.push_back(current);
    while (!dq.empty()){
        current = dq.front();
        dq.pop_front();

        if (current->left != nullptr){
            dq.push_back(current->left);
            nlast = current->left;
        }
        if (current->right != nullptr){
            dq.push_back(current->right);
            nlast = current->right;
        }
        vec_bt.push_back(current->data);

        if (last == current){
            last = nlast;

            vec_bts.push_back(vec_bt);
            vec_bt.clear();
        }
    }

    return vec_bts;
}

vector<vector<int>> BFS_with_row_num_zigzag(BT_Node *root)
{
    vector<vector<int>> vec_bts = BFS_with_row_num(root);

    for (int i = 0; i < vec_bts.size(); ++i) {
        if (i%2){
            reverse(vec_bts[i].begin(), vec_bts[i].end());
        }
    }

    return vec_bts;
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

    // 广度优先遍历,不用区分行
    BFS_without_row_num(a);

    vector<vector<int>> vec_bts = BFS_with_row_num(a);
    for (auto row:vec_bts) {
        cout_vector(row);
    }
    cout << endl;

    vector<vector<int>> vec_bts_zigzag = BFS_with_row_num_zigzag(a);
    for (auto vv:vec_bts_zigzag) {
        cout_vector(vv);
    }
    cout << endl;

    return 0;
}

