#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
int r16(){return rand()%(1<<15);}
int r32(){return (r16()<<16)|r16();}
int r(int l,int n){return (r32()%(n-l+1)+l);}
int main(){
	srand(time(NULL));
	
	return 0;
}
