#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cassert>
#include<cctype>
using namespace std;



int main(int argc , char** argv)
{
    string str="9,3,4,#,#,1,#,#,2,#,6,#,#";
    
    
    stack<char> s;
    for(int i=str.size()-1;i>=0;i--){
        char ch=str[i];
        if(ch==',')
            continue;
        if(ch=='#')
            s.push(ch);
        if(isdigit(ch)){
            if(s.empty()){
                cout<<"invalid!!"<<endl;
                break;
            }
            if(s.top()=='#')
                s.pop();
            else{
                cout<<"invalid!!"<<endl;
                break;
            }
            if(s.top()=='#')
                s.pop();
            else{
                cout<<"invalid!!"<<endl;
                break;
            }
            s.push('#');
        }
        
    }
    //cout<<s.size()<<s.top()<<endl;
    if(s.size()==1&&s.top()=='#')
        cout<<"valid!!"<<endl;
    else
        cout<<"invalid"<<endl;

    return 0;

}

