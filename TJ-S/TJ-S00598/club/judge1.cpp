#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cassert>
int main(){
	system("copy club1.in club.in");
	system("club");
	assert(!system("fc club1.ans club.out"));
	puts("TEST 1 COMPLETE!!!");
	
	system("copy club2.in club.in");
	system("club");
	assert(!system("fc club2.ans club.out"));
	puts("TEST 2 COMPLETE!!!");
	
	system("copy club3.in club.in");
	system("club");
	assert(!system("fc club3.ans club.out"));
	puts("TEST 3 COMPLETE!!!");
	
	system("copy club4.in club.in");
	system("club");
	assert(!system("fc club4.ans club.out"));
	puts("TEST 4 COMPLETE!!!");
	
	system("copy club5.in club.in");
	system("club");
	assert(!system("fc club5.ans club.out"));
	puts("TEST 5 COMPLETE!!!");
	
	for(int t=1;;t++){
		printf("t=%d\n",t);
		system("rand1");
		system("force1");
		double t0=clock();
		system("club");
		printf("%.3f\n",(clock()-t0)/CLOCKS_PER_SEC);
		assert(!system("fc force1.out club.out"));
	}
	return 0;
}
