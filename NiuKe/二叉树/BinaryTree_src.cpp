//
// Created by snow on 19-9-8.
//

#include <iostream>
#include <string>
#include "../include/BinaryTree_headers.h"

using namespace std;


void InitBinaryTreeNode(BT_Node *btree, int data, BT_Node *ptr_l, BT_Node *ptr_r)
{
    btree->data = data;
    btree->left = ptr_l;
    btree->right = ptr_r;
}


BT_Node *Creat_BTree(int data, BT_Node* ptr_l, BT_Node *ptr_r)
{
    BT_Node *p;
    p = (BT_Node*)malloc(sizeof(BT_Node));

    if (p == nullptr){
        return nullptr;
    } else{
        p->data = data;
        p->left = ptr_l;
        p->right = ptr_r;
        return p;
    }
}


BT_Node *MakeTree(BinaryTree *bt, int data, BT_Node* ptr_l, BT_Node *ptr_r)
{
    bt->root = (BT_Node*)malloc(sizeof(BT_Node));
    if (bt->root == nullptr){
        return nullptr;
    }

    InitBinaryTreeNode(bt->root, data, ptr_l, ptr_r);

    return bt->root;
}




