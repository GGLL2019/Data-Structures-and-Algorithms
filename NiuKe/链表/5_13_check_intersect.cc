/**
 * @brief 链表问题， 检查两个单链表是否相交
 * @email xueliang2007@qq.com
 * @date  2019.10.13
 */


/**
 * 题目：
 *   现在有两个无环单链表，若两个链表的长度分别为m和n，请设计一个时间复杂度为O(n + m)，额外空间复杂度为O(1)的算法，
 *   判断这两个链表是否相交。 给定两个链表的头结点headA和headB，请返回一个bool值，代表这两个链表是否相交。
 *   保证两个链表长度小于等于500。
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


class CheckIntersect {
public:
    bool chkIntersect(ListNode* head1, ListNode* head2) {
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

    ListNode *construce_list(const vector<int> &vec){
        if (vec.empty()){
            return nullptr;
        } else{
            ListNode dummy(0);
            ListNode *ptr_dummy = &dummy;
            for (auto &v:vec){
                ListNode *node = new ListNode(v);
                ptr_dummy->next = node;
                ptr_dummy = ptr_dummy->next;
            }
            return dummy.next;
        }
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
    vector<int> vec2{1,3,5,7,9,11,13};


    CheckIntersect checkIntersect;
    ListNode *head1 = checkIntersect.construce_list(vec1);
    ListNode *head2 = checkIntersect.construce_list(vec2);
    bool res = checkIntersect.chkIntersect(head1, head2);
    if (!res){
        std::cout << "INSTERSECT:\tNO\n";
    } else{
        std::cout << "INSTERSECT:\tYES\n";
    }

    return 0;
}