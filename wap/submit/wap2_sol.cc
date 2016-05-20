#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
#include<tuple>
//#include<cassert>
#define MAX 100000

typedef unsigned long long bigint;
typedef std::bitset<40> bitvec;
std::vector<bigint> in(MAX); 

struct BTrieNode{
	int index; // remember the index of leaves in the vector
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
	//assert(depth==a.size());
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

 //   assert(root->left==nullptr);
 //   assert(root->right==nullptr);

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
	
// greedy search the vector which has max xor with v, return the index  
int BTrie::find(const bitvec &v){

    if(depth==0)
        return -1;
	//assert(v.size()==depth);
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




std::tuple<int,int,bigint> max_xor(const std::vector<bigint> &vec, int n){
  //  int n = vec.size();


    std::vector<bigint> pre_xor(n+1);
    std::vector<bigint> suf_xor(n+1);
    
    pre_xor[0]=0;
    suf_xor[n]=0;
	//compute prefix xor and suffix xor
    for(int i=1;i<n+1;i++){
        pre_xor[i]=pre_xor[i-1]^vec[i-1];
        suf_xor[n-i]=suf_xor[n-i+1]^vec[n-i];
    }

    BTrie tree;

    int l,r;
    bigint max=0;
    bigint tmp;
    int tmp_ind;
    
    for(int i=0;i<n;i++){
        tree.clean();
        for(int j=i+1;j<n+1;j++)
            tree.insert(bitvec(suf_xor[j]),j);
        tmp_ind = tree.find(bitvec(pre_xor[i]));
        tmp = suf_xor[tmp_ind]^pre_xor[i];
        if(tmp>max) {
            max=tmp;
            l=i;
            r=tmp_ind;
        }
        
    }
    std::tuple<int,int,bigint> out(l,r,max);
    return out;
}

    




int main(int argc, char** argv)
{
    int N;
    int l,r;
    while(std::cin>>N){
        
        for(int i=0;i<N;i++)
            std::cin>>in[i];
        

        std::tuple<int,int,bigint> out=max_xor(in,N);
     //   l=std::get<0>(out);
     //   r=std::get<1>(out);
     //   std::cout<<"l="<<l<<std::endl;
     //   std::cout<<"r="<<r<<std::endl;
     //   std::cout<<"max="<<std::get<2>(out)<<std::endl;
		std::cout<<std::get<2>(out)<<std::endl;
    }
    return 0;
}
            

