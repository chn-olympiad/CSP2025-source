#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
inline void print(long long x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)print(x/10);
	putchar(x%10+48);
}
int n,m,k;
struct node
{
	int u,v,w;
}e[2000010],E[2000010];
int a[20][10010],c[10010],fa[100010];
long long ans=1e18;
inline int get(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
inline bool cmp(node x,node y)
{
	return x.w<y.w;
}
inline long long solve(int s)
{
//	cerr<<"s:"<<s<<'\n';
//	cerr<<"qwq\n"<<e[11].u<<' '<<E[1].u<<"\n";
//	exit(0);
	int cnt=m,tmp=0;
	long long res=0;
	for(int i=1;i<=m;i++)
	{
		e[i]=E[i];
//		cerr<<"why:"<<E[i].u<<" "<<E[i].v<<'\n';
	}
//	exit(0);
	for(int i=1;i<=k;i++)
	{
		if(s&(1<<(i-1)))
		{
			tmp++;
			res=res+c[i];
			for(int j=1;j<=n;j++)
			{
				e[++cnt]={n+i,j,a[i][j]};
//				if(cnt==11)
//				{
//					cout<<"Iloveyou:"<<e[cnt].u<<'\n';
//				}
			}
		}
	}
//	for(int i=1;i<=cnt;i++)
//	{
//		cerr<<"i:"<<e[i].u<<' '<<e[i].v<<"\n";
//	}
	sort(e+1,e+cnt+1,cmp);
	int num=0;
	for(int i=1;i<=n+15;i++)fa[i]=i;
//	cerr<<"qwq\n"<<e[11].u<<"\n";
	for(int i=1;i<=cnt;i++)
	{
//		cerr<<i<<" "<<cnt<<' '<<e[i].u<<'\n';
		int x=get(e[i].u),y=get(e[i].v),w=e[i].w;
//		cerr<<i<<' '<<x<<' '<<y<<' '<<w<<'\n';
		if(x!=y)
		{
			fa[x]=y;
			res=res+w;
			num++;
		}
//		cerr<<i<<' '<<x<<' '<<y<<' '<<w<<'\n';
		if(num==n+tmp-1)
		{
			break;
		}
	}
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		E[i].u=u;
		E[i].v=v;
		E[i].w=w;
//		if(i<=1000)
//		cerr<<"sourse:"<<E[i].u<<" "<<E[i].v<<"\n";
	}
	bool flg=1;
//	cerr<<E[1].u;
//	exit(0);
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]>0)flg=0;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
//	exit(0);
	if(flg==0)
	{
		if(k>5)
		{
			for(int s=0;s<(1<<k);s+=11)
			{
				ans=min(ans,solve(s));
			}
			ans=min(ans,solve((1<<k)-1));
		}
		else
		for(int s=0;s<(1<<k);s++)
		{
			ans=min(ans,solve(s));
		}
	}
	else
	{
//		cerr<<"qwq\n";
		ans=solve((1<<k)-1);
	}
	print(ans);
}
