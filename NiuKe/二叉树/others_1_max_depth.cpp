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


int get_height(BT_Node* root)
{
    if (root == nullptr)
        return 0;

    int lh = get_height(root->left);
    int rh = get_height(root->right);
    int h = lh > rh ? lh : rh;
    return h+1;
}

int main()
{
    BinaryTree *t = (BinaryTree*)malloc(sizeof(BinaryTree));
    BT_Node *a, *b, *c, *d, *e, *f;

//    f = MakeTree(t, 5, nullptr, nullptr);
//    e = MakeTree(t, 3, nullptr, nullptr);
//    d = MakeTree(t, 1, nullptr, nullptr);
//    c = MakeTree(t, 6, f, nullptr);
//    b = MakeTree(t, 2, d, e);
//    a = MakeTree(t, 4, b, c);

    f = MakeTree(t, 2, nullptr, nullptr);
    e = MakeTree(t, 3, nullptr, nullptr);
    d = MakeTree(t, 1, nullptr, nullptr);
    c = MakeTree(t, 6, f, nullptr);
    b = MakeTree(t, 5, d, e);
    a = MakeTree(t, 4, b, c);

    int h = get_height(a);
    cout << h << endl;

    return 0;
}

