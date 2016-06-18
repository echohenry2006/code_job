#include<iostream>
#include<cstdlib>
#include<cassert>

#define MAXINT 0x7FFFFFFF
using namespace std;


int min_cost[21][21][21][21]={0};
int areas[21][21]={0};
int choco[21][21]={0};

int main(int argc, char** argv){
    //cout<<"MAXINT"<<MAXINT<<endl;
    int m,n;
    char ch;
    while(cin>>m>>n){
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                cin>>(ch);
                choco[i][j]=ch-'0';
            }

        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                    areas[i][j]=areas[i-1][j]+areas[i][j-1]-areas[i-1][j-1]+choco[i][j];
        /*    
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++)
                cout<<areas[i][j]<<",";
            cout<<endl;
        }
        */

        for(int d1=0;d1<21;d1++)
            for(int d2=0;d2<21;d2++)
                for(int d3=0;d3<21;d3++)
                    for(int d4=0;d4<21;d4++)
                        min_cost[d1][d2][d3][d3]=0;
        for(int w=0;w<m;w++)
            for(int h=0;h<n;h++)
                for(int i=1;i<=m-w;i++)
                    for(int j=1;j<=n-h;j++){
                            if(w==0 && h==0)break;
                            int tmp_min=MAXINT;
                            int total=areas[i+w][j+h]-areas[i-1][j+h]-areas[i+w][j-1]+areas[i-1][j-1];
                           /* 
                            cout<<"w="<<w<<" h="<<h<<endl;
                            cout<<"i="<<i<<" j="<<j<<endl;
                            cout<<"total="<<total<<endl;
                            cout<<endl;
                            */

                            for(int k=0;k<w;k++){
                                int tt=min_cost[i][j][i+k][j+h]+min_cost[i+k+1][j][i+w][j+h];
                                if(tt<tmp_min)tmp_min=tt;
                            }
                            for(int k=0;k<h;k++){
                                int tt=min_cost[i][j][i+w][j+k]+min_cost[i][j+k+1][i+w][j+h];
                                if(tt<tmp_min)tmp_min=tt;
                            }
                            min_cost[i][j][i+w][j+h]=tmp_min+total;
                            /*
                            cout<<endl;
                            cout<<"w="<<w<<" h="<<h<<endl;
                            cout<<"i="<<i<<" j="<<j<<endl;
                            cout<<"total="<<total<<endl;
                            cout<<"tmp="<<tmp_min<<endl;
                            cout<<endl;
                            */
                    }


        cout<<min_cost[1][1][m][n]<<endl;
        //cout<<min_cost[1][1][1][1]<<endl;
        //cout<<min_cost[1][1][1][2]<<endl;
    }
    return 0;
}

