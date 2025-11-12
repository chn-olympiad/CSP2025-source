#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010],z[5010][5010],ans,maxn;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i],maxn=max(maxn,a[i]);
	sort(a+1,a+n+1);
	z[0][0]=1;
	maxn++;
	for(int i=1; i<=n; i++) {
		if(i>=3) {
			for(int j=a[i]+1; j<=maxn; j++)ans+=z[i-1][j],ans%=mod;
		}
		for(int j=0; j<=maxn; j++) {
			z[i][j]+=z[i-1][j];
			z[i][j]%=mod;
			z[i][min(maxn,a[i]+j)]+=z[i-1][j];
			z[i][min(maxn,a[i]+j)]%=mod;
		}
	}
	cout<<(ans+mod)%mod;
	return 0;
}
