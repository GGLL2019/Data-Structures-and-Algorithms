/**
 * @brief 二叉树，遍历（递归+循环）
 * @email xueliang2007@qq.com
 * @date  2019.9.10
 */


#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"


using namespace std;

void pre_order(BT_Node *node)
{
    if (node!= nullptr){
        std::cout << node->data << "\t\t";
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(BT_Node *node)
{
    if (node!= nullptr){
        in_order(node->left);
        std::cout << node->data << "\t\t";
        in_order(node->right);
    }
}


void post_order(BT_Node *node)
{
    if (node!= nullptr){
        post_order(node->left);
        post_order(node->right);
        std::cout << node->data << "\t\t";
    }
}

void pre_order_loop(BT_Node *tree)
{
    if (tree == nullptr)
        return;
    BT_Node *t = tree;
    stack<BT_Node*> stk;
    stk.push(t);
    while (!stk.empty()){
        t = stk.top();
        stk.pop();
        cout << t->data << "\t\t";

        if (t->right != nullptr){
            stk.push(t->right);
        }
        if (t->left != nullptr){
            stk.push(t->left);
        }
    }
    cout << endl;
}


void in_order_loop(BT_Node *tree)
{
    if (tree == nullptr)
        return;
    BT_Node *current = tree;
    stack<BT_Node*> stk;
    while (!stk.empty() || current != nullptr){
        if (current != nullptr){
            stk.push(current);
            current = current->left;
        } else {
            BT_Node *node = stk.top();
            stk.pop();
            cout << node->data << "\t\t";
            current = node->right;
        }
    }
    cout << endl;
}


void post_order_loop1(BT_Node *tree)
{
    if (tree == nullptr)
        return;

    stack<BT_Node*> stk1, stk2;
    stk1.push(tree);

    BT_Node *current;
    while (!stk1.empty()){
        current = stk1.top();
        stk1.pop();
        if (current != nullptr){
            stk2.push(current);

            stk1.push(current->left);
            stk1.push(current->right);
        }
    }

    while (!stk2.empty()){
        current = stk2.top();
        stk2.pop();
        cout << current->data << "\t\t";
    }
    cout << endl;
}

void post_order_loop2(BT_Node *tree)
{
    if (tree == nullptr)
        return;

    stack<BT_Node*> stk;
    stk.push(tree);

    BT_Node *current = nullptr;
    BT_Node *head = tree;

    while (!stk.empty()){
        current = stk.top();
        if (current->left != nullptr && head != current->left && head != current->right){
            stk.push(current->left);
        } else if(current->right != nullptr && head != current->right){
            stk.push(current->right);
        } else{
            stk.pop();
            cout << current->data << "\t\t";
            head = current;
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

    pre_order(a);
    cout << endl;
    pre_order_loop(a);

    in_order(a);
    cout << endl;
    in_order_loop(a);

    post_order(a);
    cout << endl;

    post_order_loop1(a);

    post_order_loop2(a);

    return 0;
}