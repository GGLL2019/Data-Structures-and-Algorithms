/**
 * @brief 二叉树，序列化
 * @email xueliang2007@qq.com
 * @date  2019.9.10
 */


#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"

using namespace std;


string serial_by_pre_order(BT_Node *head)
{
    if (head == nullptr){
        return "#!";
    }

    string res = to_string(head->data) + "!";
    res += serial_by_pre_order(head->left);
    res += serial_by_pre_order(head->right);
    return res;
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

//    int cc;
//    int i=0;
//    int n;
//    int nums[100];
//    while (cin >> n){
//        cc = getchar();
//        if (cc != '\n')
//            nums[i++] = n;
////        else
////            break;
//    }

    string s =  serial_by_pre_order(a);
    cout << s <<endl;

    vector<string> str_decom = str_decompose(s);



    return 0;
}

