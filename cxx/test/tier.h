#pragma once
#ifndef TIER_H_
#define TIER_H_
#endif

#include	<iostream>
#include    <string>
#include    <cstring>

#if 0
extern size_t strlen(const char* str);
extern void memset(void* m, int v, int len);
#endif
using namespace std;

class Tier;
typedef Tier* TierPtr;
class Tier {
    bool isword;
    TierPtr* edges_;
    public:
    size_t  cnt;
    Tier() : isword(false), edges_(NULL), cnt(0){};
    ~Tier() {
        Cleanup();
    }
    void Cleanup(const string msg="", const string end="")
    {
        Tier* curr = this;
        Tier* tmp = NULL;
        if (msg.length())
            std::cout << msg << endl;
        if (curr->edges_) {
            for (int i=0; i<26; i++) {
                tmp=curr->edges_[i];
                if (tmp) {
                    tmp->~Tier();
                    std::cout << "N " << tmp << endl;
                    delete tmp;
                    curr->edges_[i] = NULL;
                }
            }
            std::cout << "E " <<curr->edges_ << endl;
            delete[] curr->edges_;
            curr->edges_ = NULL;
        }
        if (end.length())
            std::cout << end << endl;

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
            std::cout << "current c:" << c<<endl;

            if (curr->edges_) {
#ifdef LOGGERIT
                std::cout << "Tier edges ready for " << c << ", search into"<<endl;
#endif
                if (curr->edges_[c-'a'])
                    curr = curr->edges_[c-'a'];
                else {
                    if (!insert_mode) {
                        last_pos = i-1;
                        return curr;
                    }
#ifdef LOGGERIT
                    std::cout << "Need new tier node for " << c <<endl;
#endif
                    try {
                        curr->edges_[c-'a'] = new Tier;
                        curr = curr->edges_[c-'a'];
#ifdef LOGGERIT
                        std::cout << "new node ready for " << c << endl;
#endif
                    } catch (...) { Cleanup("Memory fail: Retry..."); return NULL;}
                }
            } else {
                if (!insert_mode) {
                    last_pos = i-1;
                    return curr;
                }
#ifdef LOGGERIT
                std::cout << "Need new tier edges for " << c << endl;
#endif
                try {
#ifdef LOGGERIT
                    std::cout << "Create new tier edges for " << c <<endl;
#endif
                    curr->edges_ = new TierPtr[26];
                    try {
#ifdef LOGGERIT
                        std::cout << "Create new tier node for " << c <<endl;
#endif            
                        memset(curr->edges_, 0, 26*sizeof(Tier*));

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
        std::cout << endl;
        return curr;
    }
    Tier* PeekWord(const char* word, int& last_found_pos)
    {
        return SearchWord(word, false, last_found_pos, false, false);
    }
};

