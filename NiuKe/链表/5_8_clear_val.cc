/**
 * @brief 链表问题， 删除链表节点
 * @email xueliang2007@qq.com
 * @date  2019.10.12
 */


/**
 * 题目：
 *   现在有一个单链表。链表中每个节点保存一个整数，再给定一个值val，把所有等于val的节点删掉。
 *   给定一个单链表的头结点head，同时给定一个值val，请返回清除后的链表的头结点，
 *   保证链表中有不等于该值的其它值。请保证其他元素的相对顺序。
 * 测试样例：
 *   {1,2,3,4,3,2,1},2
 * 输出：
 *   {1,3,4,3,1}
 * */

#include <iostream>
#include <vector>
#include <deque>


using std::vector;
using std::deque;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class ClearValue {
public:
    ListNode* clear(ListNode* header, int val) {
        // write code here
        if (header == nullptr)
            return nullptr;

        ListNode* node = header;
        while (node != nullptr){
            ListNode *next = node->next;
            while (next != nullptr && next->val == val){
                next = next->next;
            }

            if (next == nullptr){
                node->next = nullptr;
                break;
            }

            node->next = next;
            node = node->next;
        }

        if (header->val == val)
            return header->next;
        else
            return header;
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

    void cout_list(ListNode *head){
        ListNode *node = head;
        while (node != nullptr){
            std::cout << node->val << "\t";
            node = node->next;
        }
    }
};


int main(){
    std::cout << "删除链表节点" << std::endl;

    int val = 3;
    vector<int> vec1{1,3,5,7,9,11,3,15,17,3};

    ClearValue clear_value;
    ListNode *lst1 = clear_value.construce_list(vec1);
    ListNode *res = clear_value.clear(lst1, val);
    clear_value.cout_list(res);

    return 0;
}