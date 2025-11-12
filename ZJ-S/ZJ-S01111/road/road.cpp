/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
*/
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[1000001];
long long read()
{
	long long f=1,x=0;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void init()
{
	for(int i=1;i<=n+k*n;i++)
	{
		fa[i]=i;
	}
	return;
}
struct node
{
	int u,v;
	long long w;
};
node a[1000001];
node b[11][1000001];
long long c[1000001];
int father(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=father(fa[x]);
}
void merge(int x,int y)
{
	x=father(x);
	y=father(y);
	if(x!=y)fa[x]=y;
	return;
}
bool query(int x,int y)
{
	x=father(x);
	y=father(y);
	if(x==y)return true;
	return false;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	init();	
	for(int i=1;i<=m;i++)
	{
		a[i].u=read();a[i].v=read();a[i].w=read();
	}
	
	long long ans=0;
	if(k==0)
	{
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			if(query(a[i].u,a[i].v)==false)
			{
				merge(a[i].u,a[i].v);
				ans+=a[i].w;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(k!=0)
	{
		bool flagA=true;
		for(int i=1;i<=k;i++)
		{
			c[i]=read();
			if(c[i]!=0)flagA=false;
			for(int j=1;j<=n;j++)
			{
				b[i][j].u=n+i;
				b[i][j].v=j;
				b[i][j].w=read();	
			}
		}
		if(flagA==true)
		{
			init();
			long long mnow=m,ansnow=0;
			for(int t=1;t<=k;t++)
			{
				ansnow+=c[t];
				for(int j=1;j<=n;j++)
				{
					a[++mnow].u=b[t][j].u;
					a[mnow].v=b[t][j].v;
					a[mnow].w=b[t][j].w;
				}
			}
			sort(a+1,a+1+mnow,cmp);
			for(int i=1;i<=mnow;i++)
			{
				if(query(a[i].u,a[i].v)==false)
				{
					merge(a[i].u,a[i].v);
					ansnow+=a[i].w;
				}
			}
			cout<<ansnow<<endl;
			return 0;
		}
		ans=0x3f3f3f3f;
		for(int vil=0;vil<(1<<k);vil++)
		{
			init();
			long long mnow=m,ansnow=0;
			int k=vil,t=1;
			while(k!=0)
			{
				if(k&1)
				{
					ansnow+=c[t];
					for(int j=1;j<=n;j++)
					{
						a[++mnow].u=b[t][j].u;
						a[mnow].v=b[t][j].v;
						a[mnow].w=b[t][j].w;
					}
				}
				k>>=1;
			}
			sort(a+1,a+1+mnow,cmp);
			for(int i=1;i<=mnow;i++)
			{
				if(query(a[i].u,a[i].v)==false)
				{
					merge(a[i].u,a[i].v);
					ansnow+=a[i].w;
				}
			}
			ans=min(ansnow,ans);
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
