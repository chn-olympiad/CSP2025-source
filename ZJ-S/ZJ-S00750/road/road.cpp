#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
	int operator <(const node &r)const
	{
		return z>r.z;
	}
};
int n,m,k,c,f,mx,sz[10100],fa[10100],sum;
bool flag=1;
priority_queue<node> q;
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void uno(int x,int y)
{
	int nx=find(x);
	int ny=find(y);
	if(nx==ny) return ;
	fa[nx]=ny;
	sz[ny]+=sz[nx];
	mx=max(mx,sz[ny]);
}
void kr()
{
	while(!q.empty())
	{
		int x=q.top().x,y=q.top().y,z=q.top().z;
		q.pop();
		if(find(x)==find(y)) continue;
		uno(x,y);
		sum+=z;
		if(mx==n) return ;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		q.push({x,y,z});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		if(c!=0) flag=0;
		for(int j=1;j<=n;j++)
		{
			cin>>f;
			if(f!=0) flag=0;
		}
	}
	if(k!=0 && flag)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	kr();
	cout<<sum<<"\n";
	return 0;
}