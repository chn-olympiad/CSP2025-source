#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
	int u,v,w;
};
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int fa[1000006];
inline int find(int x)
{
	//cout<<x;
	return fa[x]!=x?fa[x]=find(fa[x]):x;
}
inline bool merge(int a,int b)
{
	a=find(a),b=find(b);
	//cout<<a<<b<<"ab";
	if(a!=b)
	{
		fa[a]=b;
		return true;
	}
	return false;
}
void init()
{
	for(int i=1;i<=n+k;i++)fa[i]=i;
}
vector<edge> E[16];
int c[106],a[16][10006];
int K[16];

struct P{
	int d,i;
};
bool operator>(P a,P b)
{
	return a.d>b.d;
}
priority_queue<P,vector<P>,greater<P> >Q;
int clac(int s)
{
	int res=0;
	init();
	while(Q.size())Q.pop();
	for(int i=0;i<=k;i++)K[i]=0;
	Q.push(P{E[0][0].w,0});
	int cnt=n;
	for(int i=0;i<k;i++)
	{
		if((s>>i)&1)
		{
			cnt++;
			res+=c[i+1];
			Q.push(P{E[i+1][0].w,i+1});
		}
	}
	while(cnt>1)
	{
		//cout<<cnt<<"--\n"; 
		P p=Q.top();
		Q.pop();
		if(merge(E[p.i][K[p.i]].u,E[p.i][K[p.i]].v))
		{
			res+=E[p.i][K[p.i]].w;
			cnt--;
		}
		K[p.i]++;
		if(K[p.i]<E[p.i].size())Q.push(P{E[p.i][K[p.i]].w,p.i});
	}
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		E[0].push_back(edge{u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j]; 
			E[i].push_back(edge{n+i,j,a[i][j]});
		}
	}
	vector<edge> V;
	init();
	sort(E[0].begin(),E[0].end(),cmp);
	for(int i=0;i<E[0].size();i++)
	{
		if(merge(E[0][i].u,E[0][i].v))V.push_back(E[0][i]);
	}
	E[0]=V;
	for(int i=1;i<=k;i++)sort(E[i].begin(),E[i].end(),cmp);
	int ans=1e18;// 
	for(int s=0;s<(1<<k);s++)
	{
		ans=min(ans,clac(s));
	}
	cout<<ans;
	return 0;
}