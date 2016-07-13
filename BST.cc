/**
 * @file BST.cc
 * @brief BST traversal algorithms
 * @author Yong Yang
 * @version 1.00000
 * @date 2016-07-01
 */
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL) {
    }
};

class Solution {
  public:
    void  preorderTraversal(TreeNode* root) {
        if(!root)return;
        cout << root->val << endl;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ;
    };

    void  inorderTraversal(TreeNode* root) {
        if(!root)return;
        inorderTraversal(root->left);
        cout << root->val << endl;
        inorderTraversal(root->right);
        return ;
    };
    void  postorderTraversal(TreeNode* root) {
        if(!root)return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << endl;
        return ;
    };
    // iteration using stack , not recursive
    void preorderTraversal_stack(TreeNode* root) {
        stack<TreeNode*> s;
        if(!root)return ;
        s.push(root);
        while(!s.empty()) {
            TreeNode* p = s.top();
            s.pop();
            cout << p->val << endl;
            if(p->right)s.push(p->right);
            if(p->left)s.push(p->left);
        }
    };
    void inorderTraversal_stack(TreeNode* root) {
        stack<TreeNode*> s;
        if(!root)return;
        TreeNode* p = root;
        while(p != NULL || !s.empty()) {
            if(p != NULL) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                cout << p->val << endl;
                p = p->right;
            }
        }
    };

    void postorderTraversal_stack(TreeNode* root) {
        enum Tags {Left, Right};
        class StackElement {
          public:
            TreeNode* pointer;
            Tags tag;
        };
        stack<StackElement> s;
        if(!root)return;
        TreeNode* p = root;
        while(p || !s.empty()) {
            if(p) {
                StackElement elem;
                elem.pointer = p;
                elem.tag = Left;
                s.push(elem);
                p = p->left;
            } else {
                StackElement elem = s.top();
                s.pop();
                if(elem.tag == Left) {
                    elem.tag = Right;
                    s.push(elem);
                    p = elem.pointer->right;
                } else
                    cout << elem.pointer->val << endl;
            }
        }
    };

    void inorderMorrisTraversal(TreeNode* root) {
        TreeNode* cur = root;
        if(cur == NULL) return ;
        while(cur) {
            if(cur->left == NULL) {
                cout << cur->val << endl;
                cur = cur->right;
            } else {
                TreeNode* precur = cur->left;
                while(precur->right != NULL && precur->right != cur )
                    precur = precur->right;
                if(precur->right == NULL) {
                    precur->right = cur;
                    cur = cur->left;
                } else {
                    precur->right = NULL;
                    cout << cur->val << endl;
                    cur = cur->right;
                }
            }
        }
    };

    void preorderMorrisTraversal(TreeNode* root) {
        TreeNode* cur = root;
        while(cur) {
            if(cur->left == NULL){
                cout << cur->val << endl;
                cur = cur->right;
            }
            else {
                TreeNode* precur = cur->left;
                while(precur->right != NULL && precur->right != cur)
                    precur = precur->right;
                if(precur->right == NULL) {
                    precur->right = cur;
                    cout << cur->val << endl;
                    cur = cur->left;
                } else {
                    precur->right = NULL;
                    cur = cur->right;
                }
            }
        }

    };

    void postorderMorrisTraversal(TreeNode* root){
        TreeNode* cur = root;

    }
};

void destroyTree(TreeNode* root) {
    if (!root)
        return;

    if (root->left)
        destroyTree(root->left);
    if (root->right)
        destroyTree(root->right);
    delete root;
}

int main(int argc, char** argv) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    TreeNode* root = new TreeNode(1);
    queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < data.size();) {
        TreeNode* p = q.front();
        q.pop();
        if (i < data.size()) {
            p->left = new TreeNode(data[i]);
            i++;
            q.push(p->left);
        }
        if (i < data.size()) {
            p->right = new TreeNode(data[i]);
            i++;
            q.push(p->right);
        }
    }

    cout << "*******************" << endl;
    Solution sol;
    cout << "inorder traversal!!" << endl;
    sol.inorderTraversal(root);
    cout << "preorder traversal!!" << endl;
    sol.preorderTraversal(root);
    cout << "postorder traversal!!" << endl;
    sol.postorderTraversal(root);
    cout << "preorder traversal stack!!" << endl;
    sol.preorderTraversal_stack(root);
    cout << "inorder traversal stack!!" << endl;
    sol.inorderTraversal_stack(root);
    cout << "postorder traversal stack!!" << endl;
    sol.postorderTraversal_stack(root);
    cout << "inorder morris traversal !!" << endl;
    sol.inorderMorrisTraversal(root);
    cout << "preorder morris traversal !!" << endl;
    sol.preorderMorrisTraversal(root);

    destroyTree(root);

    return 0;
}




