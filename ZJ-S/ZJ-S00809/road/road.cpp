#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,ans,fa[N];
struct node
{
	int x,y,z;
};
node side[M];
bool cmp(node a,node b)
{
	return a.z<b.z;
}
vector<pair<int,int>>edge[M];
int find(int x)
{
	if(x!=fa[x])
		return fa[x]=find(fa[x]);
	return fa[x];
}
void kruskal()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(side+1,side+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=side[i].x,y=side[i].y;
		if(fa[x]!=fa[y])
		{
			x=find(fa[x]);
			y=find(fa[y]);
			fa[x]=y;
			ans+=side[i].z;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		if(x>y)
			swap(x,y);
		edge[x].push_back(make_pair(y,z));
		edge[y].push_back(make_pair(x,z));
		side[i]={x,y,z};
	}
	kruskal();
	cout<<ans;
}