#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;
const int N=5e5+10;
int n,x,k,sum[N],dp[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	For(i,1,n){
		cin>>x;
		sum[i]=(sum[i-1]^x);
	}
	For(r,1,n) For(l,1,r)
		dp[r]=max(dp[r],dp[l-1]+((sum[r]^sum[l-1])==k));
	cout<<dp[n];
	return 0;
}


