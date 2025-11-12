#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],f[500005],dp[500005];
map<long long,long long>Max;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)f[i]=f[i-1]^a[i];
	Max[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(Max.count(f[i]^k))dp[i]=max(dp[i],Max[f[i]^k]+1);
		Max[f[i]]=max(Max[f[i]],dp[i]);
	}
	cout<<dp[n];
	return 0;
}
