#include<bits/stdc++.h>
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
struct st{
	int a,b,c;
}a[100006];
int t,n,f[2][106][106];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<=n/2;i++)
		{
			for(int j=0;j<=n/2;j++)
			{
				f[0][i][j]=f[1][i][j]=-1e9;
			}
		}
		f[0][0][0]=0;
		bool fl1=true,fl2=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b)
			{
				fl1=false;
			}
			if(a[i].c)
			{
				fl2=false;
			}
		}
		if(fl2)
		{
			if(fl1)
			{
				sort(a+1,a+n+1,[&](st x,st y)
				{
					return x.a>y.a;
				});
				int ans=0;
				for(int i=1;i<=n/2;i++)
				{
					ans+=a[i].a;
				}
				cout<<ans<<'\n';
				continue;
			}
			else
			{
				sort(a+1,a+n+1,[&](st x,st y)
				{
					return x.b-x.a>y.b-y.a;
				});
				int ans=0;
				for(int i=1;i<=n/2;i++)
				{
					ans+=a[i].b-a[i].a;
				}
				for(int i=1;i<=n;i++)
				{
					ans+=a[i].a;
				}
				cout<<ans<<'\n';
				continue;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int now=i&1,odd=(i&1)^1;
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					if(j+k>i)
					{
						break;
					}
					f[now][j][k]=max(f[now][j][k],f[odd][j][k]+a[i].a);
					if(k!=0)
					{
						f[now][j][k]=max(f[now][j][k],f[odd][j][k-1]+a[i].c);
					}
					if(j!=0)
					{
						f[now][j][k]=max(f[now][j][k],f[odd][j-1][k]+a[i].b);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++)
		{
			for(int j=0;j<=n/2;j++)
			{
				if(i+j>=n/2)
				{
					ans=max(ans,f[n&1][i][j]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}