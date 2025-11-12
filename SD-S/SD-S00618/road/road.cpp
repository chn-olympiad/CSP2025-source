#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=1e4+5;
int n,m,k,u,v,w,c[15];
vector<pair<int,pair<int,int>>>g;
int fa[N];
int ans;
int find(int x) {
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
void solve1() {
	for(int i=1;i<=m;++i) {
		cin>>u>>v>>w;
		g.push_back({w,{u,v}});
//		g.push_back({w,{v,u}});
	}
	
}
void solve2() {
	solve1();
	for(int i=1;i<=k;++i) {
		cin>>c[i];
		for(int j=1;j<=n;++j) {
			cin>>w;
			g.push_back({w,{i,j}});
//			g.push_back({w,{j,i}});
		}
	} 
	sort(g.begin(),g.end());
	for(auto t:g) {
		int u=t.second.first,v=t.second.second;
		u=find(u);
		v=find(v);
		if(u!=v) {
			fa[v]=u;
			u=find(u);
			v=find(v);
			ans+=t.first;
		}
	}
	cout<<ans<<endl;
}
void solve() {
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)fa[i]=i;
//	fa[2]=3;//ceshi
//	fa[5]=2;
//	fa[7]=1;
//	fa[6]=3;
//	fa[4]=1;
//	for(int i=1;i<=n;++i)cout<<find(i)<<" ";
	solve2();
} 
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _ = 1;
//	cin>>_;
	while(_--)solve();
	return 0;
}
