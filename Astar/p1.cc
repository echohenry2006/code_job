#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

typedef long long ll;

int smallmod(int x, ll m, int k){
	int rem=0;
	
	if(x==10) return ( (int)(pow(10.0,m)) )%k;
	for(int i=0;i<m;i++){
		//cout<<(int)(pow(10,i))<<endl;
		rem = rem + ( x*(int)(pow(10,i)) )%k;
	}
		
	
	rem = rem %k;
	return rem;
}
		
		
int bigmod(int x , ll m , int k){
	
	if(m<=4)
		
		return smallmod(x,m,k);
	
	
	ll left=m/2;
	ll right=m-m/2;


	
	return (bigmod(x,left,k)*bigmod(10,right,k)+bigmod(x,right,k))%k;
}
		
		
		
		

int main(int argc, char** argv){
    int n_case;
    int x;
    int k,c;
	long long m;
    while(cin>>n_case){
        for(int i=0;i<n_case;i++){
            cin>>x>>m>>k>>c;

           
            
            int ret = bigmod(x,m,k);
           

            
            cout<<"Case #"<<i+1<<":"<<endl;
            if(ret==c)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }

    }
    return 0;
}
