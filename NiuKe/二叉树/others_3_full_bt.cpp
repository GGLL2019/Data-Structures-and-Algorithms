//
// Created by snow on 19-9-11.
//

#include <iostream>
#include <math.h>
#include <map>
#include <deque>
#include <stack>
#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"

using namespace std;


vector<int> BFS_without_row(BT_Node *root)
{
    vector<int> vec_bts;
    if (root == nullptr){
        return vec_bts;
    }

    deque<BT_Node*> dq;
    BT_Node *current = root;
    dq.push_back(current);
    while (!dq.empty()){
        current = dq.front();
        dq.pop_front();

        if (current->left != nullptr){
            dq.push_back(current->left);
        }
        if (current->right != nullptr){
            dq.push_back(current->right);
        }

        cout << current->data << "\t\t";
    }

    return vec_bts;
}

vector<vector<int>> BFS_with_row(BT_Node *root)
{
    vector<vector<int>> vec_bts;
    if (root == nullptr){
        return vec_bts;
    }
    int nodes = 0;
    vector<int> vec;

    deque<BT_Node*> stk;
    BT_Node *current = root;
    stk.push_back(current);

    BT_Node *last, *nlast;
    last = current;
    while (!stk.empty()){
        current = stk.front();
        stk.pop_front();
        vec.push_back(current->data);

        cout << current->data << "\t\t";

        if (current->left != nullptr){
            stk.push_back(current->left);
            nlast = current->left;
        }
        if (current->right != nullptr){
            stk.push_back(current->right);
            nlast = current->right;
        }

        if (current == last){
            cout << "\n";
            vec_bts.push_back(vec);
            nodes += vec.size();

            vec.clear();
            last = nlast;
        }

    }
    int levels = vec_bts.size();
    int nodes_ideal = pow(2, levels) - 1;
    if (nodes_ideal != nodes){
        cout << "be not full binary tree\n";
    } else{
        cout << "be full binary tree\n";
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


    BFS_without_row(a);
    cout << "\n";
    cout << "\n";
    BFS_with_row(a);
    return 0;
}