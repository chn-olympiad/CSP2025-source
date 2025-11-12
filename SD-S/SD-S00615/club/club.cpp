#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define M 5010
#define ll long long
int T,n,m,fg;
int a[N][3];
ll ans,sum,f[N],d[M][M];
void dfs(int x,int aa,int bb,int cc,ll s)
{
	if (x>n)
	{
		ans=max(ans,s);
		return;
	}
	if (aa+1<=m) dfs(x+1,aa+1,bb,cc,s+a[x][0]);
	if (bb+1<=m) dfs(x+1,aa,bb+1,cc,s+a[x][1]);
	if (cc+1<=m) dfs(x+1,aa,bb,cc+1,s+a[x][2]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		sum=0;fg=1;
		ans=0;
		scanf("%d",&n);
		m=n/2;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<3;j++)
			{
				scanf("%d",&a[i][j]);
			}
			sum+=a[i][0];
			if (a[i][2]!=0) fg=2;
		}
		if (n<=10)
		{
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
			continue;
		}
		if (fg==1)
		{
			f[0]=sum;
			for (int i=1;i<=n;i++)
			{
				for (int j=m;j>=1;j--)
				{
					f[j]=max(f[j],f[j-1]-a[i][0]+a[i][1]);
				}
			}
			printf("%lld\n",f[n/2]);
			continue;
		}
		d[0][0]=sum;
		for (int i=1;i<=n;i++)
		{
			for (int j=m;j>=0;j--)
			{
				for (int k=m;k>=0;k--)
				{
					if (j==0&&k==0) continue;
					if (j==0) d[j][k]=max(d[j][k],d[j][k-1]-a[i][0]+a[i][2]);
					else if (k==0) d[j][k]=max(d[j][k],d[j-1][k]-a[i][0]+a[i][1]);
					else d[j][k]=max(d[j][k],max(d[j-1][k]-a[i][0]+a[i][1],d[j][k-1]-a[i][0]+a[i][2]));
				}
			}
		}
		for (int j=0;j<=m;j++)
		{
			for (int k=0;k<=m;k++)
			{
				if (j+k<m) continue;
				ans=max(ans,d[j][k]);
			}
		}
		printf("%lld\n",ans);
	}

	//system("fc .out .ans");
	return 0;
}

