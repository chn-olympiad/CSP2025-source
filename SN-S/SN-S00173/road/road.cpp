#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge {
	int u,v;
	long long w;
};
vector<edge> e;

int fa[10050];
int find(int x) {
	if(x==fa[x]) {
		return x;
	} else {
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void unn(int x,int y) {
	fa[find(x)]=find(y);
}
bool cmp(edge p,edge q) {
	return p.w<q.w;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n+k; i++) {
		fa[i]=i;
	}
	for(int i=1; i<=m; i++) {
		int u,v;
		long long w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1; i<=k; i++) {
		long long w;
		cin>>w;
		for(int j=1; j<=n; j++) {
			cin>>w;
			e.push_back({n+i,j,w});
		}
	}
	sort(e.begin(),e.end()+1,cmp);
	long long res=0;
	for(int i=1; i<=e.size(); i++) {
		if(find(e[i].u)!=find(e[i].v)) {
			res+=e[i].w;
			unn(e[i].u,e[i].v);
		}
	}
	cout<<res;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
