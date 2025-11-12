#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn=2e7+5;
const int maxm=1e4+5;
const ll INF=1e18;
ll T,n,m,k,f[maxn],c[maxn],cost[maxm][15];
struct node{
	ll u,v,w;
}a[maxn];
struct edge{
	ll nxt,w,id;
};
ll dis[maxm][maxm/2]; 
ll find(ll x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
void Union(ll u,ll v) {
	if(find(u)!=find(v)) f[find(u)]=find(v);
}
bool check(ll u,ll v) {
	return find(u)==find(v);
}
void wzp(){
	sort(a+1,a+m+1,[](node x,node y){
		return x.w<y.w;
	});
	ll res=0;
	ll cnt=0;
	for(int i=1;i<=m;i++) {
		if(!check(a[i].u,a[i].v)) {
			Union(a[i].u,a[i].v);
			res+=a[i].w;
			cnt++;
//			cout << a[i].u << " "<< a[i].v << " "<< a[i].w << "\n";
		}
		if(cnt==n-1) {
			cout << res << "\n";
			return ;
		}
	}
//	cout << res << "\n";
}
void solve() {
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) {
		f[i]=i;
	}
	for(int i=1;i<=m;i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
		dis[max(a[i].u,a[i].v)][min(a[i].u,a[i].v)]=a[i].w;
//		dis[a[i].u]=min(dis[a[i].u],a[i].w);
//		dis[a[i].v]=min(dis[a[i].v],a[i].w);
	}
	if(k==0) {
		wzp();
		return ;
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		queue<pll> q;
		for(int j=1;j<=n;j++) {
			cin >> cost[i][j];
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			for(int tmp=1;tmp<=k;tmp++) {
				dis[j][i]=min(cost[tmp][j]+cost[tmp][i],dis[j][i]);
			}
		}
	}
	m=0;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			a[++m].u=i;
			a[m].v=j;
			a[m].w=dis[j][i];
		}
	}
	wzp();
}
int main() {
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cin >> T;
//	while(T--) {
		solve();
//	}
}
