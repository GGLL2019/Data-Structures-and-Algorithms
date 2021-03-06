/**
 * @brief 链表问题， 检查两个未知是否有环的单链表是否相交
 * @email xueliang2007@qq.com
 * @date  2019.10.13
 */


/**
 * 题目：
 *   给定两个单链表的头节点head1和head2，如何判断两个链表是否相交？相交的话返回true，不想交的话返回false。
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


class ChkIntersection {
public:
    ListNode *get_entrance_node(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode *pslow = head;
        ListNode *pfast = head;

        int res = 0;
        int cnt = 0;
        while (1){
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
                res = pslow->val;  // 保存入环节点的val
                break;
            } else{
                pslow = pslow->next;
                pfast = pfast->next;
            }
        }

        return res == -1 ? nullptr : pslow;
    }

    bool chkIntersect_without_loop_list(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr || head2 == nullptr){
            return false;
        }

        // 统计两个链表的长度
        int len1 = 0, len2 = 0;
        ListNode *node1 = head1;
        ListNode *node2 = head2;
        while (node1 != nullptr){
            node1 = node1->next;
            len1++;
        }
        while (node2 != nullptr){
            node2 = node2->next;
            len2++;
        }

        // 长链表先走
        bool res = false;
        node1 = head1;
        node2 = head2;
        while (node1 && node2){
            if (len1 > len2){
                // 链表1先走至长度相等
                node1 = node1->next;
                len1--;
            } else if (len1 < len2){
                // 链表2先走至长度相等
                node2 = node2->next;
                len2--;
            } else{
                // 长度相等，同步前进
                if (node1 == node2){
                    res = true;
                    break;
                } else{
                    node1 = node1->next;
                    node2 = node2->next;
                }
            }
        }

        return res;
    }

    bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
        // write code here
        if (head1 == nullptr || head2 == nullptr){
            return false;
        }

        bool res = false;
        // 分别计算两个链表的入环节点
        ListNode *entrance1 = get_entrance_node(head1);
        ListNode *entrance2 = get_entrance_node(head2);
        if (entrance1 == nullptr || entrance2 == nullptr){
            // 两个链表至少一个无环
            res = chkIntersect_without_loop_list(head1, head2);
            return res;
        }else if(entrance1 == entrance2){
            // 两个链表有环，并且在环形之前就已经相交
            res = true;
        } else{
            // 两个链表有环，并且在环形的内部相交
            ListNode *node = entrance2->next;
            while (node != entrance1 && node != entrance2){
                node = node->next;
            }

            /*if (node == entrance1){
                // 在环的内部相交
                res = true;
            } else if (node == entrance2){
                // 链表2在环内转了一圈，仍然同链表1的入口不同，即不相交
                res = false;
            }*/
            res = node == entrance1 ? true : false;  // 同上面等价
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
    vector<int> vec2{0,2,4,6};
    ListNode *head1 = new ListNode(vec1[0]);
    ListNode *node11 = new ListNode(vec1[1]);
    ListNode *node12 = new ListNode(vec1[2]);
    ListNode *node13 = new ListNode(vec1[3]);
    ListNode *node14 = new ListNode(vec1[4]);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node12;

    ListNode *head2 = new ListNode(vec2[0]);
    ListNode *node21 = new ListNode(vec2[1]);
    ListNode *node22 = new ListNode(vec2[2]);
    ListNode *node23 = new ListNode(vec2[3]);
    head2->next = node21;
    node21->next = node22;
    node22->next = node23;
//    node23->next = node21;
    node23->next = node14;

    ChkIntersection chkIntersection;
    chkIntersection.cout_list(head1, vec1.size()+1);
    std::cout << std::endl;
    chkIntersection.cout_list(head2, vec2.size()+1);
    bool res = chkIntersection.chkInter(head1, head2, 1, 2);
    if (!res){
        std::cout << "INSTERSECT:\tNO\n";
    } else{
        std::cout << "INSTERSECT:\tYES\n";
    }

    return 0;
}