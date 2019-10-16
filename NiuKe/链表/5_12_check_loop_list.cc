/**
 * @brief 链表问题， 检查链表是否有环
 * @email xueliang2007@qq.com
 * @date  2019.10.13
 */


/**
 * 题目：
 *   如何判断一个单链表是否有环？有环的话返回进入环的第一个节点的值，无环的话返回-1。如果链表的长度为N，
 *   请做到时间复杂度O(N)，额外空间复杂度O(1)。给定一个单链表的头结点head（注意另一个参数adjust为加密后
 *   的数据调整参数，方便数据设置，与本题求解无关)，请返回所求值。
 * */

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>


using std::vector;
using std::stack;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust) {
        if (head == nullptr || head->next == nullptr){
            return -1;
        }

        ListNode *pslow = head;
        ListNode *pfast = head;

        int res = 0;
        int cnt = 0;
        while (1){
            std::cout << "slow:\t" << pslow->val << "\tfast:\t" << pfast->val << std::endl;
            if (pfast == nullptr || pfast->next == nullptr){
                res = -1;
                break;
            } else if (pslow == pfast && cnt != 0){  // 确保第一次循环时不进入该条件
                std::cout << pslow->val << std::endl;
                res = 1;
                break;
            } else{
                pslow = pslow->next;
                pfast = pfast->next->next;
            }
            cnt++;
        }

        // 计算环的入口
        pfast = head;
        while (1 && res != -1){
            if (pslow == pfast){
                res = pslow->val;
                break;
            } else{
                pslow = pslow->next;
                pfast = pfast->next;
            }
        }
        return res;
    }


    void cout_list(ListNode *head, int size){
        ListNode *node = head;
        while (node != nullptr && size > 0){
            std::cout << node->val << "\t";
            node = node->next;
            size--;
        }
    }
};


int main(){
    std::cout << "复杂链表的复制" << std::endl;

    vector<int> vec1{1,3,5,7,9};
    ListNode *head = new ListNode(vec1[0]);
    ListNode *node1 = new ListNode(vec1[1]);
    ListNode *node2 = new ListNode(vec1[2]);
    ListNode *node3 = new ListNode(vec1[3]);
    ListNode *node4 = new ListNode(vec1[4]);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    int size = vec1.size();


    ChkLoop chkLoop;
    chkLoop.cout_list(head, size);
    int res = chkLoop.chkLoop(head, 1);
    std::cout << "entrance:\t" << res << std::endl;




    return 0;
}