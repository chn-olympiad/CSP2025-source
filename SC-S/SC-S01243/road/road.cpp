#include<bits/stdc++.h>
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
struct Node{
	int x,y,s;
}b[2000006];
int n,m,k,cnt,a[16][10006],d[16],fa[10006],c[1006][1006];
int find(int x)
{
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int read()
{
	int z=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		z=z*10+c-'0';
		c=getchar();
	}
	return z*f;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,x,y,z;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		if(x>y)
		{
			swap(x,y);
		}
		if(c[x][y])
		{
			b[c[x][y]].s=min(b[c[x][y]].s,z);
		}
		else
		{
			cnt++;
			b[cnt].x=x,b[cnt].y=y,b[cnt].s=z;
			c[x][y]=cnt;
		}
	}
	bool fl=true;
	for(int i=1;i<=k;i++)
	{
		cin>>d[i];
		if(d[i])
		{
			fl=false;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(fl)
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(c[j][k])
					{
						b[c[j][k]].s=min(b[c[j][k]].s,a[i][j]+a[i][k]);
					}
					else
					{
						cnt++;
						b[cnt].x=j,b[cnt].y=k,b[cnt].s=a[i][j]+a[i][k];
						c[j][k]=cnt;
					}
				}
			}
		}
		sort(b+1,b+cnt+1,[&](Node x,Node y)
		{
			return x.s<y.s;
		});
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			int x,y,s;
			x=b[i].x,y=b[i].y,s=b[i].s;
			int fx=find(x),fy=find(y);
			if(fx==fy)
			{
				continue;
			}
			ans+=s;
			fa[fy]=fx;
		}
		cout<<ans;
		return 0;
	}
	int m=(1<<k)-1,ans=1e18,num=cnt;
	for(int i=0;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			fa[j]=j;
		}
		cnt=num;
		int sum=0;
		vector<int>v;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<k-1))
			{
				v.push_back(j);
			}
		}
		for(auto j:v)
		{
			sum+=d[j];
			for(int l=1;l<=n;l++)
			{
				for(int p=l+1;p<=n;p++)
				{
					if(c[l][p])
					{
						b[c[l][p]].s=min(b[c[l][p]].s,a[j][l]+a[j][p]+d[j]);
					}
					else
					{
						cnt++;
						b[cnt].x=j,b[cnt].y=l,b[cnt].s=a[j][l]+a[j][p]+d[j];
						c[l][p]=cnt;
					}
				}
			}
		}
		sort(b+1,b+cnt+1,[&](Node x,Node y)
		{
			return x.s<y.s;
		});
		sum=0;
		for(int i=1;i<=cnt;i++)
		{
			int x,y,s;
			x=b[i].x,y=b[i].y,s=b[i].s;
			int fx=find(x),fy=find(y);
			if(fx==fy)
			{
				continue;
			}
			sum+=s;
			fa[fy]=fx;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}