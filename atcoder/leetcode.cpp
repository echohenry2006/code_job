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

void destroyTree(TreeNode* root) {
    if (!root)
        return;

    if (root->left)
        destroyTree(root->left);
    if (root->right)
        destroyTree(root->right);
    delete root;
};

vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
void createTree(vector<int> &data, TreeNode* &root) {
    assert(root == NULL);
    root = new TreeNode(data[0]);
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
}



class Solution {
  public:
};


int main(int argc , char** argv) {
}


