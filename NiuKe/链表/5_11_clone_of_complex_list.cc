/**
 * @brief 链表问题， 复杂链表的复制
 * @email xueliang2007@qq.com
 * @date  2019.10.13
 */


/**
 * 题目：
 *   输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。
 * */

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>


using std::vector;
using std::stack;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};


void cout_list(RandomListNode *head, bool is_random){
    if (is_random){
        int cnt = 0;
        RandomListNode *node = head;
        while (cnt < 6){
            std::cout << node->label << "\t";
            node = node->random;
            cnt++;
        }
    } else{
        RandomListNode *node = head;
        while (node != nullptr){
            std::cout << node->label << "\t";
            node = node->next;
        }
    }

}


class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == nullptr){
            return nullptr;
        }

        // 对每个节点进行复制
        RandomListNode *node = pHead;
        while (node != nullptr){
            RandomListNode *node_copy = new RandomListNode(node->label);
            node_copy->next = node->next;
            node->next = node_copy;

            node = node->next;
            node = node->next;
        }

        // 复制每个节点的random指针
        node = pHead;
        RandomListNode *node_bk = node->next;
        while (1){
            RandomListNode *prandom = node->random;
            RandomListNode *prandom_bk = prandom->next;
            node_bk->random = prandom_bk;

            node = node->next->next;
            if (node == nullptr){
                break;
            } else{
                node_bk = node->next;
            }
        }

        // 对该链表分流
        node = pHead;
        node_bk = node->next;
        RandomListNode *pHead_new = node->next;  // 新链表的头节点指针
        while (1){
            RandomListNode *pnext = node_bk->next;  // 暂存

            node->next = pnext;

            if (pnext == nullptr){
                node_bk->next = nullptr;
                break;
            } else{
                node_bk->next = pnext->next;
            }

            node = node->next;
            node_bk = node_bk->next;
        }

        std::cout << "------ 原始链表 -----\n";
        std::cout << "next\n";
        cout_list(pHead, false);

        std::cout << "\nrandom\n";
        cout_list(pHead, true);

        std::cout << "\n------ 拷贝链表 -----\n";
        std::cout << "next\n";
        cout_list(pHead_new, false);

        std::cout << "\nrandom\n";
        cout_list(pHead_new, true);

        return pHead_new;
    }
};



int main(){
    std::cout << "复杂链表的复制" << std::endl;

    int size = 3;
    int arr[size] = {1,2,3};
    RandomListNode *node1 = new RandomListNode(arr[0]);
    RandomListNode *node2 = new RandomListNode(arr[1]);
    RandomListNode *node3 = new RandomListNode(arr[2]);
    node1->next = node2;
    node2->next = node3;
    node1->random = node3;
    node2->random = node1;
    node3->random = node2;

    Solution solution;
    solution.Clone(node1);


    return 0;
}