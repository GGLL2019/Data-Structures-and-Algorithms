/**
 * @brief 链表问题， 检查链表是否为回文
 * @email xueliang2007@qq.com
 * @date  2019.10.12
 */


/**
 * 题目：
 *   请编写一个函数，检查链表是否为回文。给定一个链表ListNode* pHead，
 *   请返回一个bool，代表链表是否为回文。
 * 测试样例1：
 *   {1,2,3,2,1}
 * 返回：
 *   true
 * 测试样例2：
 *   {1,2,3,2,3}
 * 返回：
 *   false
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


class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        if (pHead == nullptr){
            return false;
        }

        ListNode *pfast = pHead;
        ListNode *pslow = pHead;
        stack<int> stk;
        while (pfast != nullptr && pfast->next != nullptr){
            stk.push(pslow->val);

            pslow = pslow->next; // 更新慢指针, 一步
            pfast = pfast->next;  pfast = pfast->next; // 更新快指针， 两步
        }

        bool bresult = true;
        if (pfast == nullptr){
            // 总节点数为偶数
            // 可以开始比较
            while (pslow != nullptr){
                int top = stk.top();
                stk.pop();
                if (top != pslow->val){
                    bresult = false;
                    break;
                }
                pslow = pslow->next;
            }

        } else if(pfast->next == nullptr){
            // 总节点数为奇数
            // 可以开始比较
            pslow = pslow->next;
            while (pslow != nullptr){
                int top = stk.top();
                stk.pop();
                if (top != pslow->val){
                    bresult = false;
                    break;
                }
                pslow = pslow->next;
            }
        } else{
            std::cout << "error\n";
            assert(false);
        }

        return bresult;
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
    std::cout << "检查链表是否为回文" << std::endl;

    vector<int> vec1{1,3,5,3,1};

    Palindrome palindrome;
    ListNode *lst1 = palindrome.construce_list(vec1);
    palindrome.cout_list(lst1);

    bool res = palindrome.isPalindrome(lst1);
    std::cout << std::endl << res << std::endl;

    return 0;
}