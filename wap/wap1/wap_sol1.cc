#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>
#include<cmath>
#include<bitset>
#include<algorithm>
#include<BTrie.cc>
typedef std::vector<std::vector<int>>  int_matrix;


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
            v_score[i] = v_score[i]+v_tot_num[j]-abs(2*v_pos_num[j]-v_tot_num[j]);
        
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
    
    int p=mat.size();
    int n=mat[0].size();
    
    std::vector<bool> used_flag(n,false);
    std::vector<int> used;
    std::vector<int> order(n,0);

    for(int i=0;i<n;i++)order[i]=i;

    
    BTrie tree;

    bool finish = false;
    while(!finish){
        //std::cout<<"TEST"<<std::endl;
        tree.clean();
        for(int i=0; i<p;i++)
            tree.insert(mat[i],order);
        
        #ifdef DEBUG 
        for(int i=0; i<n;i++)
            std::cout<<"##"<<tree.get_max_count(i)<<std::endl;
        #endif

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
            std::cout<<"used "<<i<<std::endl;
        }
    return count;
    std::cout<<"count is"<<count<<std::endl;
}

            

#ifdef OLD_WAY
int min_pixels(const int_matrix &mat){
    int p=mat.size();
    int n=mat[0].size();
    
    std::vector<int> used;
    
    std::vector<int> s=score(mat,used);
    for(int i=0;i<n;i++)
        std::cout<<s[i];
    std::cout<<std::endl;
    
    
    int max;
    max=findmax(s);
    std::cout<<"max is " << max<<std::endl;
    used.push_back(max);
    s=score(mat,used);
    for(int i=0;i<n;i++)
        std::cout<<s[i];
    std::cout<<std::endl;

    max=findmax(s);
    std::cout<<"max is " << max<<std::endl;
    used.push_back(max);
    s=score(mat,used);
    for(int i=0;i<n;i++)
        std::cout<<s[i];
    std::cout<<std::endl;
    
    max=findmax(s);
    std::cout<<"max is " << max<<std::endl;
    used.push_back(max);
    s=score(mat,used);
    for(int i=0;i<n;i++)
        std::cout<<s[i];
    std::cout<<std::endl;
    
    max=findmax(s);
    std::cout<<"max is " << max<<std::endl;
    used.push_back(max);
    s=score(mat,used);
    for(int i=0;i<n;i++)
        std::cout<<s[i];
    std::cout<<std::endl;

    return 0;
}

#endif



int main(int argc , char** argv)
{
    int m,n,p;
    
    //std::ifstream myfile("test.txt",std::ios::in);


    //assert(myfile);
    char ch;

    while(std::cin>>m>>n>>p){
        std::cin.get();
        int_matrix mat(p,std::vector<int>(m*n));
        for(int i=0;i<p;i++){
            //std::cin.get();
            for(int j=0;j<m*n;j++){
                ch= std::cin.get();
               mat[i][j]=(int)(ch-48);
          //     std::cout<<myfile.get();
          //     
            }
            std::cin.get();
        }
        for(int i=0;i<p;i++){
            for(int j=0;j<m*n;j++)
                std::cout<<mat[i][j];
            std::cout<<std::endl;
        }

        std::cout<<std::endl;
        

        std::cout<<min_pixels(mat)<<std::endl;
    }
    //myfile.close();

    return 0;
}

