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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* ptr=q.top();
            q.pop();
           
            //TODO
           
    }
};



void destroyTree(TreeNode* root)
{
	if(!root) return; 

	if(root->left)
		destroyTree(root->left);
	if(root->right)
		destroyTree(root->right);
	delete root;
	
}

int main(int argc , char** argv)
{
	vector<int> data={1,2,3,4,5,6,7,8,9,10,11};
	TreeNode* root=new TreeNode(1);
	queue<TreeNode*> q;
	q.push(root);

	for(int i=1;i<data.size();)
	{
		TreeNode* p=q.front();
		q.pop();
		if(i<data.size()){
			p->left=new TreeNode(data[i]);
			i++;
			q.push(p->left);
		}
		if(i<data.size()){
			p->right= new TreeNode(data[i]);
			i++;
			q.push(p->right);
		}
			
	}

	cout<<"*******************"<<endl;


	destroyTree(root);

	return 0;

	

		
	
}

