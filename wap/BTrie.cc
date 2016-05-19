#ifndef __TRIETREE__
#define __TRIETREE__

#include<iostream>
#include<vector>
#include<cassert>

typedef std::vector<int> vec;

struct BTrieNode{
	int count;
	BTrieNode* left;
	BTrieNode* right;
	BTrieNode(int in=0):count(in),left(nullptr),right(nullptr){};
};	




class BTrie{
	public: 
		BTrie();
		BTrie(vec v);
		bool isEmpty();
		void insert(const vec &v);
		void insert(const vec &v, const vec &order);
		void clean();
		bool find(const vec &v);
        int  get_max_count(int i){
            return max_count[i];
        }
		~BTrie(){
			clean();
			delete root;
		}
	private:
		BTrieNode* root;
		int depth;
		void remove(BTrieNode* p);
        vec max_count;
};


BTrie::BTrie():depth(0){
	root = new BTrieNode(0);

};
BTrie::BTrie(vec v):root(nullptr){
	
	depth = v.size();
    if(max_count.size()!=depth)
        max_count.resize(depth,0);

	root = new BTrieNode();
	insert(v);
#ifdef DEBUG
	std::cout<<"depth ==" <<depth<<std::endl;
#endif
}


void BTrie::insert(const vec &a){
	if(depth==0)
		depth = a.size();
    if(max_count.size()!=depth)
        max_count.resize(depth,0);
	assert(depth==a.size());
	BTrieNode* p = root; 
	for(int i = 0 ;i< depth;i++){
		if(a[i]==0){
			if(p->left==nullptr)
				p->left=new BTrieNode(0);
            p->count++;
            if((p->count)>max_count[i])
                max_count[i]=p->count;
			p = p->left;

		}
		else{
			if(p->right==nullptr)
				p->right=new BTrieNode(0);
            p->count++;
            if((p->count)>max_count[i])
                max_count[i]=p->count;
			p = p->right;
		}
	}
}

void BTrie::insert(const vec &a, const vec &order){
	if(depth==0)
		depth = a.size();
    if(max_count.size()!=depth)
        max_count.resize(depth,0);
	assert(depth==a.size());
	BTrieNode* p = root; 
	for(int i = 0 ;i< depth;i++){
		if(a[order[i]]==0){
			if(p->left==nullptr)
				p->left=new BTrieNode(0);
            p->count++;
            if((p->count)>max_count[i])
                max_count[i]=p->count;
			p = p->left;

		}
		else{
			if(p->right==nullptr)
				p->right=new BTrieNode(0);
            p->count++;
            if((p->count)>max_count[i])
                max_count[i]=p->count;
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
    max_count.clear();
    root->count=0;
    root->left=nullptr;
    root->right=nullptr;
    assert(root->left==nullptr);
    assert(root->right==nullptr);

}

void BTrie::remove(BTrieNode* p){
	if(p!=nullptr){
			remove(p->left);
			remove(p->right);
		delete p;
	}
	return; 
}
	

bool BTrie::find(const vec &v){

    if(depth==0)
        return false;
	assert(v.size()==depth);
	BTrieNode* p = root; 
	for(int i = 0 ;i< depth;i++){
		if(v[i]==0){
			if(p->left==nullptr)
				return false;
			p = p->left;
		}
		else{
			if(p->right==nullptr)
				return false;
			p = p->right;
		}
	}
	return true;
}



#ifdef TRIE__TEST

int main(int argc , char ** argv){
	vec v1{0,1,0};
	vec v2{1,0,0};
	vec v3{0,1,1};
    
	BTrie tree(v1);
    tree.insert(v2);
    tree.insert(v3);

    tree.clean();
    tree.insert(v1);
    tree.insert(v3);
    tree.insert(v2);
    
    for(int i=0;i<v1.size();i++)
        std::cout<<"max of " << i << " is " <<tree.get_max_count(i)<<std::endl;

	if(tree.find(v1))
		std::cout<<"find@!"<<std::endl;
	if(tree.find(v2))
		std::cout<<"find@!"<<std::endl;
    tree.clean();
	return 0;
}

#endif
#endif
