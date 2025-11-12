#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5001],maxx=-1,MOD=998244353,ans,jcc[5001],sum;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==3)
	{
		if(sum>2*maxx) cout<<1;
		else cout<<0;
		return 0;
	}
	jcc[0]=1,jcc[1]=1;
	for(int i=2;i<=5001;i++) jcc[i]=jcc[i-1]*i%MOD;
	for(int i=3;i<=n;i++) ans=(ans+(jcc[n]/jcc[n-i]/jcc[i]))%MOD;
	cout<<ans;
	return 0;
}