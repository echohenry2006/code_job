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
    int largestRectangleArea(vector<int>& heights) {
		if(heights.empty())return 0;
        stack<int> sta;
        int n=heights.size();
        int cur_h;
        int max=0;
		int top;
        int top2;
        for(int i=0;i<n;i++){
            cur_h=heights[i];
            if(sta.empty() || heights[sta.top()]<=cur_h)
                sta.push(i);
            else{
                while(!sta.empty() && heights[sta.top()]>cur_h){
					top=sta.top();
                    sta.pop();
                    
                    int tmp=heights[top]*(i-top);
                    
                    if(tmp>max)max=tmp;
                }
                sta.push(i);
            }
        }
        while(!sta.empty()){
			top=sta.top();
            int tmp=heights[top]*(n-top);
            if(tmp>max) max=tmp;
            sta.pop();
			

        }
       // cout<<"top is" <<top<<endl;
		if(heights[top]*n>max)max=heights[top]*n;
        return max;



    }
};


int main(int argc , char** argv)
{
    // [2,1,5,6,2,3]
    // 10
    int n;
    vector<int> heights;
    int h;
    while(cin>>n){
        heights.clear();
        for(int i=0;i<n;i++){
            cin>>h;
            heights.push_back(h);
        }
        Solution sol;
        cout<<sol.largestRectangleArea(heights)<<endl;;
    }
    return 0;
}

