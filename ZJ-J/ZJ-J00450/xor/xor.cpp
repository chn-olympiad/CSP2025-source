#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],f[N],dp[N],t[2000000];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]^a[i];
	memset(t,-1,sizeof(t));
	t[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int fd=k^f[i];
		if(t[fd]!=-1&&t[fd]<i) dp[i]=max(dp[i],dp[t[fd]]+1);
		t[f[i]]=i;
	}
	cout<<dp[n];
	return 0;
}