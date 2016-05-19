#include<iostream>
#include<vector>
#include<cassert>

typedef std::vector<int> vec;

struct BTrieNode{
	int count;
	BTrieNode* left;
	BTrieNode* right;
	BTrieNode(int in=0):count(in),left(NULL),right(NULL){};
};	




class BTrie{
	public: 
		BTrie();
		BTrie(vec v);
		bool isEmpty();
		void insert(const vec &v);
		void clean();
		bool find(const vec &v);
		~BTrie(){
			clean();
			delete root;
		}
	private:
		BTrieNode* root;
		int depth;
		void remove(BTrieNode* p);
};


BTrie::BTrie():depth(0){
	root = new BTrieNode();
};
BTrie::BTrie(vec v):root(NULL){
	
	depth = v.size();
	root = new BTrieNode();
	insert(v);
#ifdef DEBUG
	std::cout<<"depth ==" <<depth<<std::endl;
#endif
}


void BTrie::insert(const vec &a){
	if(depth==0)
		depth = a.size();
	assert(depth==a.size());
	BTrieNode* p = root; 
	for(int i = 0 ;i< depth;i++){
		if(a[i]==0){
			if(p->left==NULL)
				p->left=new BTrieNode();
			p = p->left;
		}
		else{
			if(p->right==NULL)
				p->right=new BTrieNode();
			p = p->right;
		}
	}
}

bool BTrie::isEmpty(){
	return (depth==0);
}

void BTrie::clean(){
	if(isEmpty())return;
	remove(root->left);
	remove(root->right);
	depth=0;
}

void BTrie::remove(BTrieNode* p){
	if(p!=NULL){
		if(p->left!=NULL)
			remove(p->left);
		if(p->right!=NULL)
			remove(p->right);
		delete p;
		p=NULL;
	}
	return; 
}
	

bool BTrie::find(const vec &v){

				
	assert(v.size()==depth);
	BTrieNode* p = root; 
	for(int i = 0 ;i< depth;i++){
		if(v[i]==0){
			if(p->left==NULL)
				return false;
			p = p->left;
		}
		else{
			if(p->right==NULL)
				return false;
			p = p->right;
		}
	}
	return true;
}





int main(int argc , char ** argv){
	vec v1{0,0,1,1,0,1,0,1};
	BTrie tree(v1);
	vec v2{1,1,1,1,1,1,1,1};
	if(tree.find(v1))
		std::cout<<"find@!"<<std::endl;
	if(tree.find(v2))
		std::cout<<"find@!"<<std::endl;
	return 0;
}
