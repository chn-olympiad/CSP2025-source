#include<bits/stdc++.h>
#define N 500005
#define M 2000005
using namespace std;
int n,k,a[N],t[M],dp[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=0;i<(1<<20);i++)	t[i]=-1;
	t[0]=0;
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1],dp[i]=dp[i-1];
		if(t[a[i]^k]!=-1)	dp[i]=max(dp[i],dp[t[a[i]^k]]+1);
		t[a[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
