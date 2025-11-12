#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
ll a[500010];
map<ll,int>mp;
int dp[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	mp[0ll]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int p=(a[i]^k);
		if(mp.count(p)){
			dp[i]=max(dp[i],dp[mp[p]]+1);
		}
		mp[a[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
