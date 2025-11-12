#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int to,nxt,u;
	ll w;
};
edge e[2000005];
edge eo[2000005];
int head[10005];
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
	eo[cnt]=e[cnt];
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
void solvea()
{
	int num=0;
	int pos=1;
	while(num<n-1)
	{
		edge topp=e[pos];
		pos+=2;
		int u=topp.u;
		int w=topp.w;
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
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool spa=0;
	cin>>n>>m>>k;
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
	sort(e+1,e+cnt+1,cmp);
	if(spa)
	{
		solvea();
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
} 
