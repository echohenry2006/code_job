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
      int sum;
      int sumNumbers(TreeNode* root){
        sum=0;
        dfs(0,root);
        return sum;
      }

      void dfs(int curSum, TreeNode* root){
        int newSum=curSum*10+root->val;
        if(root->left){
            dfs(newSum,root->left);
        }
        if(root->right){
            dfs(newSum,root->right);
        }
        if(!root->left && !root->right)
            sum+=newSum;
        return ;

      }
};


int main(int argc , char** argv) {
    TreeNode* root=NULL;
    /* vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }; */
    vector<int> data = { 1, 2, 3 };
    createTree(data,root);
    cout<<"tree created!!"<<endl;

    Solution sol;
    cout<<sol.sumNumbers(root)<<endl;
    
    cout<<"hello world!!"<<endl;
    destroyTree(root);
    return 0;
}


