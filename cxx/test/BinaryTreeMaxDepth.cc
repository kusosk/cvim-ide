#include	<iostream>
#include	<stack>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root) {
    int level = 0;
    int max = 0;
    if (!root) return 0;
    stack<TreeNode*> nodes;
    TreeNode* curr = root;
    int tmp_depth = 0;
    bool rec_tmp_depth=false;
    while(curr || nodes.size()) {
        cout << "*************      " << curr->val << "     **************"<<endl;
        if (!curr->left && !curr->right) {
            level++;
            max = max<level?level:max;
            if (nodes.size()) {
                curr=nodes.top();
                nodes.pop();
                level-= tmp_depth;
                tmp_depth = (int)nodes.top();
                nodes.pop();
                rec_tmp_depth=true;
                cout << "backtrace: note[" << curr->val << "] maxd="
                    << max << " tmp_depth="<<tmp_depth<<endl;
            } else 
                break;
        }
        if (curr->left && curr->right) {
                cout << "push: node[" << curr->right->val << "] level="
                    << level << " tmp_depth="<<tmp_depth<<endl;
            nodes.push((TreeNode*)tmp_depth);
            nodes.push(curr->right);
            rec_tmp_depth=true;
            tmp_depth=1;
            curr=curr->left;
            level++;
                
                cout << "continue on: node[" << curr->val << "] level="
                    << level << " tmp_depth="<<tmp_depth<<endl<<endl;
        }
        if (curr->left && !curr->right) {
            curr=curr->left;
            level++;
            if (rec_tmp_depth)
               tmp_depth++;
            cout << "on left: node[" << curr->val << "] level="
                    << level << " tmp_depth="<<tmp_depth<<endl;
        }
        if (!curr->left && curr->right)
        {
            curr=curr->right;
            level++;
            if(rec_tmp_depth)
                tmp_depth++;
            cout << "on right: node[" << curr->val << "] level="
                    << level << " tmp_depth="<<tmp_depth<<endl;
        } 
    }
    return max;
}
int main()
{
    TreeNode root(0);
    root.left=new TreeNode(2);
    root.right=new TreeNode(4);

    root.left->left=new TreeNode(1);
    root.left->right=NULL;
    root.right->left=new TreeNode(3);
    root.right->right=new TreeNode(7);

    root.left->left->left=new TreeNode(5);
    root.left->left->right=new TreeNode(10);

    root.right->left->left=NULL;
    root.right->left->right=new TreeNode(6);

    root.right->right->left=NULL;
    root.right->right->right=new TreeNode(8);

    cout << maxDepth(&root) << endl;

    return 0;

}
