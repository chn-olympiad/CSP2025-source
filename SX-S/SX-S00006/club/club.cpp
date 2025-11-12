#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][13],v[N][5],f[N][13];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t=1,n,s,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=0;
		s=n/2;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]==0)
				{
					f[i][j]=a[i-1][j];
				}
				else
				{
					for(int k=1;k<=3;k++)
					{
						if(f[i-1][k]+a[i][j]>f[i][j])
						{
							if(v[i-1][j]+1>s)
							{
								continue;
							}
							else
							{
								f[i][j]=f[i-1][k]+a[i][j];
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			if(ans<f[n][i])
				ans=f[n][i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}