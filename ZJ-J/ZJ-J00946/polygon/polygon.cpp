#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],st[N][N],ans;
int mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if (n==3)
	{
		if (a[1]+a[2]+a[3]>2*a[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	st[1][0]=1;
	st[1][1]=1;
	st[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			st[i][j]=(st[i-1][j]+st[i-1][j-1])%mod;
		}
	}
	for (int i=3;i<=n;i++)
	{
		ans=(ans+st[n][i])%mod;
	}
	cout<<ans;
	return 0;
}
