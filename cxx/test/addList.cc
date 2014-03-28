#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* pl1=l1, *pl2=l2, *tmp, *new_head=pl1, *new_end=NULL;
    if(!l1) return l2;
    if(!l2) return l1;
    int tmpv=0;
    bool incnext=false;
    new_head=pl1;
    while(pl1&&pl2){
        tmpv=pl1->val+pl2->val+(incnext?1:0);
        incnext=tmpv>9?true:false;
        pl1->val = tmpv%10;
        new_end = pl1;
        pl1=pl1->next;
        pl2=pl2->next;
    }
    if (pl1) {
        while(pl1) {
            tmpv=pl1->val+(incnext?1:0);
            incnext=tmpv>9?true:false;
            pl1->val = tmpv%10;
            if (pl1) new_end=pl1;
            pl1=pl1->next;
        }
    }
    if (pl2) {
        new_end->next=pl2;
        new_end=pl2;
        while(pl2) {
            tmpv=pl2->val+(incnext?1:0);
            incnext=tmpv>9?true:false;
            pl2->val=tmpv%10;
            if (pl2) new_end=pl2;
            pl2=pl2->next;
        }
    }
    if (incnext) {
        tmp = new ListNode(1);
        new_end->next=tmp;
        new_end=tmp;
    }
    if (new_end)
        new_end->next=NULL;
    return new_head;
}
void display(ListNode* h)
{
    while(h) {
        cout << h->val << " ";
        h=h->next;
    }
    cout << endl;
}
int main()
{
    ListNode n1(1);
    n1.next=new ListNode(8);
    ListNode n2(0);
    ListNode* r = addTwoNumbers(&n1, &n2);
    if (r) {
        display(r);
    } else 
        cout << "NULL returned" << endl;
    return 0;
}
