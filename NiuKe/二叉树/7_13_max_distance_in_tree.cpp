/**
 * @brief 二叉树，树中节点的最大距离
 * @email xueliang2007@qq.com
 * @date  2019.9.10
 */


#include "../include/tools.h"
#include "../include/BinaryTree_headers.h"

using namespace std;

struct bt_info{
    int max_dist;
    int height;
    bt_info(int max_distance, int height):max_dist(max_distance), height(height){

    }
};

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

int get_height(BT_Node* root)
{
    if (root == nullptr)
        return 0;
    int lh = get_height(root->left);
    int rh = get_height(root->right);
    int h = lh > rh ? lh:rh;
    return h+1;
}


bt_info process(BT_Node* head)
{
    if (head == nullptr)
        return bt_info(0, 0);

    bt_info l_data = process(head->left);
    bt_info r_data = process(head->right);
    int height = max(l_data.height, r_data.height) + 1;
    int max_dist = max(l_data.height + r_data.height + 1, max(l_data.max_dist, r_data.max_dist));

    return bt_info(max_dist, height);
}

int get_max_distance(BT_Node* head)
{
    return process(head).max_dist;
}



class LongestDistance {
public:
    struct TreeNode {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
        TreeNode(int x) :
                val(x), left(NULL), right(NULL) {
        }
    };

    struct bt_info{
        int max_dist;
        int height;
        bt_info(int max_dist_, int height_):max_dist(max_dist_), height(height_){}
    };

    bt_info process(TreeNode* root){
        if (root == nullptr)
            return bt_info(0, 0);

        bt_info l_data = process(root->left);
        bt_info r_data = process(root->right);

        int height = std::max(l_data.height, r_data.height) + 1;
        int max_dist = std::max(l_data.height, r_data.height + 1, std::max(l_data.max_dist, r_data.max_dist));
        return bt_info(max_dist, height);
    }

    int findLongest(TreeNode* root) {
        // write code here
        return process(root).max_dist;
    }
};


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

    vector<vector<int>> vec_bts = BFS_with_row(a);

    int max_dist = get_max_distance(a);
    cout << max_dist << endl;

    return 0;
}

