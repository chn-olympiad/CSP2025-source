#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int N,M;
char Strs[502];
bool Test[502];
int C[502];
int Pailie[20];
void Solve1(void){
	int Ans=0;
	for(int I=1;I<=N;++I){
		Pailie[I]=I;
	}
	do{
		int Goaw=0;
		for(int I=1;I<=N;++I){
			if(Goaw>=C[Pailie[I]]||Test[I]==0){
				++Goaw;
			}
		}
		if(Goaw<=N-M){
			Ans=(Ans+1)%Mod;
		}
	}while(next_permutation(Pailie+1,Pailie+N+1));
	printf("%d\n",Ans);
	return ;
}
int main(void){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&N,&M);
	int Summer=0;
	scanf("%s",Strs);
	for(int I=0;I<N;++I){
		Test[I+1]=Strs[I]-'0';
		Summer=Summer+Test[I];
	}
	for(int I=1;I<=N;++I){
		scanf("%d",&C[I]);
	}
	if(N<=18){
		Solve1();
	}
	
	return 0;
}
