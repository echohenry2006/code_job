#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>

using namespace std;
int  pp(string s1,string s2){
   int diff=abs(atoi(s2.c_str())-atoi(s1.c_str()));
   cout<<s1<<" - "<<s2<<" = "<<diff<< endl; 
    return diff;
}

int strtoint(string s){
    return (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+s[3]-'0';
}

string inttostr(int n){
    std::stringstream ss;
	std::string str;
	ss<<n;
	ss>>str;
    return str;
}

int main(){
    string s;
    string s1,s2;
    char tmp[5];
    cin>>s;
    if(s[0]==s[1] && s[0]==s[2] && s[0]==s[3])
        pp(s,s);
    else{
        while(s!="6174"){
        	s1=s;
        	sort(s1.begin(),s1.end());
        	s2=s1;
            reverse(s2.begin(),s2.end());
        	int diff=pp(s2,s1);
        	s=inttostr(diff);
            //cout<<s<<endl;
            //s=string(tmp);
        }
        
    }
    return 0;
    
}