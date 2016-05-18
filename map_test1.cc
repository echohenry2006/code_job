#include<cstdlib>
#include<iostream>
#include<ctime>
#include<vector>
#define MAX 2 

void generate_one_matrix(int N, int M){
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			std::cout<<std::rand()%MAX;
		}
#ifndef FLAT
		std::cout<<std::endl;
#endif
	}
	std::cout<<std::endl;
}
int main(int argc, char* argv[])
{

	srand(time(NULL));
	int n=atoi(argv[1]);
	int m = atoi(argv[2]);
	int p = atoi(argv[3]);


	std::cout<<"n: "<<n<<" m: "<<m<<" p: "<<p<<std::endl;
	for (int i =0; i<p ;i ++)
		generate_one_matrix(n,m);
	return 0;
}
