/**
 * @brief 链表问题， 向有序环形链表中插入节点，并依然保持有序
 * @email xueliang2007@qq.com
 * @date  2019.10.12
 */


/**
 * 题目：
 *   有一个整数val，如何在节点值有序的环形链表中插入一个节点值为val的节点，并且保证这个环形单链表依然有序。
 *   给定链表的信息，及元素的值A及对应的nxt指向的元素编号同时给定val，请构造出这个环形链表，并插入该值。
 * 测试样例：
 *   [1,3,4,5,7],[1,2,3,4,0],2
 * 返回：
 *   {1,2,3,4,5,7}
 * */


#include <iostream>
#include <vector>


using std::vector;

class InsertValue {
public:
    struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* insert(vector<int> lst, vector<int> nxt, int val) {
        int i_size = lst.size();
        if (i_size < 1 || i_size != nxt.size()){
            return nullptr;
        }

        ListNode *new_head;
        ListNode *head = construct_loop_list(lst, nxt);
        if (val <= head->val){
            // 新节点应当插入在链表头部并作为新的头节点
            new_head = new ListNode(val);
            new_head->next = head;

            // 把尾节点重新链接到新的头节点
            ListNode *curr = head;
            while (curr->next != head){
                curr = curr->next;
            }
            curr->next = new_head;
        } else{
            // 新节点应当作为中间节点插入在链表中间
            bool is_break = true;
            ListNode *pre = head, *curr = head->next;

            while (curr != head){
                if (val <= curr->val){
                    ListNode *node = new ListNode(val);
                    node->next = curr;
                    pre->next = node;
                    is_break = false;
                    break;
                } else{
                    pre = curr;
                    curr = curr->next;
                }
            }

            // 新节点作为尾节点插入
            if (is_break){
                ListNode *node = new ListNode(val);
                pre->next = node;
                node->next = head;
            }
            new_head = head;
        }

        // 把尾节点同头节点断开
        ListNode *curr = new_head;
        while (curr->next != new_head){
            curr = curr->next;
        }
        curr->next = nullptr;

        return new_head;
    }

    ListNode *construct_loop_list(const vector<int> &lst, const vector<int> &nxt){
        ListNode *head, *head_temp;
        int i_size = lst.size();
        for (int i = 0; i < i_size; ++i) {
            ListNode *node = new ListNode(lst[i]);
            if (i == 0){
                head_temp = node;
            } else{
                head_temp->next = node;
                head_temp = node;
            }

            if (nxt[i] == 1){
                head = node;
            } else if (nxt[i] == 0){
                head_temp->next = head;
            }
        }
        return head;
    }

    void cout_list(ListNode *head, int i_size){
        if (head == nullptr || i_size == 0){
            return;
        }

        ListNode *curr = head;
        int i = 0;
        while (curr != nullptr && i < i_size*2){
            std::cout << curr->val << "\t";
            i++;
            curr = curr->next;
        }
    }
};

int main(){
    std::cout << "向有序环形链表中插入节点，并依然保持有序" << std::endl;

    int val = 8;
    vector<int> lst{1, 3, 4, 5, 7};
    vector<int> nxt{1, 2, 3, 4, 0};

    InsertValue iv;
    iv.insert(lst, nxt, val);


    return 0;
}