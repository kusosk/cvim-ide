/*
 * =====================================================================================
 *
 *       Filename:  binaryTree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/16/2013 08:46:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <deque>
//
using namespace std;

struct TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):value(v),left(NULL),right(NULL){}
};

typedef TreeNode* BinaryTree;

void BuildTree(BinaryTree tree, int s, int n) 
{
    if (!tree) return;

    int v = s;
    deque<TreeNode*> tmp;
    TreeNode* curr = tree;
    tmp.push_back(curr);
    while (tmp.size()!=0 && v < n) {
        curr = tmp.front();
        tmp.pop_front();
        curr->left = new TreeNode(v++);
        curr->right = new TreeNode(v++);
        tmp.push_back(curr->left);
        tmp.push_back(curr->right);
    }
}

void Cleanup(BinaryTree tree)
{
    if (!tree)
        return;

    deque<TreeNode*> tmp;
    TreeNode* curr = tree;
    tmp.push_back(curr);
    while (tmp.size()!=0) {
        curr = tmp.front();
        tmp.pop_front();

        if (!curr)
            continue;
        tmp.push_back(curr->left);
        tmp.push_back(curr->right);
        delete curr;
    }

}

void travel_by_layer(BinaryTree tree)
{
    if (!tree)
        return;

    int cnt = 0;
    int layer = 1;
    deque<TreeNode*> tmp;
    tmp.push_back(tree);

    cout << "level " << layer << ": ";
    while (tmp.size() != 0) {
        TreeNode* curr = tmp.front();
        if (!curr) {
            cnt ++;
            continue;
        }
        cout << curr->value << ", " ;
        cnt++;
        tmp.pop_front();
        if (curr->left)
            tmp.push_back(curr->left);
        if (curr->right)
            tmp.push_back(curr->right);
        int sz = tmp.size();
        if (sz >> layer == 1){
            cout << endl << "level " << ++layer << ": ";
        }
    }
    cout << endl;
}

void zigzag_layer_visit(BinaryTree tree)
{
    if (!tree)
        return;

    int cnt = 0;
    int layer = 1;
    bool is_odd_layer = true;
    deque<TreeNode*> tmp;
    deque<TreeNode*> tmp2;
    tmp.push_back(tree);

    cout << "level " << layer << ": ";
    while (tmp.size() || tmp2.size()) {
        TreeNode* curr = tmp.front();
        if (!curr) {
            cnt ++;
            tmp.pop_front();
            continue;
        }
        cnt++;
        tmp.pop_front();
        tmp2.push_back(curr);

        if (curr->left)
            tmp.push_back(curr->left);
        if (curr->right)
            tmp.push_back(curr->right);
        int sz = tmp.size();
        if (sz >> layer == 1){
            TreeNode* curr_layer = NULL;
            if (is_odd_layer) {
                // left to right
                for (deque<TreeNode*>::iterator curr_pos = tmp2.begin();
                        curr_pos != tmp2.end(); ++curr_pos) {
                    curr_layer = *curr_pos;
                    cout << curr_layer->value << ", ";
                }
            } else {
                // right to left
                for (deque<TreeNode*>::reverse_iterator curr_pos = tmp2.rbegin();
                        curr_pos != tmp2.rend(); ++curr_pos) {
                    curr_layer = *curr_pos;
                    cout << curr_layer->value << ", ";
                }
                
            }
            // cleanup tmp2
            tmp2.clear();
            if (tmp.size())
                cout << endl << "level " << ++layer << ": ";
            is_odd_layer = is_odd_layer ? false : true;
        }

    }
    cout << endl;

}

int main()
{
    BinaryTree tree = new TreeNode(1);

    BuildTree(tree, 2, 15);
    travel_by_layer(tree);   
    zigzag_layer_visit(tree);
    Cleanup(tree);

    return 0;
}
