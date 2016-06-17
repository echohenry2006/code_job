#include<iostream>
#include<vector>
#include<bitset>



typedef std::vector<int> vec;
typedef std::vector<std::vector<int>>  int_matrix;


struct BTrieNode{
	int count; // num of leaves below this node
	BTrieNode* left;
	BTrieNode* right;
	BTrieNode(int in=0):count(in),left(nullptr),right(nullptr){};
};




class BTrie{
	public:
		BTrie();
		bool isEmpty();
		void insert(const vec &v);
		// insert a vector acording to the order of "order"
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
		void remove(BTrieNode* &p);
        vec max_count; // the max num of leaves below at each level
};


BTrie::BTrie():depth(0){
	root = new BTrieNode(0);

};


void BTrie::insert(const vec &a){
	if(depth==0)
		depth = a.size();
    if(max_count.size()!=depth)
        max_count.resize(depth,0);

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


bool BTrie::find(const vec &v){

    if(depth==0)
        return false;

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




std::vector<int> score(const int_matrix &mat, std::vector<int> &used){
    int p = mat.size();
    int n = mat[0].size();
    std::bitset<5> b_group;
    int size_group = (1<<used.size());
    std::vector<int> v_score(n);
    std::vector<int> v_pos_num(size_group);
    std::vector<int> v_tot_num(size_group);


    for(int i=0;i<n;i++){
        v_pos_num.assign(size_group,0);
        v_tot_num.assign(size_group,0);
        for(int j=0;j<p;j++)
        {
            b_group.reset();
            for(int k=0;k<used.size();k++)
                if(mat[j][used[k]]==1)b_group.set(k);
            int loc = (int)(b_group.to_ulong());
            v_pos_num[loc]= v_pos_num[loc]+mat[j][i];
            v_tot_num[loc]= v_tot_num[loc]+1;
        }

        for(int j=0;j<size_group;j++)
            v_score[i] += v_tot_num[j]-abs(2*v_pos_num[j]-v_tot_num[j]);

    }

    for(int i=0;i<used.size();i++)
        v_score[used[i]]=-1;

    return v_score;
}

int findmax(const std::vector<int> &v){
    int max=0;
    int loc=0;
    for(int i=0;i<v.size();i++)
        if(v[i]>max){
            max=v[i];
            loc=i;
        }
    return loc;
}

int min_pixels(const int_matrix &mat){
    int p= mat.size();

    if(p==2)
        return 1;
    if(p==3)
        return 2;
    int n=mat[0].size();
    std::vector<bool> used_flag(n,false);
    std::vector<int> order(n,0);

    for(int i=0;i<n;i++)order[i]=i;


    BTrie tree;

    bool finish = false;
    while(!finish){

        tree.clean();
        for(int i=0; i<p;i++)
            tree.insert(mat[i],order);



        finish = true;
        for(int i=n-1;i>=0;i--){
            if(tree.get_max_count(i)==2)
                if(!used_flag[order[i]]){
                    int tmp = order[i];
                    used_flag[order[i]]=true;
                    order.erase(order.begin()+i);
                    order.insert(order.begin(),tmp);
                    finish = false;
                    break;
                }
        }

    }




    int count=0;
    for(int i=0;i<n;i++)
        if(used_flag[i]){
            count++;
        //    std::cout<<"used "<<i<<std::endl;
        }
    return count;

}

int main(int argc , char** argv)
{
    int m,n,p;


    char ch;

    while(std::cin>>m>>n>>p){
		int_matrix mat(p,std::vector<int>(m*n));
        std::cin.get();

        for(int k=0;k<p;k++){
            std::cin.get();
            for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					ch= std::cin.get();
					mat[k][i*n+j]=(int)(ch-48);

				}
				std::cin.get();
			}


        }

		/*
        for(int i=0;i<p;i++){
            for(int j=0;j<m*n;j++)
                std::cout<<mat[i][j];
            std::cout<<std::endl;
        }


        std::cout<<std::endl;
        */

        std::cout<<min_pixels(mat)<<std::endl;
    }

    return 0;
}

