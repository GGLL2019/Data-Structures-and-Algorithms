/**
 * @brief 统计完全二叉树节点个数
 * @email xueliang2007@qq.com
 * @date  2019.10.08
 */


/**
 * 题目：
 *   给定一棵完全二叉树的根节点root，返回这棵树的节点个数。如果完全二叉树的节点数为N，
 *   请实现时间复杂度低于O(N)的解法。 给定树的根结点root，请返回树的大小。
 * */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class CountNodes {
public:
    int get_depth_leftest(TreeNode* root, int level){
        if (root == nullptr)
            return 0;
        level += get_depth_leftest(root->left, 1);
        return level;
    }

    int bt_nodes(TreeNode* root, int level, int height){
        if (level == height)
            return 1;
        if (get_depth_leftest(root->right, level+1) == height){
            return (1 << (height-level)) + bt_nodes(root->right, level+1, height);
        }else{
            return (1 << (height-level-1)) + bt_nodes(root->left, level+1, height);
        }
    }

    int count(TreeNode* root) {
        // write code here
        if (root == nullptr)
            return 0;
        return bt_nodes(root, 1, get_depth_leftest(root, 1));
    }
};

