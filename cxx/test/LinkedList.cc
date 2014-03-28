#include	<iostream>
#include	<string>
#include	<bitset>
#include	<climits>
#include	<cassert>
using namespace std;

struct Bytes {
    public:
        char l1;
        char l2;
        char h1;
        char h2;
}; 
union HexNybble {
    public:
        Bytes bs;
        int v;
};

void func1() 
{
    //char* mem = new char[1];
    int hex1 = 0x90AB12CD;
    HexNybble hn1;
    hn1.v = hex1;
    cout << std::hex << (bitset<8>)hn1.bs.l1 << " " << (bitset<8>)hn1.bs.l2 <<  " " << (bitset<8>)hn1.bs.h1 << " " << (bitset<8>)hn1.bs.h2 << endl;

    cout << oct << (hex1&&(0xff000000) >> 24) << " ";
    cout << dec << (hex1&&(0xff000000) >> 24) << " ";
    cout << "in hex:" << endl;
    cout << hex << (hex1&&(0xff000000) >> 24) << " ";
    cout<<hex << (char) ((0x00ff0000 & hex1) >> 16)  << " ";
    cout<<hex << (char) ((0x0000ff00 & hex1) >> 8) << " ";
    cout<<hex << (char) (0x000000ff & hex1) << " " << endl;
    cout << "end hex:" << endl;
}

void func2(int x)
{
    //cout << std::cout.write(reinterpret_cast<char*>(x), sizeof x) << endl; 
    //    cout << std::cout.write(reinterpret_cast<const char*>(&x), sizeof(u_long)) << endl;
}

template <typename T>
class LinkedList {
    bool freed_;
    public:
    T v_;
    LinkedList* next_;
    LinkedList() : v_(T()), next_(NULL), freed_(false) {}
    LinkedList(T v) : v_(v), next_(NULL), freed_(false) {}
    ~LinkedList() {
        if (!freed_ && next_) {
            freed_ = true;
            next_->~LinkedList();
            delete next_;
            next_ = NULL;
        }
    }
    void Display(int n=100) {
        LinkedList* curr = this;
        while(curr && n-->0) {
            cout << curr->v_ << " ";
            curr = curr->next_;
        }
        cout << endl;
    }
    void Deduplicate() {

    }
    LinkedList<T>* Append(T t)
    {
        LinkedList* curr = this;
        while (curr->next_) {
            curr = curr->next_;
        }
        curr->next_ = new LinkedList<T>(t);
        return curr->next_;
    }
    void Append(LinkedList<T>* node)
    {
        LinkedList* curr = this;
        if (curr == node)
            return;
        while (curr->next_) {
            curr = curr->next_;
        }
        curr->next_ = node;
    }
};

typedef LinkedList<int> List1;

bool CheckCircle(LinkedList<int>* head)
{
    LinkedList<int> *curr = head;
    LinkedList<int> *prior = NULL;
    while (curr && prior != curr) {
        curr = curr->next_;
        if (!prior) {
            if (!curr) return false;
            prior = curr->next_;
        } else {
            prior = prior->next_;
            if (!prior) return false;
            prior = prior->next_;
        }
    }
    if (!curr) return false;
    return true;
}

void CheckCircle_driver()
{
    cout << "NULL list : "<< CheckCircle(NULL) << endl;
    LinkedList<int> head(1);
    cout << "head-only list : "<< CheckCircle(&head) << endl;
    head.Append(2);
    head.Append(3);
    head.Append(4);
    head.Append(5);
    LinkedList<int>* cs = head.Append(6);
    head.Append(7);
    head.Append(8);
    cout << "no circle list : "<< CheckCircle(&head) << endl;
    head.Append(cs);
    cout << "circled list : "<< CheckCircle(&head) << endl;

}
void FB1()
{
    LinkedList<int> head(1);
    head.Append(2);
    head.Append(3);
    head.Append(4);
    head.Append(5);
    head.Append(6);
    head.Append(7);
    head.Display();

    LinkedList<int>* front=&head;
    LinkedList<int> *end, *end_prev;
    while(front->next_) {
        end=front;
        while(end->next_) {
            end_prev = end;
            end=end->next_;
        }
        end->next_ = front->next_;
        front->next_ = end;
        front = end->next_;
        end_prev->next_ = NULL;
    }
    head.Display();
    cout << "FB1 end" << endl;
}

LinkedList<int>* reverse()
{
    LinkedList<int> head(1);
    head.Append(2);
    head.Append(3);
    head.Append(4);
    head.Append(5);
    head.Append(6);
    head.Append(7);
    head.Append(8);
    head.Append(9);
    head.Display();

    LinkedList<int> *curr = &head;
    LinkedList<int> *new_head = NULL;
    /*
       while(curr) {
       LinkedList<int>* tmp = curr->next_;
       if (tmp) {
       curr->next_ = new_head;
       new_head = curr;
       curr=tmp;
       } else {
       curr->next_ = new_head;
       new_head = curr;
       break;
       }

       }
       */
    while (curr) {
        LinkedList<int> * tmp = curr->next_;
        curr->next_ = new_head;
        new_head = curr;
        curr = tmp;
    }
    new_head->Display();
    cout << "reveser() end" << endl;
    return new_head;
}

LinkedList<int>* Sort(LinkedList<int>* head)
{
    LinkedList<int>* new_head = NULL, *new_end = NULL;
    LinkedList<int>* curr=head, *tmp, *pre_min=NULL;
    while(curr) {
        int min = curr->v_;
        pre_min = NULL;
        tmp = curr;
        while(tmp) {
            if (tmp->next_) {
                if (tmp->next_->v_ <= min) {
                    pre_min = tmp;
                    min = pre_min->next_->v_;
                }
            } else {
                if (pre_min) {
                    if (!new_head) {
                        new_head = new_end = pre_min->next_;
                        pre_min->next_ = pre_min->next_->next_;
                        new_end->next_ = curr;
                    } else {
                        new_end->next_ = pre_min->next_;
                        pre_min->next_ = pre_min->next_->next_;
                        new_end = new_end->next_;
                        new_end->next_ = curr;
                    }
                } else {
                    // curr is the minimal
                    if (!new_head) 
                        new_head = new_end = curr;
                    new_end = curr;
                    curr = curr->next_;
                }
                break;
            }
            tmp = tmp->next_;
        }
    }
    return new_head?new_head:head;    
}


void Sort_driver()
{
    cout << Sort(NULL) << endl;
    LinkedList<int> head(10);
    head.Append(20);
    head.Append(20);
    head.Append(4);
    head.Append(1);
    head.Append(1);
    head.Append(15);
    head.Append(8);
    head.Display();
    head.Append(0);
    head.Display();
    LinkedList<int>* newh = Sort(&head);
    newh->Display();
    //    head.Display();
    //    newh->Display();

}

LinkedList<int>* Sort012(LinkedList<int>* head)
{
    List1* zero_head=NULL, *zero_end;
    List1* one_head=NULL, *one_end, *two_head=NULL, *two_end;
    List1* curr=head, *new_head=NULL;
    while(curr) {
        cout << curr->v_ << endl;
        switch (curr->v_) {
            case 0:
                if(!zero_head)
                    zero_head=zero_end=curr;
                else
                    zero_end->next_ = curr;
                zero_end = curr;
                curr = curr->next_;
                zero_end->next_ = NULL;
                break;
            case 1:
                if(!one_head)
                    one_head=one_end=curr;
                else
                    one_end->next_ = curr;
                one_end = curr;
                curr = curr->next_;
                one_end->next_ = NULL;
                break;
            case 2:
                if(!two_head)
                    two_head=two_end=curr;
                else
                    two_end->next_ = curr;
                two_end = curr;
                curr = curr->next_;
                two_end->next_ = NULL;
                break;
            default:
                break;
        }   
    }
    cout << "...\n" << endl;

    if (zero_head) {
        new_head = zero_head;
        if (one_head) {
            zero_end->next_ = one_head;
            if (two_head) {
                one_end->next_ = two_head;
            }
        } else {
            if (two_head) 
                zero_end->next_ = two_head;
        }   
    } else {
        if (one_head) {
            new_head = one_head;
            if (two_head) {
                one_end->next_ = two_head;
            }
        } else {
            if (two_head) {
                new_head = two_head;
            }
        }
    }
    return new_head;
}

void Sort012_driver()
{
    List1 h(1);
    h.Append(2);
    h.Append(0);
    h.Append(1);
    h.Append(1);
    h.Append(2);
    h.Append(2);
    h.Append(0);
    h.Append(1);
    h.Append(1);
    h.Append(0);
    h.Append(2);
    h.Append(0);
    h.Append(1);
    h.Append(1);
    h.Display();
    List1 *nh = Sort012(&h);
    nh->Display();
    //delete nh;
}


    int
main0 ( int argc, char *argv[] )
{
    static char* a = "test12345";
    cout << sizeof(short) << endl;

    func1();
    cout << INT_MAX << endl << INT_MIN << endl;
    func2(10);

    int v2 = 100;
    cout << to_string(v2) << endl;

    string s("-1234d");
    cout << stol(s) <<endl;
    return 0;
}				/* ----------  end of function main  ---------- */
int main()
{

    //    FB1();
    //    reverse();
    //    CheckCircle_driver();
    Sort_driver();

    Sort012_driver();
    return 0;
}
