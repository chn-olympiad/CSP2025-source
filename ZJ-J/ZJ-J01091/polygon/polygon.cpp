#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[5010],g[5010][5010];
const int mod=998244353;
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	g[0][2]=1;g[a[1]][2]=1;
	for(int i=3;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=30;j++)
		{
			g[j][i]=g[j][i-1];
			if(j>=a[i-1])
			{
				g[j][i]+=g[j-a[i-1]][i-1];
			}
		}
		for(int j=a[i]+1;j<=30;j++)
		{
			cnt=(cnt+g[j][i])%mod;
		}
		ans=(ans+cnt)%mod;
	}
	cout<<ans;
	return 0;
}