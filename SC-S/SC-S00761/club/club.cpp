#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][4];
long long ans,f[110][110][110][110];
long long ff[210][210][210];
void dfs(int k,int st1,int st2,int st3,long long p)
{
	if(k>n)
	{
		ans=max(p,ans);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1&&st1<n/2)dfs(k+1,st1+1,st2,st3,p+a[k][i]);
		if(i==2&&st2<n/2)dfs(k+1,st1,st2+1,st3,p+a[k][i]);
		if(i==3&&st3<n/2)dfs(k+1,st1,st2,st3+1,p+a[k][i]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		bool A=true,B=true;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]>0||a[i][3]>0)A=false;
			if(a[i][3]>0)B=false;
		}
		if(A)
		{
			int mx=0;
			for(int i=1;i<=n;i++)mx=max(a[i][1],mx);
			cout<<mx<<"\n";
			continue;
		}
		if(n<=10)
		{
			ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		if(n<=30)
		{
			ans=0;
			memset(f,0,sizeof(f));
			f[1][1][0][0]=a[1][1];
			f[1][0][1][0]=a[1][2];
			f[1][0][0][1]=a[1][3];
			for(int i=2;i<=n;i++)
			{
				for(int x=0;x<=min(n/2,i);x++)
				{
					for(int y=0;y<=i-x&&y<=n/2;y++)
					{
						for(int z=0;z<=n/2&&z<=i-x-y;z++)
						{
							if(x>0)f[i][x][y][z]=max(f[i][x][y][z],f[i-1][x-1][y][z]+a[i][1]);
							if(y>0)f[i][x][y][z]=max(f[i][x][y][z],f[i-1][x][y-1][z]+a[i][2]);
							if(z>0)f[i][x][y][z]=max(f[i][x][y][z],f[i-1][x][y][z-1]+a[i][3]);
							if(i==n)ans=max(ans,f[i][x][y][z]);
						}
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(B)
		{
			ans=0;
			memset(ff,0,sizeof(ff));
			ff[1][1][0]=a[1][1];
			ff[1][0][1]=a[1][2];
			for(int i=2;i<=n;i++)
			{
				for(int x=0;x<=min(n/2,i);x++)
				{
					for(int y=0;y<=i-x&&y<=n/2;y++)
					{
						if(x>0)ff[i][x][y]=max(ff[i][x][y],ff[i-1][x-1][y]+a[i][1]);
						if(y>0)ff[i][x][y]=max(ff[i][x][y],ff[i-1][x][y-1]+a[i][2]);
						if(i==n)ans=max(ans,ff[i][x][y]);
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}