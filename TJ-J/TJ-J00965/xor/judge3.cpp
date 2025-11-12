#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
int main(){
	system("copy xor1.in xor.in");
	system("xor");
	assert(!system("fc xor1.ans xor.out"));
	system("copy xor2.in xor.in");
	system("xor");
	assert(!system("fc xor2.ans xor.out"));
	system("copy xor3.in xor.in");
	system("xor");
	assert(!system("fc xor3.ans xor.out"));
	system("copy xor4.in xor.in");
	system("xor");
	assert(!system("fc xor4.ans xor.out"));
	system("copy xor5.in xor.in");
	system("xor");
	assert(!system("fc xor5.ans xor.out"));
	system("copy xor6.in xor.in");
	double t0=clock();
	system("xor");
	printf("time=%.3f\n",(clock()-t0)/CLOCKS_PER_SEC);
	assert(!system("fc xor6.ans xor.out"));
	
	for(int t=1;;t++){
		printf("t=%d\n",t);
		system("rand3");
		system("force3");
		double t0=clock();
		system("xor");
		printf("time=%.3f\n",(clock()-t0)/CLOCKS_PER_SEC);
		assert(!system("fc force3.out xor.out"));
	}
	
	return 0;
}
