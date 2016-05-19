#include<cstdlib>
#include<iostream>
#include<ctime>
#include<vector>

#include<./BTrie.cc>

#define MAX 2 

void generate_one_matrix(int N, int M,int P){
    BTrie bt;
    std::vector<int> v(M*N);
    std::vector<std::vector<int>> mat(P,std::vector<int>(M*N));
	for (int i=0;i<P;){
		for (int j=0;j<M*N;j++){
			v[j] = std::rand()%MAX ;
        }

        if(bt.find(v))
            continue;
        else{

            bt.insert(v);
            mat[i]=v;
            i++;
        }

	}
    for (int k=0;k<P;k++){
        for (int i=0;i<N;i++){
            for(int j=0; j<M;j++)
                std::cout<<mat[k][i*M+j];
            #ifndef FLAT
		    std::cout<<std::endl;
            #endif
        }
	std::cout<<std::endl;
    }
}
int main(int argc, char* argv[])
{

	srand(time(NULL));
	int n=atoi(argv[1]);
	int m = atoi(argv[2]);
	int p = atoi(argv[3]);


	//std::cout<<"n: "<<n<<" m: "<<m<<" p: "<<p<<std::endl;
	std::cout<<n<<" "<<m<<" "<<p<<std::endl;
    generate_one_matrix(n,m,p);
    
	return 0;
}
