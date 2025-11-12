#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct Edge{
	int u,v,w;
	friend bool operator>(Edge a,Edge b)
	{
		return a.w>b.w;
	}
};
priority_queue<Edge,vector<Edge>,greater<Edge> >q;
int fa[10005];
inline int getfa(int rt)
{
	if(fa[rt]!=rt)return fa[rt]=getfa(fa[rt]);
	else return rt;
}
inline bool isone(int a,int b)
{
	return getfa(a)==getfa(b);
}
inline void toone(int a,int b)
{
	fa[getfa(a)]=getfa(b);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	int meishayong;
	for(int i=1;i<=k*(n+1);i++)cin>>meishayong;
	while(!q.empty())
	{
		Edge tp=q.top();
		q.pop();
		if(isone(tp.u,tp.v))continue;
		toone(tp.u,tp.v);
		ans+=tp.w;
	}
	cout<<ans;
	return 0;
}
