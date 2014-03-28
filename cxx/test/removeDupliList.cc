#include	<iostream>
#include	<map>
#include    <string>
#include    <unordered_set>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode* curr=head, *nh=NULL, *ne=NULL;
    map<int, ListNode*> lu;
    unordered_set<int> shown;
    while(curr) {
        if (lu.find(curr->val) == lu.end()){
            if (shown.find(curr->val) == shown.end())
                lu[curr->val] = curr;
        }else {
            lu.erase(curr->val);
            shown.emplace(curr->val);
        }
        curr = curr->next;
    }
    for( map<int, ListNode*>::iterator it=lu.begin(); it!=lu.end(); ++it) {
        if (!nh)
            nh=ne=it->second;
        else {
            ne->next=it->second;
            ne=ne->next;
        }
    }
    if (ne)
        ne->next=NULL;
    return nh;
}
void display(ListNode* h)
{
    cout << "[";
    while(h) {
        cout << h->val<< " ";
        h = h->next;
    }
    cout << "]" << endl;
}
int main()
{
    ListNode h(1);
    ListNode n1(1);
    h.next=&n1;
    display(&h);
    ListNode* nh=deleteDuplicates(&h);
    display(nh);
    return 0;
}
