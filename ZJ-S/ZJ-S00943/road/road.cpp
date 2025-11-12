#include<bits/stdc++.h>
const int N=1e4+10;
const int M=1e6+10;
using namespace std;
int n,m,k;
struct E {
	int v,w;
};
struct M {
	int u,v,w;
	bool operator<(const M &y)const {
		return w<y.w;
	}
} e[M];
//vector<E> g[N];
typedef long long LL;
int c[15];
int a[15][N];
int fa[N],siz[N];

int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void merge(int x,int y) {
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(siz[x]>siz[y]) swap(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
}

long long kruskal(int cnt) {
	LL ans=0;
	for(int i=1; i<=m; i++) {
		int u=e[i].u,v=e[i].v,w=e[i].w;
//		auto [u,v,w]=e[i];
		if(find(u)!=find(v)) {
			merge(u,v);
			ans+=w;
			cnt--;
			if(cnt==0) break;
		}
	}
	return ans;
}
void solve1() {
	cout << kruskal(n-1);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;

	for(int i=1; i<=n; i++) fa[i]=i,siz[i]=1;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
//		g[u].push_back({v,w});
//		g[v].push_back({u,w});
		e[i]= {u,v,w};
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	}
	sort(e+1,e+m+1);
	if(k==0) {
		solve1();
		return 0;
	}
	return 0;
}

