#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
RandomListNode *copyRandomList(RandomListNode *head) {
    // IMPORTANT: Please reset any member data you declared, as
    //         // the same Solution instance will be reused for each test case.
    RandomListNode* curr =head, *tmp, *new_head=NULL, *new_end;
    while(curr) {
        tmp = new RandomListNode(curr->label);
        tmp->next = curr->next;
        curr->next = tmp;
        curr = tmp->next;
    }

    curr=head;
    while(curr) {
        tmp = curr->next;
        if (curr == head) {
            new_end = new_head = tmp;
        } else  {
            new_end->next=tmp;
            new_end = tmp;
        }
        if (!curr->random)
            tmp->random = NULL;
        else
            tmp->random = curr->random->next;
        curr->next = tmp->next;
        new_end->next = NULL;
        curr = curr->next;
    }
    return new_head;
}
RandomListNode* NN(int v)
{
    return new RandomListNode(v);
}
void N(RandomListNode* l, RandomListNode* n)
{
    l->next=n;
}
void R(RandomListNode* l, RandomListNode* n)
{
    l->random=n;
}
void display(RandomListNode* h)
{
    while(h) {
        cout << h->val << " : " << h->random->val << endl;
    }
    cout << "************************"<<endl;
}

void test1()
{
    RandomListNode* h=NN(10);
    RandomListNode* n1=NN(11);
    RandomListNode* n2=NN(12);
    RandomListNode* n3=NN(13);
    RandomListNode* n4=NN(14);
    RandomListNode* n5=NN(15);
    RandomListNode* n6=NN(16);
    RandomListNode* n7=NN(17);
    RandomListNode* n8=NN(18);
    RandomListNode* n9=NN(19);
    N(h,n1);
    N(n1,n2);
    N(n2,n3);
    N(n3,n4);
    N(n4,n5);
    N(n5,n6);
    N(n6,n7);
    N(n7,n8);
    N(n8,n9);
    N(h,n1);
    N(n1,n2);
    N(n2,n3);
    N(n3,n4);
    N(n4,n5);
    N(n5,n6);
    N(n6,n7);
    N(n7,n8);
    N(n8,n9);
}

int main()
{
    
    return 0;
}
