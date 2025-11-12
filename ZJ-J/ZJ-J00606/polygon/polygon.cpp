#include <bits/stdc++.h>
using namespace std;
const int Maxn=5002;
const int Mod=998244353;
int N=0,Ans=0;
int A[Maxn];
void Solve1(void){
	vector<int>Dp(50002);
	Dp[0]=1;
	int Lastsum=0;
	for(int I=1;I<=N;++I){
		for(int J=A[I]+1;J<=Lastsum;++J){
			Ans=(Ans+Dp[J])%Mod;
		}
		for(int J=Lastsum;J>=0;--J){
			Dp[J+A[I]]=(Dp[J+A[I]]+Dp[J])%Mod;
		}
		Lastsum=Lastsum+A[I];
	}
	return ;
}
void Solve2(void){
	vector<int>Dp(25000002);
	Dp[0]=1;
	int Lastsum=0;
	for(int I=1;I<=N;++I){
		for(int J=A[I]+1;J<=Lastsum;++J){
			Ans=(Ans+Dp[J])%Mod;
		}
		for(int J=Lastsum;J>=0;--J){
			Dp[J+A[I]]=(Dp[J+A[I]]+Dp[J])%Mod;
		}
		Lastsum=Lastsum+A[I];
	}
	return ;
}
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&N);
	for(int I=1;I<=N;++I){
		scanf("%d",&A[I]);
	}
	sort(A+1,A+N+1);
	if(N<=500||A[N]<=1){
		Solve1();
	}else{
		Solve2();
	}
	printf("%d\n",Ans);
	return 0;
}
