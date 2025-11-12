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
	freopen("xor.in","w",stdout);
	srand(time(NULL));
	int n=r(1,1000),k=r(0,255);
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;i++){
		printf("%d ",r(0,255));
	}
	puts("");
	return 0;
}
