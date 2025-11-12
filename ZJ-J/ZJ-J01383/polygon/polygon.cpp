#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long N,a[5005],Ans;
void dfs(long long Dep,long long Res,long long Max,long long Sum) {
	if(Res==0) {
		if(Sum>Max*2)Ans=(Ans+1)%mod;
		return;
	}
	if(Dep==N+1)return;
	dfs(Dep+1,Res,Max,Sum);
	dfs(Dep+1,Res-1,max(Max,a[Dep]),Sum+a[Dep]);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&N);
	for(register int i=1; i<=N; i++)scanf("%lld",&a[i]);
	for(register int i=N; i>=3; i--)dfs(1,i,0,0);
	cout<<Ans%mod<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
