#ifndef __XORTRIETREE__
#define __XORTRIETREE__

#include<iostream>
#include<vector>
#include<bitset>
#include<cassert>


typedef unsigned long long bigint;
typedef std::bitset<40> bitvec;

struct BTrieNode{
	int index;
	BTrieNode* left;
	BTrieNode* right;
	BTrieNode(int in=-1):index(in),left(nullptr),right(nullptr){};
};	




class BTrie{
	public: 
		BTrie();
		bool isEmpty();
		void insert(const bitvec &v,int index);
		void clean();
		int find(const bitvec &v);
        
		~BTrie(){
			clean();
			delete root;
		}
	private:
		BTrieNode* root;
		int depth;
		void remove(BTrieNode* &p);
};


BTrie::BTrie():depth(0){
	root = new BTrieNode(0);

};


void BTrie::insert(const bitvec &a,int index){
	if(depth==0)
		depth = a.size();
	assert(depth==a.size());
	BTrieNode* p = root; 
	for(int i = depth-1 ;i>=0;i--){
		if(a[i]==0){
			if(p->left==nullptr)
				p->left=new BTrieNode(0);
			p = p->left;
            if(i==0)p->index=index; 

		}
		else{
			if(p->right==nullptr)
				p->right=new BTrieNode(0);
			p = p->right;
            if(i==0)p->index=index; 
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
//    root->left=nullptr;
//    root->right=nullptr;
    assert(root->left==nullptr);
    assert(root->right==nullptr);

}

void BTrie::remove(BTrieNode* &p){
	if(p!=nullptr){
			remove(p->left);
			remove(p->right);
		delete p;
        p=nullptr;
	}
	return; 
}
	

int BTrie::find(const bitvec &v){

    if(depth==0)
        return -1;
	assert(v.size()==depth);
	BTrieNode* p = root; 
	for(int i = depth-1 ;i>=0;i--)
		if(v[i]==0){
			if(p->right!=nullptr)
			    p = p->right;
            else
                p = p->left;
        }
		
		else{
			if(p->left!=nullptr)
			    p = p->left;
            else 
                p = p->right;
        }

    //std::cout<<"#####"<<std::endl;
	return p->index;	
}




#ifdef XORTRIE__TEST

int main(int argc , char ** argv){
	bitvec v1(std::string("00001111"));
	bitvec v2(std::string("00001001"));
	bitvec v3(std::string("00000000"));

    if(v1[1]==1)
        std::cout<<"#####"<<v1[1]<<std::endl;

    std::cout<<"v1: "<<v1<<std::endl;
    
    BTrie tree;

    tree.insert(v1,1);
    tree.insert(v2,2);
    tree.insert(v3,3);
    
    std::cout<<"#####"<<std::endl;

    int max_ind=tree.find(v2);
    assert(max_ind>=0);
    std::cout<<"#####"<<std::endl;

    std::cout<<"max xor is"<<max_ind<<std::endl;
    tree.clean();
	return 0;
}

#endif
#endif
