#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <set>
#include <vector>
#include <queue>

using namespace std;



const int N=105;
const int mod=1000000007;


int a[N];
int n;

double cal(double R)
{
    double ans=1;
    double sum=0;
    for(int i=0;i<=n;i++)
    {
        sum+=ans*a[i];
        ans*=R;
    }
    return sum;
}

void Deal()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&a[n-i]);
    }
    a[n]=-a[n];
    double low=0,high=2;

    for(int i=0;i<200;i++)
    {
        double Mid=(low+high)*0.5;


        if(cal(Mid)<0) high=Mid;
        else low=Mid;
    }

    double ans=(low+high)*0.5-1;

    printf("%.11f\n",ans);
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("ans","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        printf("Case #%d: ",i);
        Deal();
    }
}
/**
3
3
10000 3000 4000 5000
5
3000 100 100 100 100 100
*/
