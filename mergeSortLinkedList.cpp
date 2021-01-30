#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        ListNode * mid = getMid(head);
        ListNode * left = sortList(head);
        ListNode * right = sortList(mid);
        return merge(left, right);
    }
    
    ListNode*merge(ListNode *list1, ListNode *list2){
        ListNode *temp = new ListNode(0);
        ListNode *remember = temp;
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1)
            temp->next = list1;
        else
            temp->next = list2;
        return remember->next;
    }
    
    ListNode * getMid(ListNode *head){
        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL; //split
        return slow;
    } 
};

int main(){
    ListNode * root = new ListNode(10);
    root->next = new ListNode(1);
    root->next->next = new ListNode(60);
    root->next->next->next = new ListNode(30);
    root->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode * ans = s.sortList(root);
    while(ans){
        cout<<ans->val<< " ";
        ans = ans->next;
    }
}