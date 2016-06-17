#include<iostream>
#include<string>
#include<vector>

using namespace std;


int max_sum(const vector<int> &vec, int &begin, int &end){
    int max;
    int cur_sum;
    cur_sum=vec[0];
    max=vec[0];
    int newbegin=0;
    begin=0;
    end=0;
    for(int i=1;i<vec.size();i++){
        if(cur_sum<0){
            cur_sum=0;
            newbegin=i;
        }
        cur_sum+=vec[i];
        if(cur_sum>max){
            max=cur_sum;
            begin=newbegin;
            end=i;
        }
    }
    return maxSum;
}


int main(int argc,char** argv){
    vector<int> v={-4,-2,-1,0};
    int b;
    int e;
    cout<<max_sum(v,b,e)<<endl;;
    return 0;
   
} 
