#include <bits/stdc++.h>
#define fi first
#define se second
#define mkp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=1e4+15, K=12, M=1e6+15;
int n, m, k, fa[N], c[K], b[K][N], cnt;
ll ans=0x3f3f3f3f3f3f3f3f, res, sum[(1<<K)+10];
struct qwq {
	int u, v, w;
} a[M+N*K];

int find(int x) {
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

bool mycmp(qwq x, qwq y) {
	return x.w < y.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1, a+m+1, mycmp);
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) 	cin>>b[i][j];
	}
	if(!k) {
		for(int i=1; i<=m; i++) {
			int u=find(a[i].u), v=find(a[i].v);
			if(u==v) continue;
			fa[u]=v;
			ans+=a[i].w; ++cnt;
			if(cnt==n-1) break;
		}
	} else {
		int tot=0;
		for(int i=1; i<=m; i++) {
			int u=find(a[i].u), v=find(a[i].v);
			if(u==v) continue;
			fa[u]=v;
			a[++tot]=a[i]; ++cnt;
			if(cnt==n-1) break;
		}	
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) a[++tot]={i+n, j, b[i][j]};
		}
		sort(a+1, a+tot+1, mycmp);
		for(int p=1; p<1<<k; p++) sum[p]=sum[p^p&-p]+1ll*c[__lg(p&-p)+1];
		for(int p=0; p<1<<k; p++) {
			for(int i=1; i<=n+k; i++) fa[i]=i;
			int t=__builtin_popcount(p);
			cnt=0; res=0;
			for(int i=1; i<=tot; i++) {
				int u=find(a[i].u), v=find(a[i].v);
				if(u==v||(a[i].u>n&&!((p>>(a[i].u-n-1))&1))) continue;
				fa[u]=v;
				res+=1ll*a[i].w; ++cnt;
				if(cnt==n+t-1) break;
			}	
			ans=min(ans, res+sum[p]);
		}
	}
	cout<<ans;
	return 0;
}

