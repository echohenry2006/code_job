#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cassert>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
        , next(NULL){
    }
};

void destroyTree(TreeLinkNode* root) {
    if (!root)
        return;

    if (root->left)
        destroyTree(root->left);
    if (root->right)
        destroyTree(root->right);
    delete root;
};

void createTree(vector<int> &data, TreeLinkNode* &root) {
    assert(root == NULL);
    root = new TreeLinkNode(data[0]);
    queue<TreeLinkNode*> q;
    q.push(root);

    for (int i = 1; i < data.size();) {
        TreeLinkNode* p = q.front();
        q.pop();
        if (i < data.size()) {
            p->left = new TreeLinkNode(data[i]);
            i++;
            q.push(p->left);
        }
        if (i < data.size()) {
            p->right = new TreeLinkNode(data[i]);
            i++;
            q.push(p->right);
        }
    }
}



class Solution {
  public:
      void connect(TreeLinkNode *root);


};


int main(int argc , char** argv) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
}


