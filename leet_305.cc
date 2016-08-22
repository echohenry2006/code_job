#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cassert>
using namespace std;

class UnionFind2D {
  public:
    UnionFind2D(int m, int n): M(m), N(n), cnt(0) {
        parent.resize(m * n);
        height.resize(m * n);
        fill(parent.begin(), parent.end(), -1);
        fill(height.begin(), height.end(), 0);
    };
    void Union(int x, int y);
    int  Find(int x);
    void add(pair<int, int> pos);
    int count() {
        return cnt;
    };
  private:
    int M;
    int N;
    vector<int> parent;
    vector<int> height;
    int cnt;
};


int UnionFind2D::Find(int x) {
    if(parent[x] == -1)return -1;
    if(parent[x] == x)return x;
    return Find(parent[x]);
}

void UnionFind2D::Union(int x, int y) {
    int xp = Find(x);
    int yp = Find(y);
    assert(xp >= 0 && yp >= 0);
    if(xp == yp)return ;
    if(height[yp] < height[xp])swap(xp, yp);
    parent[xp] = yp;
    height[yp] = max(height[yp], height[xp] + 1);
    return ;
}


void UnionFind2D::add(pair<int, int> pos) {

    int x = pos.first;
    int y = pos.second;
    assert(x >= 0 && x < M);
    assert(y >= 0 && y < N);
    int index = x * N + y;
    if(parent[index] > 0)return;
    cnt++;
    parent[index] = index;
    height[index] = 1;

    int index2 = (x - 1) * M + y;
    if(x - 1 >= 0 && parent[index2] != -1) {
        Union(index, index2);
        cnt--;
    }

    index2 = (x + 1) * M + y;
    if(x + 1 < M && parent[index2] != -1) {
        Union(index, index2);
        cnt--;
    }
    index2 = x * M + y - 1;
    if(y - 1 >= 0 && parent[index2] != -1) {
        Union(index, index2);
        cnt--;
    }
    index2 = x * M + y + 1;
    if(y + 1 < N && parent[index2] != -1) {
        Union(index, index2);
        cnt--;
    }
    return ;


}


class Solution {
  public:
    vector<int> numIsland2(int m, int n, vector<pair<int, int>>& positons) {
        vector<int> ret;
        UnionFind2D island(m, n);
        for(auto& pos : positons) {
            island.add(pos);
            ret.push_back(island.count());
        }
        return ret;
    }
};

int main() {

    vector<int> ret ;
    Solution sol;
    int m = 3, n = 3;
    vector<pair<int, int>> opers = {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
    ret = sol.numIsland2(3, 3, opers);
    for(auto s : ret)
        cout << s << endl;
    return 0;

}

