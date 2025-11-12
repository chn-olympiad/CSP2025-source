#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,z,i,a[500010],b[500010],j,k,dp[500010],ans,e[500010],lst[500010];
map<int,int> f;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>z;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) b[i]=b[i-1]^a[i];
	for(i=1;i<=n;i++) f[b[i]^z]=-1;
	f[0]=0;
	for(i=1;i<=n;i++){
		if(f[b[i]^z]==-1) lst[i]=i;
		else lst[i]=f[b[i]^z];
		f[b[i]]=i;
	}
	for(i=1;i<=n;i++){
		if(lst[i]!=i) dp[i]=e[lst[i]]+1;
		else dp[i]=0;
		e[i]=max(e[i-1],dp[i]);
	}
	for(i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}