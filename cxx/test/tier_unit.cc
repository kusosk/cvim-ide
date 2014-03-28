#include "gtest/gtest.h"

#include	<iostream>
#include	<stack>
#include	<cstring>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;

class Tier {
    bool isword;
    Tier** edges_;
    public:
    size_t  cnt;
    Tier() : isword(false), edges_(NULL), cnt(0){};
    /*
    ~Tier()
    {
        Cleanup("dctor working..");
    }
    void Cleanup(const string msg="", const string end="cleanup done")
    {
        Tier* curr = this;
        stack<Tier*> top_nodes;
        if (msg.length())
            cout << msg << endl;
        top_nodes.push(curr);
        while(top_nodes.size()!=0) {
            curr = top_nodes.top();
            top_nodes.pop();
            if (curr->edges_) {
                for (int i=0; i<26; i++) {
                    if (curr->edges_[i])
                        top_nodes.push(curr->edges_[i]);
                }
                delete[] curr->edges_;
            }
            if (curr && curr != this)
                delete curr;
        }
        if (end.length())
            cout << end << endl;
    }
    */
    ~Tier() {
        Cleanup("Dtor working...");
    }
    void Cleanup(const string msg="", const string end="cleanup done")
    {
        Tier* curr = this;
        Tier* tmp = NULL;
        if (msg.length())
            cout << msg << endl;
        if (curr->edges_) {
            for (int i=0; i<26; i++) {
                if ( (tmp=curr->edges_[i]) )
                    tmp->~Tier();
            }
            delete[] curr->edges_;
        }
        if (end.length())
            cout << end << endl;

    }
    // in NON-INSERT mode, return the last Tier Node retrieved, and last_pos holds the last found character in Tier
    // in INSERT mode, return the new-inserted Tier Node, and last_pos==strlen(word), if inc_cnt set, increase retrieved count by 1;
    Tier* SearchWord(const char* word, bool insert_mode, int& last_pos, bool inc_cnt, bool mark_complete)
    {
        if (!word || !strlen(word))
            return NULL;
        size_t len = strlen(word);
        Tier* curr = this;
        for (size_t i=0; i<len; ++i) {
            char c = word[i] > 'Z' ? word[i] : (word[i]|('a'^'A'));
            cout << "current c:" << c<<endl;

            if (curr->edges_) {

                cout << "Tier edges ready for " << c << ", search into"<<endl;

                if (curr->edges_[c-'a'])
                    curr = curr->edges_[c-'a'];
                else {
                    if (!insert_mode) {
                        last_pos = i>1?i-1:0;
                        return curr;
                    }
                    cout << "Need new tier node for " << c <<endl;

                    try {
                        curr->edges_[c-'a'] = new Tier;
                        curr = curr->edges_[c-'a'];
                    } catch (...) { Cleanup("Memory fail: Retry..."); return NULL;}
                }
            } else {
                if (!insert_mode) {
                    last_pos = i>1?i-1:0;
                    return curr;
                }
                    cout << "Need new tier edges for " << c << endl;

                try {
                    cout << "Create new tier edges for " << c <<endl;

                    curr->edges_ = new Tier*[26];
                    try {
                    cout << "Create new tier node for " << c <<endl;

                        curr->edges_[c-'a'] = new Tier;
                        curr = curr->edges_[c-'a'];
                    } catch (...) { Cleanup("Memory fail: Retry..."); return NULL;}
                } catch (...) { Cleanup("Memory fail: Retry..."); return NULL;}
            }
        }
        last_pos = len;
        if (mark_complete)
            curr->isword=true;
        if (inc_cnt)
            curr->cnt ++;
        return curr;
    }
    Tier* PeekWord(const char* word, int& last_found_pos)
    {
        return SearchWord(word, false, last_found_pos, false, false);
    }
};

TEST(TIER, OPS)
{
    Tier root;
    int last_found_idx = -1;
    cout << "root@" << &root<<endl;
    cout << root.PeekWord("ABC", last_found_idx)<< " last pos:" << last_found_idx << endl;
    Tier* curr = root.SearchWord("ABC", true, last_found_idx, true, true);
    if (curr)
        cout << curr << curr->cnt << " last pos:"<< last_found_idx << endl;
    else
        cout << "NOT FOUND, last pos:"<< last_found_idx << endl;

    curr = root.PeekWord("AB", last_found_idx);
    if (curr)
        cout << curr << curr->cnt << " last pos:"<< last_found_idx << endl;
    else
        cout << "NOT FOUND, last pos:"<< last_found_idx << endl;

    curr = root.PeekWord("BA", last_found_idx);
    if (curr)
        cout << curr << curr->cnt << " last pos:"<< last_found_idx << endl;
    else
        cout << "NOT FOUND, last pos:"<< last_found_idx << endl;
    
    curr = root.SearchWord("BA", true, last_found_idx, true, true);
    if (curr)
        cout << curr << curr->cnt << " last pos:"<< last_found_idx << endl;
    else
        cout << "NOT FOUND, last pos:"<< last_found_idx << endl;


    /*
    */
}
