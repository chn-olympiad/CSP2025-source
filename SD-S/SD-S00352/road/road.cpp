#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+50;
int n,m,k;
struct edge
{
	int u,v;
	ll w;
}e[N];
int fa[N];
queue<edge> q;
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(ll x)
{
	return x==fa[x]?fa[x]:x=find(fa[x]);
}
ll ans=0;
void kru()
{
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		u=find(u),v=find(v);
		if(u==v)continue;
		ans+=e[i].w;
		q.push(e[i]);
		fa[u]=v;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=n+1;i<=n+k;i++)
	{
		ll c;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			ll w;
			cin>>w;
			e[++m].u=i;
			e[m].v=j;
			e[m].w=w;
		}
	}
	kru();
	cout<<ans;
	return 0;
}
//打了2个小时，没想出正解，暴力严重超时，打了特殊性质40~48
//这是我第一次打csp，也可能是最后一次了
//已经初三了，csp-s还拿不到1=，可以退役了，拿到J1去考强基班吧 
//回去还得补whk，可能是我与oi无缘吧
//还有20min，去骗一下T3，T4的分吧 
//希望分数线在130~140左右吧。。。。。 
