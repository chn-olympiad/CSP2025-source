#include<bits/stdc++.h>
#define maxn int(1e4+200)
#define maxm int(2e6+5)
#define maxk 12
#define ll long long
using namespace std;
ll n, m, M, k, c[maxk], book[maxn], ans;
//ll a[maxk][maxn];
//ll dis[maxn], vis[maxn], viscnt;
ll fa[maxn];
//struct e{int v, w;};
struct edge{ll u, v, w;} edges[maxm];
bool cmp(edge x, edge y) {return x.w<y.w;}
//queue<e> que;
//vector<e> G[maxn];
int findfa(int x) {
	if(fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}
ll solve(int cnt) {
	for(int i = 1; i <= n+k; i++) fa[i]=i;
	int N = n+cnt, chosen=0;
	ll ret=0;
	for(int i = 1; i <= M; i++) {
		if(book[edges[i].u] && book[edges[i].v]
		&& findfa(edges[i].u)!=findfa(edges[i].v)) {
//			cout<<edges[i].u<<edges[i].v<<endl;
			fa[findfa(edges[i].u)]=findfa(edges[i].v);
			chosen++;
			ret+=edges[i].w;
			if(chosen==N-1) break;
		}
	}
//	if(chosen<N-1) cout<<"ERROR"<<endl;
//	cout<<ret<<endl;
	return ret;
}
void dfs(ll x, ll cnt, ll sum) {
	if(x==k+1) {
//		for(int i = n+1; i <= n+k; i++) {
//			cout<<book[i]<<' ';
//		}cout<<endl;
		ans=min(ans, sum+solve(cnt));
		return;
	}
	book[n+x]=0;
	dfs(x+1, cnt, sum);
	book[n+x]=1;
	dfs(x+1, cnt+1, sum+c[x]);
	return;
}
inline ll read() {
	char ch=getchar();
	ll ret=0;
	while(isdigit(ch)) {
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll w;
	n=read(); m=read(); k=read();
	for(int i = 1; i <= n; i++) book[i]=1;
	ans=LLONG_MAX;
	for(int i = 1; i <= m; i++) {
		edges[i].u=read(); edges[i].v=read(); edges[i].w=read();
//		G[u].push_back({v,w});
//		G[v].push_back({u,w});
	}
	for(int i = 1; i <= k; i++) {
		c[i]=read();
		for(int j = 1; j <= n; j++) {
			w=read();
			edges[m+n*(i-1)+j]=(edge){n+i, j, w};
//			G[i].push_back({n+j,a[i][j]});
//			G[n+j].push_back({i,a[i][j]});
		}
	}
	M=m+k*n;
	sort(edges+1, edges+(M+1), cmp);
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
