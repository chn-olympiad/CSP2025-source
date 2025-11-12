#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
int main(){
	system("copy number1.in number.in");
	system("number");
	assert(!system("fc number1.ans number.out"));
	system("copy number2.in number.in");
	system("number");
	assert(!system("fc number2.ans number.out"));
	system("copy number3.in number.in");
	system("number");
	assert(!system("fc number3.ans number.out"));
	system("copy number4.in number.in");
	double t0=clock();
	system("number");
	printf("time=%.3f\n",(clock()-t0)/CLOCKS_PER_SEC);
	assert(!system("fc number4.ans number.out"));
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
