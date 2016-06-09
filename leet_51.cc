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
    vector<vector<string> > solveNQueens(int n){
        vector<vector<string> > ret;
        vector<int> state(n,0);
        string str(n,'.');
        vector<string> board(n,str);
        int cur_row=0;
        int cur_col=0;
        while(state[0]<n){
            //cout<<cur_row<<endl;
            cur_col=state[cur_row];
            if(cur_col==n){
                state[cur_row]=0;
                state[--cur_row]++;
                continue;
            }
            fill(board[cur_row].begin(),board[cur_row].end(),'.');
            //cout<<"check point!!"<<endl;
            if(canDown(cur_row,cur_col,board)){
                board[cur_row][cur_col]='Q';
                cur_row++;
                if(cur_row==n){
                    //cout<<"success!!"<<endl;//success!!
                    state[--cur_row]=n;
                    ret.push_back(board);
                    //for(int i=0;i<n;i++)
                        //cout<<board[i]<<endl;
                }
            }
            else
                state[cur_row]++;
        }

        return ret;
            

    }

    bool canDown(int cur_row, int cur_col, vector<string> &board){
        //check 
        int size=board.front().size();
        for(int i=0;i<cur_row;i++)
            if(board[i][cur_col]=='Q')return false;
        int m=cur_row;
        int n=cur_col;
        while(m>0 && n>0)
            if(board[--m][--n]=='Q')return false;
        m=cur_row;
        n=cur_col;
        while(m>0 && n<(size-1))
            if(board[--m][++n]=='Q')return false;
        return true;
    }
            


};


int main(int argc , char** argv)
{
    int n;
    
    Solution sol;
    while(cin>>n){
        vector<vector<string> > ret=sol.solveNQueens(n);
        cout<<ret.size()<<endl;
    }

    return 0;
}

