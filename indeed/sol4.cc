#include<iostream>
#include<cstdlib>

using namespace std;


int max[21][21][21][21]={0};
int areas[21][21]={0};
int choco[21][21]={0};

int main(int argc, char** argv){
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
                if(i==1||j==1)
                    if(i==1&&j==1)
                        areas[i][j]=choco[i][j];
                    else if(i==0)
                        areas[i][j]=areas[i][j-1]+choco[i][j];
                    else
                        areas[i][j]=areas[i-1][j]+choco[i][j];
                else
                    areas[i][j]=areas[i-1][j]+areas[i][j-1]-areas[i-1][j-1]+choco[i][j];

        for(int w=0;w<m;w++)
            for(int h=0;h<n;h++)
                for(int i=0;i<m-w;i++)
                    for(int j=0;j<n-h;j++){
                        if(w==0||h==0)
                            if(w==0&&h==0)
                                max[i][i+w][j][j+h]=0;
                            else if(w==0)
                                if(h==1)
                                    max[i][i+w][j][j+h]=choco[i][j]+choco[i][j+1];
                                else{
                                    int tmp=0;
                                    for(int k=0;k<h;k++)
                                        max[i][i+w][j][j+k]+max[i][i+w][j+k+1][j+h]+areas[


                                    
                        
    return 0;
}

