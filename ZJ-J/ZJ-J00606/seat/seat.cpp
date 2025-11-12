#include <bits/stdc++.h>
using namespace std;
const int Maxnm=12;
int N=0,M=0,XiaoR=0,Rank=0;
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&N,&M);
	scanf("%d",&XiaoR);
	for(int I=2;I<=N*M;++I){
		int X; scanf("%d",&X);
		if(X>XiaoR){
			++Rank;
		}
	}
	if((Rank/N)%2==0){
		printf("%d %d",Rank/N+1,Rank%N+1);
	}else{
		printf("%d %d",Rank/N+1,N-Rank%N);
	}
	printf("\n");
	return 0;
}
