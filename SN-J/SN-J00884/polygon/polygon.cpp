#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
#define ll long long
const ll mod=998244353;
ll sol[N];
ll f[N];
ll ans;
int a[N];
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sol[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>=3)
		{
			for(int j=5001;j>a[i];j--)
			{
				f[i]=(f[i]+sol[j])%mod;
			}
		}
		for(int j=5001;j>=5001-a[i];j--)
		{
			sol[5001]+=sol[j];
			sol[5001]%=mod;
		}
		for(int j=5000;j>=a[i];j--)
		{
			sol[j]+=sol[j-a[i]];
			sol[j]%=mod;
		}
	}
	for(int i=3;i<=n;i++) ans=(ans+f[i])%mod;
	cout<<ans<<'\n';
	return 0;
}
