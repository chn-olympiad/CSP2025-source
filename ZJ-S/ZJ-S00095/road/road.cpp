#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
struct Edge {
	int u,v;
	long long w;
};
bool cmp(Edge a,Edge b) {
	return a.w<b.w;
}
Edge e[1500000];
long long c[20];
bool vis[20];
long long ans=1e18;
int fa[10020];
void init() {
	for(int i=1; i<=n+k; i++)
		fa[i]=i;
	return;
}
int find(int u) {
	if(fa[u]==u)
		return u;
	return fa[u]=find(fa[u]);
}
void kru(long long sum) {
	init();
	for(int i=1; i<=m; i++)
		if(e[i].u<=n||(vis[e[i].u-n])) {
			int u=find(e[i].u),v=find(e[i].v);
			if(u!=v) {
				fa[u]=v;
				sum+=e[i].w;
			}
		}
	ans=min(sum,ans);
	return;
}
void dfs(int i,long long sum) {
	if(i>k) {
		kru(sum);
		return;
	}
	vis[i]=1;
	dfs(i+1,sum+c[i]);
	vis[i]=0;
	dfs(i+1,sum);
	return;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			++m;
			e[m].u=n+i;
			e[m].v=j;
			cin>>e[m].w;
		}
	}
	sort(e+1,e+m,cmp);
	dfs(1,0);
	cout<<ans;
	return 0;
}