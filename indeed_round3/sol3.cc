#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<bitset>
#include<utility>
#include<cmath>
#include<ctime>

using namespace std;

double touch(vector<string> &board) {
    int R = board.size();
    int C = board[0].size();
    double ret = 0.0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++) {
            int curx = i;
            int cury = j;
            if(board[i][j] != '*')
                ret += 1.0;
            else
                continue;
            while(curx < R && cury < C ) {
                char ch = board[curx][cury];
                board[curx][cury] = '*';
                switch (ch) {
                case 'C':
                    curx++;
                    continue;
                case 'R':
                    cury++;
                    continue;
                default:
                    break;
                }
                break;
            }

        }
    return ret;
}









int main(int argc, char *argv[]) {
    int R, C;
    while(cin >> R >> C) {
        clock_t start = 0 , end = 0;
        start = clock();
        vector<string> board(R);
        for(int i = 0; i < R; i++)
            cin >> board[i];
        vector<pair<int, int>> puzzele;
        //int npuzzle=0;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(board[i][j] == '?') {
                    //npuzzle++;
                    puzzele.push_back(pair<int, int>(i, j));
                }

        double ret = 0;

        for(int k = 0; k < 1 << puzzele.size(); k++) {
            bitset<10> vec(k);
            vector<string> tmp = board;
            for(int j = 0; j < puzzele.size(); j++)
                if(vec.test(j))
                    tmp[puzzele[j].first][puzzele[j].second] = 'C';
                else
                    tmp[puzzele[j].first][puzzele[j].second] = 'R';

            /* for(int i=0;i<R;i++) */
            /* cout<<tmp[i]<<endl; */

            double r = touch(tmp);
            ret += r;
            /* cout<<"ret:"<<r<<endl; */
        }

        ret = ret / pow(2, puzzele.size());
        cout.precision(15);
        cout.setf(ios::fixed);
        cout << ret << endl;
        end = clock();
        cout << "elaspe time is:" << (end - start) << " miliseconds" << endl;


    }
    return 0;
}







