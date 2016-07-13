#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<bitset>
#include<utility>
#include<cmath>
#include<ctime>

using namespace std;


int rain(vector<vector<int>> &land) {
    int flag = 0;
    int min_h = 9999;
    int R = land.size();
    int C = land[0].size();
    int loc[2];


    vector<pair<int, int>> center;
    for(int i = 1; i < R - 1; i++)
        for(int j = 1; j < C - 1; j++)
            if(land[i - 1][j] >= land[i][j] && land[i][j - 1] >= land[i][j] && land[i + 1][j] >= land[i][j] && land[i][j + 1] >= land[i][j])
                center.push_back(pair<int, int>(i, j));
    int sh = 9999;
    for(int i = 0; i < center.size(); i++) {
        sh = 9999;
        queue<pair<int, int>> locs;
        loc[0] = center[i].first;
        loc[1] = center[i].second;
        min_h = land[loc[0]][loc[1]];
        locs.push(pair<int, int>(loc[0], loc[1]));
        set<pair<int, int>> iland;
        while(!locs.empty()) {
            if(iland.find(locs.front()) != iland.end()) {
                locs.pop();
                continue;
            }
            iland.insert(locs.front());
            loc[0] = locs.front().first;
            loc[1] = locs.front().second;
            locs.pop();
            if(loc[0] - 1 > 0) { // inner
                int tmph = land[loc[0] - 1][loc[1]];
                if(tmph == min_h) {
                    locs.push(pair<int, int>(loc[0] - 1, loc[1]));
                }
                if(tmph < min_h) {
                    iland.clear();
                    break;
                }
                if(tmph > min_h)
                    if(tmph < sh)
                        sh = tmph;
            } else {
                int tmph = land[loc[0] - 1][loc[1]];
                if(tmph <= min_h) {
                    iland.clear();
                    break;
                } else if(tmph < sh)sh = tmph;

            }
            if(loc[0] + 1 < R - 1) { // right
                int tmph = land[loc[0] + 1][loc[1]];
                if(tmph == min_h) {
                    locs.push(pair<int, int>(loc[0] + 1, loc[1]));
                } //
                if(tmph < min_h) {
                    iland.clear();
                    break;
                }
                if(tmph > min_h)
                    if(tmph < sh)
                        sh = tmph;
            } else {
                int tmph = land[loc[0] + 1][loc[1]];
                if(tmph <= min_h) {
                    iland.clear();
                    break;
                } else if(tmph < sh)sh = tmph;

            }
            if(loc[1] - 1 > 0) { // up
                int tmph = land[loc[0]][loc[1] - 1 ];
                if(tmph == min_h) {
                    locs.push(pair<int, int>(loc[0], loc[1] - 1));
                } //
                if(tmph < min_h) {
                    iland.clear();
                    break;
                }
                if(tmph > min_h)
                    if(tmph < sh)
                        sh = tmph;
            } else {
                int tmph = land[loc[0]][loc[1] - 1];
                if(tmph <= min_h) {
                    iland.clear();
                    break;
                } else if(tmph < sh)sh = tmph;

            }
            if(loc[1] + 1 < C - 1) { // inner
                int tmph = land[loc[0]][loc[1] + 1];
                if(tmph == min_h) {
                    locs.push(pair<int, int>(loc[0], loc[1] + 1));
                } //
            } else {
                int tmph = land[loc[0]][loc[1] + 1];
                if(tmph <= min_h) {
                    iland.clear();
                    break;
                } else if(tmph < sh)sh = tmph;

            }
        }
        for(set<pair<int, int>>::iterator it = iland.begin(); it != iland.end(); ++it) {
            land[it->first][it->second] = sh;
            flag = 1;
        }
    }

    return flag;



}

int main(int argc, char *argv[]) {
    int T;
    int R, C;

    cin >> T;
    for(int ncase = 0; ncase < T; ncase++) {
        cin >> R >> C;
        vector<vector<int>> land(R, vector<int>(C));
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                cin >> land[i][j];
        vector<vector<int>> land2 = land;
        while(rain(land2)) {
            /* cout << "************" << endl; */
            /* for(int i = 0; i < R; i++) { */
                /* for(int j = 0; j < C; j++) */
                    /* cout << land2[i][j] << " " ; */
                /* cout << endl; */
            /* } */
        }

        long long ret = 0;
        for(int i = 0; i < R; i++)
            for (int j = 0 ; j < C ; j++)
                ret += land2[i][j] - land[i][j];
        cout << "Case #" << ncase + 1 << ": " << ret << endl;

    }


    return 0;
}










