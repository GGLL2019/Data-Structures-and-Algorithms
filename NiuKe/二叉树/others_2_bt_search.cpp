//
// Created by snow on 19-9-8.
//

#include <algorithm>
#include <iostream>
#include <math.h>
#include <map>
#include <deque>
#include <stack>
#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"

using namespace std;

void in_order(BT_Node* root, vector<int> &vec_datas)
{
    if (root == nullptr)
        return;
    in_order(root->left, vec_datas);
    vec_datas.push_back(root->data);
    in_order(root->right, vec_datas);
}


bool check_bst1(BT_Node* root)
{
    vector<int> vec_datas;
    in_order(root, vec_datas);
    cout_vector(vec_datas);
    for (int i = 0; i < vec_datas.size()-1; ++i) {
        if (vec_datas[i] > vec_datas[i+1]){
            cout << "be not search tree\n";
            return false;
        }
    }
    return true;
}

bool check_bst2(BT_Node* root)
{
    if (root == nullptr)
        return false;

    stack<BT_Node*> stk;
    BT_Node* current = root;
    BT_Node* last;
    bool init_flag = true;
    while (!stk.empty() || current!= nullptr){
        if (current != nullptr){
            stk.push(current);
            current = current->left;
        } else{
            BT_Node* node = stk.top();
            stk.pop();
            cout << node->data << endl;
            if (init_flag){
                last = node;
                init_flag = false;
            } else{
                if (last->data > node->data){
                    cout << "be not search tree" << endl;
                    return false;
                }
                last = node;
            }
            current = node->right;
        }
    }
    cout << endl;
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

    check_bst1(a);
    check_bst2(a);


    return 0;
}

