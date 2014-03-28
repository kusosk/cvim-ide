#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>
#include    <cassert>
#include    <unordered_map>

using namespace std;

template <typename T>
struct ListNode {
    T v;
    ListNode* next;
    ListNode() : v{}, next(NULL) {};
    ListNode(const T& v_) : v(v_), next(NULL) {};
    ListNode(const T& v_, ListNode<T> *prev) : v(v_), next(NULL) {
        if (prev) prev->next = this;
    };
};

typedef ListNode<int> LNI;
void printList(LNI* h)
{
    while(h){
        cout << h->v << " ";
        h = h->next;
    }
    cout << endl;
}

LNI* genList(int s, int e)
{
    if (s >= e) return NULL;
    LNI* h = new ListNode<int>(s);
    LNI* p = h, *n;
    while(s < e) {
        n=new ListNode<int>(++s, p);
        p=n;
    }
    return h;
}

void cleanup(LNI* h)
{
    LNI* c=h, *n;
    while(c) {
        n = c->next;
        delete c;
        c = n;
    }
}

void odd_even_reorder(LNI* h)
{
    if (!h) return;
    LNI* ob=h, *oe=NULL, *eb=h->next, *ee=NULL, *t1=h, *t2;
    while(t1) {
        if (oe) oe->next=t1;
        oe=t1;
        t2 = t1->next;
        if (!t2)
            break;
        if (ee) ee->next=t2;
        ee=t2;
        t1=t2->next;
        oe->next=ee->next=NULL;
    }
    if (!oe) return;
    oe->next=eb;
}

void even_odd_reorder(LNI* h)
{
    if (!h) return;
    LNI* ob=h, *oe=NULL, *eb=h->next, *ee=NULL, *t1=h, *t2;
    //TODO
}

void deleteNode(LNI* n)
{
    if (! n->next) return;
    n->v = n->next->v;
    n->next = n->next->next;
}
LNI *removeNthFromEnd(LNI *head, int n) {
    if (!head || n <= 0) return head;
    LNI* curr=head, *nh=head, *kp=head;
    int i=0;
    while(kp && i<n) {
        kp=kp->next;
        i++;
    }
    if (i<n) return head;
    else if (i==n) {
        nh=head->next;
        head->next=nullptr;
        return nh;
    }
    while(kp->next) {
        kp=kp->next;
        curr= curr->next;
    }
    kp = curr->next;
    curr->next= curr->next->next;
    kp->next = nullptr;
    return nh;
}

LNI* reverse(LNI* h)
{
    LNI* nh=nullptr, *c=h, *t;
    while (c) {
        t = c->next;
        c->next=nh;
        nh = c;
        c = t;
    }
    return nh;
}
double get_median(LNI* h)
{
    double res = 0.0;
    LNI* c=h, *p=h;
    while(p->next) {
        p = p->next;
        if (! p->next)
            return 1.0*(c->v+c->next->v)/2;
        p=p->next;
        c=c->next;
    }
    return c->v;
}

void zip_order(LNI* h)
{
    LNI* c = h, *t;
    while (c && c->next) {
        t = c->next;
        c->next = reverse(t);
        c = c->next;
    }
    return;
}
void zip_order1(LNI* h)
{
    LNI* f = h, *s=h, *t;
    if (!h || !h->next) return;
    while(f && f->next) {
        f = f->next;
        t = f->next;
        if (!t) break;
        f=t;
        s=s->next;
    }
    t = s->next;
    s->next=nullptr;
    
    t = reverse(t);
    s = h;
    while (s && t) {
        f = t->next;
        t->next=s->next;
        s->next=t;
        s=t->next;
        if (!f) break;
        t = f;
    }
    t->next=s;
    return;
}
int main()
{
    LNI* h = genList(1, 10);
    LNI* h0 = genList(1, 9);
    printList(h);
    cout << get_median(h)<<endl;

    //printList(reverse(h));
    zip_order(h);
    printList(h);

    zip_order(h0);
    printList(h0);
    //even_odd_reorder(h);
    //LNI* h2 = removeNthFromEnd(h, 1);
    printList(h);
    cleanup(h);
    LNI* a = nullptr;
    if (!a) cout << a << endl;
    return 0;
}
