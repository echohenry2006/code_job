#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        vector<string> res;
        unordered_map<string, multiset<string> > m;
        for (auto a : tickets) {
            m[a.first].insert(a.second);
        }
        dfs(m, "JFK", res);
        return vector<string> (res.rbegin(), res.rend());
    }
    void dfs(unordered_map<string, multiset<string> > &m, string s, vector<string> &res) {
		cout<<"from "<<s<<endl;
		multiset<string>::iterator it;
		for(it=m[s].begin();it!=m[s].end();++it)
			cout<<*it<<"---";
		cout<<endl;
        while (m[s].size()) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(m, t, res);
        }
        res.push_back(s);
		cout<<s<<endl;
    }
};

int main(){
	vector<pair<string, string> > tickets;
	tickets.push_back(pair<string, string>("JFK","ATL"));
	tickets.push_back(pair<string, string>("JFK","SFO"));
	tickets.push_back(pair<string, string>("ATL","SFO"));
	tickets.push_back(pair<string, string>("SFO","ATL"));
	tickets.push_back(pair<string, string>("SFO","JFK"));
	Solution sol;
	sol.findItinerary(tickets);
	return 0;
}


