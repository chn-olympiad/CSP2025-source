#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
struct edge
{
	int to,nxt,u;
	ll w;
};
edge e[2000005];
int head[10005];
ll c[20];
ll a[20][10005];
int cnt=0;
bool cmp(edge xx,edge yy)
{
	return xx.w<yy.w;
}
void add(int u,int v,ll w)
{
	cnt++;
	e[cnt].nxt=head[u];
	e[cnt].w=w;
	e[cnt].to=v;
	e[cnt].u=u;
	head[u]=cnt;
	return;

}
int top[10005];
int n,m,k;
int finde(int x)
{
	if(top[x]==x)
	{
		return top[x];
	}
	return top[x]=finde(top[x]);
}
void cont(int x,int y)
{
	int fx=finde(x);
	int fy=finde(y);
	if(fx==fy)
	{
		return;
	}
	top[fx]=fy;
	return;
}
ll ans=0;
void kru()
{
	sort(e+1,e+cnt+1,cmp);
	int num=0;
	int pos=1;
	while(num<n-1)
	{
		edge topp=e[pos];
		pos+=2;
		int u=topp.u;
		ll w=topp.w;
		int v=topp.to;
		int fu=finde(u);
		int fv=finde(v);
		if(fu==fv)
		{
			continue;
		}
		num++;
		cont(u,v);
		ans+=w;
	}
	return;
}
/*
void exkru()
{
	sort(e+1,e+cnt+1,cmp);
	int num=0;
	int pos=1;
	while(num<n-1)
	{
		edge topp=e[pos];
		pos+=2;
		int u=topp.u;
		ll w=topp.w;
		int v=topp.to;
		int fu=finde(u);
		int fv=finde(v);
		if(fu==fv)
		{
			continue;
		}
		bool type=topp.typ;
		if(type==0)
		{
			int 
			for(int i=1;i<=k;i++)
			{
				
			}
		}
		ori[]
		num++;
		cont(u,v);
		ori[topp.]
	}
	return;
}
*/
void solve()
{
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=j+1;l<=n;l++)
			{
				add(j,l,a[i][j]+a[i][l]+c[i]);
				add(l,j,a[i][j]+a[i][l]+c[i]);
			}
		}
	}
	kru();
	cout<<ans<<'\n';
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool spa=0;
	cin>>n>>m>>k;
	for(int i=0;i<=1e4;i++)
	{
		head[i]=-1;
	}
	if(k==0)
	{
		spa=1;
	}
	for(int i=1;i<=n;i++)
	{
		top[i]=i;
	}
	int u,v;
	ll w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	int cx;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>cx;
			if(j==1)
			{
				c[i]=cx;
			}
			else
			{
				a[i][j-1]=cx;
			//	cin>>a[i][j-1];
			}
		}
	}
	if(spa)
	{	
		kru();
		cout<<ans<<'\n';
	}
	else
	{
		solve();
	}
	
	return 0;
} 
/*
7 9 0
1 2 1
1 3 2
2 6 2
3 6 2
3  4 3
6 7 1
2 5 1
5 7 4
4 7 2
*/
