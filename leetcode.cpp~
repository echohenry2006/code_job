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
	string reverseVowels(string s){
		set<char> vowel{'a','e','i','o','u'};
		queue<char> q;
		stack<char> st;
		vector<char> out;
		for (auto ch : s){
			cout<<ch<<endl;
			if(vowel.find(ch)!=vowel.end()){
				q.push('@');
				st.push(ch);
			}
			else{
				q.push(ch);
			}

		}

		char cc;

		while(!q.empty()){
			cc= q.front();
			q.pop();
			if(cc=='@'){

				out.push_back(st.top());
				st.pop();
			}
			else

				out.push_back(cc);
		}
		return string(out.begin(),out.end());

	}
};


int main(int argc , char** argv)
{
	assert(argc==2);
	Solution sol;
	string s = sol.reverseVowels(string(argv[1]));
	cout<<s<<endl;
	return 0;
}
