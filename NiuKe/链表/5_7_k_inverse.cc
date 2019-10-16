/**
 * @brief 链表问题， 单链表逆序
 * @email xueliang2007@qq.com
 * @date  2019.10.12
 */


/**
 * 题目：
 *   有一个单链表，请设计一个算法，使得每K个节点之间逆序，如果最后不够K个节点一组，则不调整最后几个节点。
 *   例如链表1->2->3->4->5->6->7->8->null，K=3这个例子。调整后为，3->2->1->6->5->4->7->8->null。
 *   因为K==3，所以每三个节点之间逆序，但其中的7，8不调整，因为只有两个节点不够一组。
 * 输入
 *   给定一个单链表的头指针head,同时给定K值
 * 返回
 *   逆序后的链表的头指针。
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

class KInverse {
public:
    ListNode* inverse(ListNode* header, int k) {
        deque<int> dq;
        ListNode *node = header;

        ListNode *dummy = new ListNode(-1);
        ListNode *node_dummy = dummy;

        int dq_value = 0;
        while (node != nullptr){
            dq.push_back(node->val);
            int dq_size = dq.size();
            if (dq_size == k){
                while (dq.size() != 0){
                    dq_value = dq.back();
                    dq.pop_back();

                    ListNode *temp = new ListNode(dq_value);

                    node_dummy->next = temp;
                    node_dummy = node_dummy->next;
                }
                dq.clear();
            }
            node = node->next;
        }

        while (dq.size() != 0){
            dq_value = dq.front();
            dq.pop_front();

            ListNode *temp = new ListNode(dq_value);
            node_dummy->next = temp;
            node_dummy = node_dummy->next;
        }

        return dummy->next;
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
    std::cout << "单链表子序列逆序" << std::endl;

    int k = 3;
    vector<int> vec1{1,3,5,7,9,11,13,15,17};

    KInverse kinverse;
    ListNode *lst1 = kinverse.construce_list(vec1);
    ListNode *res = kinverse.inverse(lst1, k);
    kinverse.cout_list(res);

    return 0;
}