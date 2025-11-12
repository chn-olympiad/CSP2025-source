#include<bits/stdc++.h>
using namespace std;
int n,m,k,cn,head[4000010],fa[10020],nn;
struct A
{
	int xx,yy,dis;
	bool operator <(const A &x)const
	{
		return x.dis<dis;
	}
};
priority_queue<A> q;
void add(int u,int v,int w)
{
	q.push((A){u,v,w});
}
int find(int x)
{
	if(x==fa[x])
		return fa[x];
	return fa[x]=find(fa[x]);
}
long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	nn=n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	int a;
	for(int i=1;i<=k;i++)
	{
		cin>>a;
		if(a!=0)
			break;
		nn++;
		for(int j=1;j<=n;j++)
		{
			int xx;
			cin>>xx;
			add(nn,j,xx);
		}
	}
	while(!q.empty())
	{
		int x=q.top().xx,y=q.top().yy,dis=q.top().dis;
		q.pop();
		int nx=find(x),ny=find(y);
		if(nx==ny)
			continue;
		ans+=dis;
		fa[ny]=nx;
	}
	cout<<ans;
	return 0;
}
/*
5 7 0
1 4 6
4 5 3
1 5 2
2 4 5
3 4 4
2 3 7
3 5 5

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/