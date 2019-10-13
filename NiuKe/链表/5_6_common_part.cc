/**
 * @brief 链表问题， 打印两个升序单链表公共部分
 * @email xueliang2007@qq.com
 * @date  2019.10.12
 */


/**
 * 题目：
 *   现有两个升序链表，且链表中均无重复元素。请设计一个高效的算法，打印两个链表的公共值部分。
 *   给定两个链表的头指针headA和headB，请返回一个vector，元素为两个链表的公共部分。
 *   请保证返回数组的升序。两个链表的元素个数均小于等于500。保证一定有公共值
 * 测试样例：
 *   {1,2,3,4,5,6,7},{2,4,6,8,10}
 * 返回：
 *   [2.4.6]
 * */

#include <iostream>
#include <vector>


using std::vector;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Common {
public:
    vector<int> findCommonParts(ListNode* header0, ListNode* header1) {
        // write code here
        vector<int> pub_part;
        ListNode *node0 = header0, *node1 = header1;
        if (node0 == nullptr || node1 == nullptr){
            return pub_part;
        }

        while (node0 != nullptr && node1 != nullptr){
            if (node0->val == node1->val){
                pub_part.push_back(node0->val);
                node0 = node0->next;
                node1 = node1->next;
            } else if (node0->val < node1->val){
                node0 = node0->next;
            } else{
                node1 = node1->next;
            }
        }

        return pub_part;
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
};
int main(){
    std::cout << "根据指定元素分化单链表" << std::endl;

    vector<int> vec1{1,3,5,7,9};
    vector<int> vec2{2,4,5,6,8};

    Common common;
    ListNode *lst1 = common.construce_list(vec1);
    ListNode *lst2 = common.construce_list(vec2);
    vector<int> res = common.findCommonParts(lst1, lst2);
    for (auto r:res){
        std::cout << r << "\t";
    }

    return 0;
}