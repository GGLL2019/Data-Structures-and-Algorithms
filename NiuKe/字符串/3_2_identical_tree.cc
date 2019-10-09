/**
 * @brief 利用字符串，来检测二叉树T1中是否含有拓扑结构相同的子树T2.
 *   将两个二叉树每个节点相互匹配时间复杂度较高，可以通过前序遍历算法，将二叉树转化为字符串，
 *   然后通过KMP算法判断字符串s2是否是字符串是s1的子串。
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   对于两棵彼此独立的二叉树A和B，请编写一个高效算法，检查A中是否存在一棵子树与B树的拓扑结构完全相同。
 *   给定两棵二叉树的头结点A和B，请返回一个bool值，代表A中是否存在一棵同构于B的子树。
 * */

#include <iostream>
#include <vector>

using std::vector;
using std::string;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class IdenticalTree {
public:
    bool chkIdentical(TreeNode* A, TreeNode* B) {
        string sa, sb;
        tree_to_string(A, sa);
        tree_to_string(B, sb);

        if (sa.find(sb) != std::string::npos)
            return true;
        else
            return false;
    }

    void tree_to_string(TreeNode* root, string &str){
        if (root == nullptr){
            str += "#!";
            return ;
        }

        str += std::to_string(root->val) + '!';
        tree_to_string(root->left, str);
        tree_to_string(root->right, str);
    }
};


int main(){
    TreeNode *h1 = new TreeNode(1);
    TreeNode *h2 = new TreeNode(2);
    TreeNode *h3 = new TreeNode(3);
    TreeNode *h4 = new TreeNode(4);
    TreeNode *h5 = new TreeNode(5);
    TreeNode *h6 = new TreeNode(6);
    TreeNode *h7 = new TreeNode(7);
    TreeNode *h8 = new TreeNode(8);
    h1->left  = h2;
    h1->right = h3;
    h2->left  = h4;
    h2->right = h5;
    h3->left  = h6;
    h3->right = h7;
    h4->left  = h8;


    TreeNode *r2 = new TreeNode(1);
    TreeNode *r4 = new TreeNode(4);
    TreeNode *r5 = new TreeNode(5);
    r2->left  = r4;
    r2->right = r5;


    IdenticalTree it;

    // 二叉树1
    string sa;
    it.tree_to_string(h1, sa);
    std::cout << sa << std::endl;

    // 二叉树2
    string sb;
    it.tree_to_string(r2, sb);
    std::cout << sb << std::endl;

    // 检查拓扑结构是否相同
    bool b_res = it.chkIdentical(h1, r2);
    std::cout << "拓扑结构是否相同：\t" << b_res << std::endl;

    return 0;
}