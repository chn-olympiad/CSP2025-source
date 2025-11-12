#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cassert>
int main(){
	system("copy road1.in road.in");
	system("road");
	assert(!system("fc road1.ans road.out"));
	puts("TEST 1 COMPLETE!!!");
	
	system("copy road2.in road.in");
	double t0=clock();
	system("road");
	printf("%.3f\n",(clock()-t0)/CLOCKS_PER_SEC);
	assert(!system("fc road2.ans road.out"));
	puts("TEST 2 COMPLETE!!!");
	
	system("copy road3.in road.in");
	system("road");
	assert(!system("fc road3.ans road.out"));
	puts("TEST 3 COMPLETE!!!");
	
	system("copy road4.in road.in");
	t0=clock();
	system("road");
	printf("%.3f\n",(clock()-t0)/CLOCKS_PER_SEC);
	assert(!system("fc road4.ans road.out"));
	puts("TEST 4 COMPLETE!!!");
	
	/*
	system("copy club5.in club.in");
	system("club");
	assert(!system("fc club5.ans club.out"));
	puts("TEST 5 COMPLETE!!!");
	*/
	/*
	for(int t=1;;t++){
		printf("t=%d\n",t);
		system("rand1");
		system("force1");
		double t0=clock();
		system("club");
		printf("%.3f\n",(clock()-t0)/CLOCKS_PER_SEC);
		assert(!system("fc force1.out club.out"));
	}
	*/
	return 0;
}
