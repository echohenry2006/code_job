#include<cstdlib>
#include<iostream>
#include<ctime>
#include<vector>

typedef unsigned long long bigint;

#define MAX (bigint)(1000000000000) 

void generate_sample(const &k){
    std::vector<bigint> v(k);
	for (int i=0;i<k;i++)
			v[i] = std::rand()%MAX ;
    for (int i=0;i<k;i++){
            std::cout<<v[i];
            if(i==k-1)
                std::cout<<std::endl;
            else
                std::cout<<" ";
    }
}
int main(int argc, char* argv[])
{

	srand(time(NULL));
	int n=atoi(argv[1]);


	//std::cout<<"n: "<<n<<" m: "<<m<<" p: "<<p<<std::endl;
	std::cout<<n<<std::endl;
    generate_sample(n);
    
	return 0;
}
