#include<string>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<string, std::vector<string>, std::greater<string>> s;
        for(int i=1;i<=n;i++)
            s.push(std::to_string(i));
        vector<int> ret;
        while(!s.empty()){
            ret.push_back(std::stoi(s.top()));
            s.pop();
        }
        return ret;
    }

    void print(vector<int> &v){
        for(auto & s:v)
            cout<<s<<"-"<<endl;
        
    }
};


class trietree{
    public: 
        trietree(int n );
        
}


int main(){
    Solution sol;
    vector<int> ret = sol.lexicalOrder(1000);
    sol.print(ret);
    return 0;

}