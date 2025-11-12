#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
int main(){
	system("copy seat1.in seat.in");
	system("seat");
	assert(!system("fc seat1.ans seat.out"));
	system("copy seat2.in seat.in");
	system("seat");
	assert(!system("fc seat2.ans seat.out"));
	system("copy seat3.in seat.in");
	double t0=clock();
	system("seat");
	printf("time=%.3f\n",(clock()-t0)/CLOCKS_PER_SEC);
	assert(!system("fc seat3.ans seat.out"));
	/*
	for(int t=1;;t++){
		printf("t=%d\n",t);
		system("rand");
		system("force");
		double t0=clock();
		system("std");
		printf("time=%.3f\n",(clock()-t0)/COLCKS_PER_SEC);
		assert(!system("fc force.out std.out"));
	}
	*/
	return 0;
}
