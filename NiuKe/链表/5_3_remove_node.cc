/**
 * @brief 链表问题， 从单向链表中删除节点
 * @email xueliang2007@qq.com
 * @date  2019.10.12
 */


/**
 * 题目：
 *   实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。给定带删除的头节点和要删除的数字，请执行删除操作，
 *   返回删除后的头结点。链表中没有重复数字
 * */


#include <iostream>
#include <vector>


using std::vector;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Remove {
public:
    ListNode* removeNode(ListNode* pHead, int delVal) {
        // write code here
        if (pHead == nullptr){
            return nullptr;
        }

        // 需要删除的节点是头节点
        if (pHead->val == delVal){
            ListNode *node = pHead->next;
            pHead->next = nullptr;  // 防止野指针
            return node;
        }

        // 计算需要删除的节点的位置
        ListNode *node = pHead;
        while (node->next != nullptr && node->next->val != delVal){
            node = node->next;
        }
        if (node->next == nullptr){
            // 判断尾节点是否是目标节点
            if (node->val == delVal){
                node = nullptr;
            }
            return pHead;
        } else{
            // 需要删除的是中间节点
            ListNode *temp_node = node->next->next;
            node->next->next = nullptr;
            node->next = temp_node;
            return pHead;
        }
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
    std::cout << "从单链表中删除指定元素" << std::endl;

    int del_val = 5;
    vector<int> lst{1, 3, 4, 5, 6, 7};


    Remove rv;
    ListNode *head = rv.construce_list(lst);
    rv.cout_list(head);

    std::cout << "\n-----------------\n";

    head = rv.removeNode(head, del_val);
    rv.cout_list(head);

    return 0;
}