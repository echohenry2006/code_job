#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cassert>
#include<utility>
#include<algorithm>
using namespace std;

class Solution{
public:
    typedef pair<int,int> loc;
    void solve(vector<vector<char>>& board){
		if(board.empty())return;
        int m,n;
        m = board.size();
		if(m < 3)  
            return;  
        n = board[0].size();
		if(n < 3)  
            return;  
        int i,j;
        
        queue<loc> q;
		i=0;
        for(j=0;j<n;j++)
            if(board[i][j]=='O')
                search(i,j,m,n,q,board);
        i=m-1;
        for(j=0;j<n;j++)
            if(board[i][j]=='O')
                search(i,j,m,n,q,board);

        j=0;
        for(i=0;i<m;i++)
            if(board[i][j]=='O')
                search(i,j,m,n,q,board);
        j=n-1;
        for(i=0;i<m;i++)
            if(board[i][j]=='O')
                search(i,j,m,n,q,board);
			
	
        


        for (i=0;i<m;i++)
            for(j=0;j<n;j++){
                board[i][j]=='O'?board[i][j]='X':1;
                board[i][j]=='p'?board[i][j]='O':1;
            }
			
		
    
    }

    void search(int a, int b, int m, int n, queue<loc> &q, vector<vector<char>>& board){
        assert(q.empty());
        q.push(loc(a,b));
        board[a][b]='p';
        loc cur_loc;
        while(!q.empty()){
            cur_loc=q.front();
            
            q.pop();
            if(cur_loc.first-1>0 && board[cur_loc.first-1][cur_loc.second]=='O'){
                q.push(loc(cur_loc.first-1,cur_loc.second));
                board[cur_loc.first-1][cur_loc.second]='p';
            }//up
            if(cur_loc.first+1<m && board[cur_loc.first+1][cur_loc.second]=='O'){
                q.push(loc(cur_loc.first+1,cur_loc.second));
                board[cur_loc.first+1][cur_loc.second]='p';
            }//down
            if(cur_loc.second-1>0 && board[cur_loc.first][cur_loc.second-1]=='O'){
                q.push(loc(cur_loc.first,cur_loc.second-1));
                board[cur_loc.first][cur_loc.second-1]='p';
            }//left
            if(cur_loc.second+1<n && board[cur_loc.first][cur_loc.second+1]=='O'){
                q.push(loc(cur_loc.first,cur_loc.second+1));
                board[cur_loc.first][cur_loc.second+1]='p';
            }//right
        }
    }


};


int main(int argc , char** argv)
{
    int m,n;
    while(cin>>m>>n){
        vector<vector<char>> board(m, vector<char>(n));
        for(int i=0;i<m;i++)
            for( int j=0 ; j<n; j++)
                cin>>board[i][j];
			


    Solution sol;
    sol.solve(board);
	
	
	for( int i=0;i<m;i++){
			for( int j=0;j<m;j++)
				cout<<board[i][j]<<" ";
        cout<<endl;
        }
	}
    

    return 0;

}
