#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cassert>
int r16(){return rand()%(1<<15);}
int r32(){return (r16()<<16)|r16();}
int r(int l,int n){return r32()%(n-l+1)+l;}
int main(){
	srand(time(NULL));
	freopen("club.in","w",stdout);
	int T=r(1,10);
	printf("%d\n",T);
	while(T--){
		int n=r(1,3);
		printf("%d\n",n*2);
		for(int i=1;i<=n*2;i++){
			printf("%d %d %d\n",r(1,10),r(1,10),r(1,10));
		}
	}
	
	return 0;
}
