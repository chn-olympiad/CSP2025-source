#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
typedef pair<int,int> PII;
struct node 
{
	int u,w;
};
struct to
{
	int dist,u,v;
};
bool cmp(to a,to b)
{
	return a.dist<b.dist;
}
int n,m,k;
vector <node> g[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	queue<to> q;
	for (node e:g[1]) q.push({e.w,1,e.u});
	int ans=0,ansn=1;
	while (q.size())
	{
		to t=q.top();
		q.pop();
		int u=t.u,v=t.v,dist=t.dist;
		ans+=dist;
		ansn++;
		if (ansn>=n) break;
		for (node e:g[v])
		{
			int vv=e.u,w=e.w;
			q.push({dist+w,v,vv});
		}
	}
	cout<<ans;
	return 0;
}

