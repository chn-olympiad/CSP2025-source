#include<bits/stdc++.h>
using namespace std;
struct info{
	int x,y,z;
}a[100010];
int f[110][110][110],n,t;
bool cmp1(info a,info b)
{
	return a.x>b.x;
}
bool cmp2(info a,info b)
{
	return a.x-a.y>b.x-b.y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool flag2=1,flag3=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0)
				flag2=0;
			if(a[i].z!=0)
				flag3=0;
		}
		if(flag2&&flag3)
		{
			stable_sort(a+1,a+1+n,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			printf("%d\n",ans);
		}
		else if(flag3)
		{
			stable_sort(a+1,a+1+n,cmp2);
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			for(int i=n/2+1;i<=n;i++)
				ans+=a[i].y;
			printf("%d\n",ans);
		}
		else
		{
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n/2;j++)
					for(int k=0;k<=n/2;k++)
						if(j+k<=i)
							f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].x);
				for(int j=0;j<=n/2;j++)
					for(int k=1;k<=n/2;k++)
						if(j+k<=i)
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].y);
				for(int j=0;j<=n/2;j++)
					for(int k=0;k<=n/2;k++)
						if(j+k<i&&i-j-k<=n/2)
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
			}
			int ans=0;
			for(int i=0;i<=n/2;i++)
				for(int j=0;j<=n/2;j++)
					if(n-i-j<=n/2)
						ans=max(ans,f[n][i][j]);
			printf("%d\n",ans);
		}
	}
	return 0;
}
