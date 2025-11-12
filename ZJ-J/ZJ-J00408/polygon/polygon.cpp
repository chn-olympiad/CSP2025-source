#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
void dfs(int x,int y,int s) {
	if(x>=2)for(int i=y+1; i<=n; i++)
			if(s>a[i])ans=(ans+1)%mod;
			else break;
	for(int i=y+1; i<=n; i++)
		dfs(x+1,i,s+a[i]);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a[1];
	int jh=0;
	for(int i=2; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=a[i-1])jh=1;
	}
	if(jh==0) {
		ans=1;
		for(int i=1; i<=n; i++)
			ans*=2;
		int cn0=1;
		int cn1=n;
		int cn2=n*(n-1)/2;
		cout<<ans-cn0-cn1-cn2<<"\n";
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<ans<<"\n";
	return 0;
}
//csprp++;
//64 pts