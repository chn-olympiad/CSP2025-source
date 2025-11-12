#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,sum,ans,a[5005],f[25000005];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
	    cin>>a[i];
	    sum+=a[i];
	}
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;++i)
	{
	    for(int j=sum;j>=a[i];--j)
	    	f[j]=(f[j]+f[j-a[i]])%mod;
	    if((i>1)&&(i<n))
	    {
	    	for(int j=a[i+1]+1;j<=sum;++j)
	    	    ans=(ans+f[j])%mod;
	    }
	}
	cout<<ans;
	return 0;
}
