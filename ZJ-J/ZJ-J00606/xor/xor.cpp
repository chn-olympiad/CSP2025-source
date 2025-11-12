#include <bits/stdc++.h>
using namespace std;
const int Maxn=500002;
int N=0,K=0,Ans=0;
int A[Maxn];
map<int,bool>Mp;
int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&N,&K);
	for(int I=1;I<=N;++I){
		int X; scanf("%d",&X);
		A[I]=A[I-1]^X;
	}
	Mp[0]=1;
	for(int I=1;I<=N;++I){
		int Tar=A[I]^K;
		if(Mp[Tar]==1){
			++Ans;
			Mp.clear();
		}
		Mp[A[I]]=1;
	}
	printf("%d\n",Ans);
	return 0;
}
