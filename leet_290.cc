#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cassert>
#include<iterator>
#include<sstream>
#include<unordered_map>
using namespace std;

class Solution{
public:
    typedef unordered_map<char,string> stringmap;
    bool wordPattern(string pattern, string str) {
        vector<string> v;
        istringstream in(str);
        copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(v));
        if(pattern.size()!=v.size())return false;
        //ostream_iterator<string> output(cout , "**" );
        //copy(v.begin(),v.end(),output);
        //cout<<pattern.size()<<endl;
        //cout<<v.size()<<endl;
        stringmap s1;
        unordered_map<string,char> s2;
        for(int i=0;i<v.size();i++){
            if(s1.find(pattern[i])==s1.end() )s1.insert(pair<char,string>(pattern[i],v[i]));
            else 
                if(s1[pattern[i]]!=v[i])
                    return false;
            if(s2.find(v[i])==s2.end() )s2.insert(pair<string,char>(v[i],pattern[i]));
            else 
                if(s2[v[i]]!=pattern[i])
                    return false;
        }
        return true;
        
    }
};


int main(int argc , char** argv)
{
    string pattern("abba");
    string str("dog cat cat dog");
    Solution sol;
    if(sol.wordPattern(pattern,str))cout<<"YES"<<endl;
    return 0;

}
