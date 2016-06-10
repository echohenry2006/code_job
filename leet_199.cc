#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cassert>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    vector<int> rightSideView(TreeNode* root){
        int h=0;
        vector<int> vec(20,0);
        DFS(root,h,vec);
        vector<int> ret(vec.begin(),vec.begin()+h);
        return ret;
    }

    void DFS(TreeNode* root, int &h, vector<int> &vec){
        
        if(root){
            if(vec.size()<h+1)
                vec.resize(h,2*(h+1));
            vec[h]=root->val;
            h++;
            DFS(root->left,h,vec);
            DFS(root->right,h,vec);
        }
    }

        
        
};


int main(int argc , char** argv)
{
    

}

