// This code showed some mistaken use of pointer
// function set is right, set2 is wrong
#include<iostream>
#include<cassert>

void set(int* &p){
	if(p!=NULL)delete p;
	p=NULL;
}
void set2(int* p){
	if(p!=NULL)delete p;
	p=NULL;
}

int main(int argn , char** argv)
{
	int* p=new int;
	p[0]=1;
	set2(p);
	assert(p==NULL);
	return 0;
}
