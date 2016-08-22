#include<iostream>
#include<bitset>
#include<vector>
#include<queue>
#include<functional>

using namespace std;


int main() {
    int N;
    while(cin >> N) {
        vector<int> a(N);
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < N; i++) {
            cin >> a[i];
            q.push(a[i]);
        }
        vector<int> ret;
        ret.push_back(q.top());
        q.pop();
        queue<int> remain;
        while(!q.empty()) {

            if(!remain.empty() && remain.front() != ret.back()) {
                ret.push_back(remain.front());
                remain.pop();
                continue;
            }

            int tp = q.top();
            q.pop();
            if(tp == ret.back()) {
                //int k;
               // for(k = ret.size() - 3; k >= 0; k--)
                 //   if(ret[k] != tp && ret[k + 1] != tp) {
                 //       ret.insert(ret.begin() + k +1, tp);
                 //       break;
                 //   }
                if(k < 0)
                    remain.push(tp);
            } else
                ret.push_back(tp);
        }



        while(!remain.empty()) {
            int tp = remain.front();
            if(tp != ret.back()) {
                ret.push_back(tp);
                remain.pop();
            } else{
                int k;
                for(k = ret.size() - 3; k >= 0; k--)
                    if(ret[k] != tp && ret[k + 1] != tp) {
                        ret.insert(ret.begin() + k +1, tp);
                        remain.pop();
                        break;
                    }
                if(k < 0)
                    break;
            }
               

        }
        if(!remain.empty())
            cout << -1 << endl;
        else {
            for(int i = 0; i < N - 1; i++)
                cout << ret[i] << " ";
            cout << ret[N - 1] << endl;
        }





    }
    return 0;

}


