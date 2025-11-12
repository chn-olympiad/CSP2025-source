#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],f[1010][1010],mx1=0;
int g[500010],q[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx1=max(mx1,a[i]);
		for (int j=1;j<=i;j++)
			f[j][i]=f[j][i-1]^a[i];
	}
	memset(g,0,sizeof(g));
	if (mx1==1)
	{
		int cnt=0;
		if (m==1)
		{
			for (int i=1;i<=n;i++)
				if (a[i]==1) cnt++;
			cout << cnt;
		}
		else if (m==0)
		{
			for (int i=1;i<=n;i++)
				if (a[i]==0) cnt++;
			int sum=0;
			for (int i=1;i<=n;i++)
			{
				if (a[i]==1) sum++;
				if (a[i]==0)
				{
					cnt+=sum/2;
					sum=0;
				}
			}
			cout << cnt;
		}
		else cout << 0;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			int mx=0;
			for (int j=1;j<=i;j++)
				if (f[j][i]==m)
				{
					mx=max(mx,g[j-1]+1);
				}
			g[i]=mx;
			g[i]=max(g[i],g[i-1]);
		}
		cout << g[n];
	}
	return 0;
}
