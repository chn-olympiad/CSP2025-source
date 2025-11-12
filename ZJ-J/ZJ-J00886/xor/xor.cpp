#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,dp[maxn],a[maxn],b[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int x=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		x=x^a[i];
		int p=b[x^k];
		if(p) dp[i]=max(dp[i],dp[p]+1);
		if(x==k) dp[i]=max(dp[i],1);
		b[x]=i;
	}
	cout<<dp[n]<<"\n";
	return 0;
}
