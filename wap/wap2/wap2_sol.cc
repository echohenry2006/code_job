#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>
#include<cmath>
#include<bitset>
#include<algorithm>
#include<xortrie.cc>
#include<tuple>


typedef unsigned long long bigint;
typedef std::bitset<40> bitvec;

std::tuple<int,int,bigint> max_xor(const std::vector<bigint> &vec){
    int n = vec.size();
    assert(n>0);

    std::vector<bigint> pre_xor(n+1);
    std::vector<bigint> suf_xor(n+1);
    
    pre_xor[0]=0;
    suf_xor[n]=0;
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
        std::vector<bigint> in(N);
        for(int i=0;i<N;i++)
            std::cin>>in[i];
        

        std::tuple<int,int,bigint> out=max_xor(in);
        l=std::get<0>(out);
        r=std::get<1>(out);
        assert(l<r);
        std::cout<<"l="<<l<<std::endl;
        std::cout<<"r="<<r<<std::endl;
        std::cout<<"max="<<std::get<2>(out)<<std::endl;
    }
    return 0;
}
            

