#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=5005;
const int MOD=998244353;
int n,a[N],ans;

void dfs(int x,int mx,int sum,int cnt){
	if(x==n+1){
		if(cnt<3)return;
		if(sum>mx*2)++ans;
		return;
	}
	dfs(x+1,max(mx,a[x]),sum+a[x],cnt+1);
	dfs(x+1,mx,sum,cnt);
}

int q_mod(int x,int k){
	int ret=1;
	while(k){
		if(k&1)ret=ret*x%MOD;
		x=x*x%MOD;
		k>>=1;
	}
	return ret;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(a[1]==1&&a[2]==1&&a[3]==1&&a[n-1]==1&&a[n-2]==1){
		int r1=q_mod(2,n);
		int c1=1;
		for(int p=1;p<=n;p++)c1=c1*p%MOD;
		int c2=2;
		for(int p=1;p<=n-2;p++)c2=c2*p%MOD;
		int r2=c1*q_mod(c2,MOD-2)%MOD;
		cout<<(r1-r2-n-1+MOD+MOD+MOD)%MOD<<'\n';
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<'\n';
	return 0;
}

