/**
 * @brief 链表问题， 链表分化问题
 * @email xueliang2007@qq.com
 * @date  2019.10.12
 */


/**
 * 题目：
 *   对于一个链表，我们需要用一个特定阈值完成对它的分化，使得小于等于这个值的结点移到前面，
 *   大于该值的结点在后面，同时保证两类结点内部的位置关系不变。给定一个链表的头结点head，
 *   同时给定阈值val，请返回一个链表，使小于等于它的结点在前，大于等于它的在后，保证结点值不重复。
 * 测试样例：
 *   {1,4,2,5},3
 * 结果
 *   {1,2,4,5}
 * */


#include <iostream>
#include <vector>


using std::vector;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Divide {
public:
    ListNode* listDivide(ListNode* header, int val) {
        if (header == nullptr)
            return nullptr;

        ListNode *lhead = new ListNode(0),
                 *rhead = new ListNode(0);
        ListNode *lnode = lhead, *rnode = rhead;

        // 将原始链表分为小于等于和大于两段
        ListNode *curr = header;
        while(curr != nullptr) {
            ListNode *node = new ListNode(curr->val);
            if (curr->val <= val){
                node->next = lnode->next;
                lnode->next = node;
                lnode = lnode->next;
            } else {
                node->next = rnode->next;
                rnode->next = node;
                rnode = rnode->next;
            }
            curr = curr->next;
        }

        // 合并两个链表
        merge_list(lnode, rhead->next);
        std::cout << "\n--------resule---------\n";
        cout_list(lhead->next);

        return lhead->next;
    }

    void merge_list(ListNode *pre_lst_tail, ListNode *curr_lst_head)
    {
        if (pre_lst_tail == nullptr){
            return ;
        }
        if (curr_lst_head == nullptr){
            return ;
        }

        pre_lst_tail->next = curr_lst_head;
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
    std::cout << "根据指定元素分化单链表" << std::endl;

    int val = 1134;
    vector<int> lst{1620,1134,861,563,1};

    Divide divide;
    ListNode *head = divide.construce_list(lst);
    divide.cout_list(head);
    divide.listDivide(head, val);

    return 0;
}