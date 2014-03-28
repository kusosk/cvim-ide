/*
 * =====================================================================================
 *
 *       Filename:  fifo.cxx
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2013 11:33:46 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <exception>

using std::cout;
using std::endl;
using std::exception;

template <typename T>
class ListNode {
    T& value;
    ListNode* next;
    public:
        ListNode() : value(T()) {next = NULL;}
        ListNode(T& t) : value(t) {next = NULL;}
        ListNode* getNext() { return next;}
        T& getValue() { return value;}
};

namespace DS {
    template <typename T>
    class ListNode {
        const T& value;
        ListNode* next;
        public:
            ListNode() : value(T()) {next = NULL;}
            ListNode(T& t) : value(t) {next = NULL;}
            ListNode* getNext() { return next;}
            const T& getValue() { return value;}
    };
    template <typename T>
    class List {
        ListNode<T>* head;
    public:
        List() {
            try {
            head = new ListNode<T>;
            } catch (exception &e) {
                cout << "cannot create list head: " << e.what() << endl;
            } catch (...) {
                cout << "cannot create list head: " << "UNKNOWN REASON" << endl;
            }
        }
        virtual ~List() {
            if (!head)
                return ;
            for (ListNode<T>* curr = head; curr!=NULL;) {
                ListNode<T>* tmp = curr->getNext();
                delete curr;
                curr = tmp;
            }
            delete head;
        }
    };
};

class T1 {
    const int i1;
    int& i2;
    const int& i3;
public:
    T1() : i1(int()), i2(* new int(1)), i3(int()) {}
    void getValue() { cout << "i1=" << i1 << " i2=" << i2 << " i3=" << i3<<endl;}
};
int main(void) {
    DS::ListNode < int > intList1

    return 0;
}
