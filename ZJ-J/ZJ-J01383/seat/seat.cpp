#include<bits/stdc++.h>
using namespace std;
long long N,M,a[105],P,S[15][15],Pos,X=1,Y=1;
bool OP;
bool Cmp(long long X,long long Y) {
	return X>Y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&N,&M);
	for(register int i=1; i<=N*M; i++)scanf("%lld",&a[i]);
	P=a[1];
	sort(a+1,a+N*M+1,Cmp);
	while(Pos<=N*M) {
		S[X][Y]=a[++Pos];
		if(OP)Y--;
		else Y++;
		if(Y==0||Y==M+1) {
			X++;
			OP=!OP;
			if(Y==0)Y=1;
			else Y=M;
		}
	}
	for(register int i=1; i<=N; i++) {
		for(register int j=1; j<=M; j++) {
			if(S[i][j]==P) {
				printf("%d %d",i,j);
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	return 0;
}
