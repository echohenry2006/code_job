#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cassert>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        typedef pair <TreeNode*,int> node;
        int i=1;
        int minD;
        queue<node> q;
        if(NULL==root) return 0;
        node info;
        TreeNode* p;
        q.push(node(root, i));
        while(!q.empty()){
            info = q.front();
            q.pop();
            p = info.first;
            minD = info.second;
            if( NULL != p->left){
                i = minD+1;
                q.push(node(p->left,i));
            }
            if( NULL != p->right){
                i = minD+1;
                q.push(node(p->right,i));
            }
            if( NULL == p->left && NULL == p->right)
                break;
        }

        return minD;

    }


};




int main(int argc , char** argv)
{

}
