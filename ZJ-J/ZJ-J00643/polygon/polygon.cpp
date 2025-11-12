#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,i,j,sum,ans,a[100010];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;for(i=1;i<=n;i++) cin>>a[i];
	for(i=3;i<=n;i++){
		sum=1;
		for(j=n;j>=n-i+1;j--)
			sum*=j;
		for(j=i;j>=1;j--)
			sum/=j;
		ans+=sum;ans=ans%mod;
	}
	cout<<ans%mod;
	return 0;
}	
