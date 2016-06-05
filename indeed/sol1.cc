#include<iostream>
#include<vector>
#include<cassert>
#include<cmath>
#include<bitset>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

set<string> permute_str(string str){
    int len=str.length();
    set<string> vec;
    if(len==1)
        vec.insert(str);
    else if(len==2){
        vec.insert(str);
        swap(str[0],str[1]);
        vec.insert(str);
    }
    else if(len==3){
        vec.insert(str);
        swap(str[1],str[2]);
        vec.insert(str);
        swap(str[0],str[2]);
        vec.insert(str);
        swap(str[1],str[2]);
        vec.insert(str);
        swap(str[0],str[2]);
        vec.insert(str);
        swap(str[1],str[2]);
        vec.insert(str);
    }
    return vec;
}



int main(int argc , char** argv)
{
    string str;
    while(cin>>str){
        char ch[5]={'a','b','c','d'};
        int len;
        len=str.length();
        string outstr(str);
        sort(outstr.begin(),outstr.end());
        //cout<<outstr<<endl;
        set<string> sets;
        for(int i=0;i<len;i++){
            for(int j=0;j<4;j++){
                string str2(str);
                str2[i]=ch[j];

                sort(str2.begin(),str2.end());
                sets.insert(str2);
                //cout<<sets.size()<<"###"<<str2<<endl;
                
            }
        }
            //cout<<endl;
        priority_queue<string,vector<string>,greater<string> > q;

        set<string>::iterator it1;
        set<string>::iterator it2;
        set<string> set2;
        for(it1=sets.begin();it1!=sets.end();++it1){
            set2=permute_str(*it1);
            for(it2=set2.begin();it2!=set2.end();++it2)
                q.push(*it2);
        }

        while(!q.empty()){
            string sss=q.top();
            cout<<sss<<endl;
            q.pop();
        }
            
        




    }

    return 0;
}

