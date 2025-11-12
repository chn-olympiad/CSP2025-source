#include<bits/stdc++.h>
using namespace std;
int n,m,k,dsu[1000020];
struct node
{
	int u,v,w;
	bool operator<(const node& rhs) const { return w<rhs.w; }
};
vector <node> ed;
int find(int u) { return dsu[u]==u ? u:dsu[u]=find(dsu[u]); }
void unite(int u,int v) {dsu[find(u)]=dsu[find(v)]; }
long long kruskal()
{
	long long ret=0,cnt=0;
	for(auto [u,v,w]:ed)
	{
		if(find(u)!=find(v)) cnt++,ret+=w,unite(u,v);
		if(cnt==n-1) return ret;
	}
	return -1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,ed.push_back({u,v,w});
		sort(ed.begin(),ed.end());
		for(int i=1;i<=n;i++) dsu[i]=i;
		cout<<kruskal()<<"\n";
	}
	return 0;
}