#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+100;
int ans,sum[N],mod=998244353 ;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	sum[0]=1;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]*(n-i+1)/i,sum[i]%=mod;
	for(int i=3;i<=n;i++) ans+=sum[i],ans%=mod;
	cout<<ans<<"\n";
	return 0;
}
/*
5
1 2 3 4 5
*/
