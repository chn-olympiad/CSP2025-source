#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005][5];
long long f[205][205][205];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		}
		f[0][0][0]=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int x=i;x>=0;x--)
			{
				for(int y=i-x;y>=0;y--)
				{
					if(x>n/2 || y>n/2 || (i-x-y)>n/2) continue;
					if(x>=1) f[x][y][i-x-y]=max(f[x][y][i-x-y],f[x-1][y][i-x-y]+a[i][1]);
					if(y>=1) f[x][y][i-x-y]=max(f[x][y][i-x-y],f[x][y-1][i-x-y]+a[i][2]);
					if(i-x-y>=1) f[x][y][i-x-y]=max(f[x][y][i-x-y],f[x][y][i-x-y-1]+a[i][3]);
					ans=max(ans,f[x][y][i-x-y]);
				}
			}
		}
		printf("%d\n",ans);
	}
}