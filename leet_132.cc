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
    int minCut(string s){
        int n=0;
        int offset=0;
        while(offset=lastCut(s)){
            n++;
            s=s.substr(0,offset);
        }
        return n;
            
    };

    int lastCut(string &s){
        string::iterator it=s.begin();
        string::iterator rit=s.end()-1;
        while(it!=s.end()){
            if(isPal(s,it,rit))break;
            cout<<"++"<<endl;
            it++;
        }
        return it-s.begin();
    }

    bool isPal(string &s, string::iterator it, string::iterator rit){
        while(it<rit)
            if(*it==*rit){
                it++;
                rit--;
            }
            else
                return false;
        return true;
    }


};


int main(int argc , char** argv)
{
    string s("aaabbaa");
    Solution sol;
    if(sol.isPal(s,s.begin(),s.end()-1))
        cout<<"YES!!"<<endl;
    cout<<sol.lastCut(s)<<endl;;
    return 0;
}

