#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
int main(){
	system("copy polygon1.in polygon.in");
	system("polygon");
	assert(!system("fc polygon1.ans polygon.out"));
	system("copy polygon2.in polygon.in");
	system("polygon");
	assert(!system("fc polygon2.ans polygon.out"));
	
	system("copy polygon3.in polygon.in");
	system("polygon");
	assert(!system("fc polygon3.ans polygon.out"));
	system("copy polygon4.in polygon.in");
	system("polygon");
	assert(!system("fc polygon4.ans polygon.out"));
	
	for(int t=1;;t++){
		printf("t=%d\n",t);
		system("rand4");
		system("force4");
		double t0=clock();
		system("polygon");
		printf("time=%.3f\n",(clock()-t0)/CLOCKS_PER_SEC);
		assert(!system("fc force4.out polygon.out"));
	}
	
	return 0;
}
