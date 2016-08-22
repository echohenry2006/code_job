#ifndef __UnionFindSet__
#define __UnionFindSet__
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

class UnionFindSet {
    
    UnionFindSet(int n):size(n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            height[i]=1;
        }
        
    };
    int Find(int x);
    void Union(int x, int y);

  private:
    int size;
    vector<int> parent;
    vector<int> height;

};


int UnionFindSet::Find(int x){
    assert(x>=0 && x<size);
    if(parent[x]==x)
        return x;
    else
        return Find(parent[x]);
}


void UnionFindSet::Union(int x ,int y){
    int xp=Find(x);
    int yp=Find(y);
    if(xp==yp)return ;
    if(height[yp]<height[xp])swap(xp,yp);
    parent[xp]=yp;
    height[yp]=max(height[yp],height[xp]+1);
    return ;
}


#endif /* ifndef __UnionFindSet__ */


