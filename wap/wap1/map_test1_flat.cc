#include<cstdlib>
#include<iostream>
#include<ctime>

#define MAX 2 

void generate_one_matrix(int N, int M){
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			std::cout<<std::rand()%MAX;
		}
	//	std::cout<<std::endl;
	}
	std::cout<<std::endl;
}
int main(int argc, char* argv[])
{

	srand(time(NULL));
	int n=atoi(argv[1]);
	int m = atoi(argv[2]);
	int p = atoi(argv[3]);
	for (int i =0; i<p ;i ++)
		generate_one_matrix(n,m);
	return 0;
}
