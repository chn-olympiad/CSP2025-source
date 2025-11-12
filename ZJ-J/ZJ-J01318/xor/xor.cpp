#include <bits/stdc++.h>
#define int long long
using namespace std;
unordered_map <int,int> mp;
int n,k,to,a[1000010],f[1000010],l[1000010],dp[1000010];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f[i]=f[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;i++) {
		to=f[i]^k;
		if(!mp.count(to)) l[i]=-1;
		else l[i]=mp[to];
		mp[f[i]]=i;
	}
	for(int i=1;i<=n;i++) {
		dp[i]=dp[i-1];
		if(l[i]!=-1) dp[i]=max(dp[i],dp[l[i]]+1);
	}
	cout<<dp[n];
	return 0;
}