#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<cassert>
using namespace std;

class Solution {
  private:
    vector<int> res;
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        vector<int> in(numCourses,0);
        vector<int> vis(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].first].insert(prerequisites[i].second);

            in[prerequisites[i].second]++;

        }

        for(int it = 0; it < numCourses; it++){
            if(in[it] == 0){
              //  cout<<"in "<<it<<" is "<<in[it]<<endl;
                dfs(graph, in, vis, it );
            }
        }

        /* if(res.size()==numCourses) */
            /* return res; */
        /* else */
            /* return {}; */
        return res;


    }

    void dfs(unordered_map<int, unordered_set<int>> &graph, vector<int> &in, vector<int> &vis, int cur) {
        /* if(!vis[cur] && graph.find(cur) == graph.end()) { */
            //cout<<"not found "<<cur<<endl;
            /* res.push_back(cur); */
            /* vis[cur] = true; */
            /* return ; */
        /* } */
        cout<<"###"<<cur<<endl;
        if(vis[cur]==2)return ;
        if(vis[cur]==1){vis[cur]=2;return;}
        vis[cur]=1;
        while(!graph[cur].empty()){
            dfs(graph, in, vis,*graph[cur].begin());
            graph[cur].erase(graph[cur].begin());
        }
        if(vis[cur]==1){
            res.push_back(cur);
            vis[cur]=2;
        }
        /* cout<<"push back"<<cur<<endl; */
        return ;


    }
};


int main(int argc , char** argv) {
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2},{0,1}};
    Solution sol;
    vector<int> res = sol.findOrder(4, prerequisites);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << "---";
    cout << endl;
    return 0;

}





