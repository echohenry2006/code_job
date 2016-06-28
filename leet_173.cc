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


class BSTIterator
{
	public:
	BSTIterator(TreeNode *root)
	{
		TreeNode* p=root;
		while(p)
		{
			s1.push(p);
			//cout<<p->val<<endl;
			p=p->left;
		}

	}

	bool hasNext()
	{
		return !s1.empty();
	}

	int next()
	{
		TreeNode* ret = s1.top();
		s1.pop();
		//cout<<"top is "<<ret->val<<endl;
		if(ret->right)
		{
			//s2.push(ret);
			//s1.push(ret);
			TreeNode* p=ret->right;
			while(p)
			{
				s1.push(p);
				p=p->left;
			}

		}
		return ret->val;

	}

	stack<TreeNode*> s1;
	


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

	BSTIterator i= BSTIterator(root);
	cout<<"Iterator initialized!!"<<endl;
	while(i.hasNext()) cout<<i.next();

	destroyTree(root);

	return 0;

	

		
	
}

