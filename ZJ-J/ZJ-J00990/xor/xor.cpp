#include<bits/stdc++.h>
using namespace std;
int const N=5e5+5;
int w[N],dp[N];
unordered_map<int,int>mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		w[i]^=w[i-1];
	}
	int ans=0;
	mp[k]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(mp.count(w[i]))
			dp[i]=max(dp[i],mp[w[i]]+1);
		mp[w[i]^k]=max(mp[w[i]^k],dp[i]);
	}
	cout<<dp[n];
	return 0;
}