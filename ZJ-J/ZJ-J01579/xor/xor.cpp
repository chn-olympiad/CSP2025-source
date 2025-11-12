#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+5;
int n,k,a[N],s[N],dp[N],mp[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(mp[s[i]^k]||(s[i]^k)==0) dp[i]=max(dp[i],dp[mp[s[i]^k]]+1);
		mp[s[i]]=i;
	}
	cout<<dp[n];
	return 0;
}

