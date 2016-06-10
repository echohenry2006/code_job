#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cassert>
using namespace std;

class Solution{
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        while(i<nums.size()){
            if(nums[i]!=0)
                if(i==j)
                    j++;
                else
                    swap(nums[i],nums[j++]);
        i++;
                    
    }
};


int main(int argc , char** argv)
{
    vector<int> nums={4,2,4,0,0,3,0,5,1,0};
    
    Solution sol;
    sol.moveZeroes(nums);
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;

}

