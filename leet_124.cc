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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxleft = 0;
        int maxright = 0;
        int maxsum = 0;
        dfs(root, maxleft, maxright, maxsum);
        return maxsum;
    };
    void dfs(TreeNode* root, int &maxleft , int &maxright, int &maxsum) {
        if(!root) {
            maxleft = 0;
            maxright = 0;
            return ;
        }
        dfs(root->left, maxleft, maxright, maxsum);
        int mleft = root->val + max(maxleft, maxright);
        dfs(root->right, maxleft, maxright, maxsum);
        int mright = root->val + max(maxleft, maxright);
        maxleft = mleft;
        maxright = mright;
        int tmp = mleft + mright - root->val;
        if(tmp > maxsum)
            maxsum = tmp;
        return ;
    }
};


int main(int argc , char** argv) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    TreeNode* root = NULL;
    createTree(data, root);
    Solution sol;
    int maxsum = sol.maxPathSum(root);
    cout << "max is " << maxsum << endl;
    destroyTree(root);
    return 0;
}



