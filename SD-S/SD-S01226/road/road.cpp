#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;
typedef long long ll;

ll read() {
	ll x=0, f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	return x*f;
}

#define N 10020
#define M 1100010
#define NK 15
int n, m, k;
ll ans;
#define fi first
#define se second

#define v e[i].to
#define w e[i].val
int head[N], tot;
struct edge {int from, to, nxt; ll val; int kf;} e[M<<1];
void add_edge(int x, int y, ll z, int kf) {
	e[++tot].nxt=head[x], head[x]=tot;
	e[tot].from=x, e[tot].to=y, e[tot].val=z, e[tot].kf=kf;
}

//int tot1;
//struct edge1 {int x, y; ll z;} e1[M];
//bool operator<(edge1 x, edge1 y) {
//	return x.z<y.z;
//}

//void srt_edge() {
//	pair<ll,int> e1[M];
//	for (int x=1; x<=n; ++x) {
//		int l=0;
//		for (int i=head[x]; i; i=e[i].nxt) {
//			e1[++l]={w,v};
//		}
//		sort(e1+1, e1+l+1);
//		int p=0;
//		for (int i=head[x]; i; i=e[i].nxt) {
//			w=e1[++p].fi, v=e1[++p].se;
//		}
//	}
//}

bool vis[N];
priority_queue<pair<ll,int>> q;
namespace t4 {
	ll min_tree() {
		ll res=0;
		memset(vis, 0, sizeof(vis));
		q=priority_queue<pair<ll,int>>();
		vis[1]=1;
		for (int i=head[1]; i; i=e[i].nxt) {
			q.push({-w,v});
		}
		while (!q.empty()) {
			auto x=q.top(); q.pop();
			int &u=x.se;
//			fprintf(stderr, "%d %lld\n", u, -x.fi);
			if (vis[u]) continue;
			res+=-x.fi;
			vis[u]=1;
//			fprintf(stderr, "OK\n");
			for (int i=head[u]; i; i=e[i].nxt) {
				if (!vis[v]) q.push({-w,v});
			}
		}
		return res;
	}
}

//inline bool chk(int tc, int kf) {
//	return tc&(1<<(kf-1));
//}

ll c[NK];

ll min_tree(int tc) { // !!
	ll res=0;
	memset(vis, 0, sizeof(vis));
	q=priority_queue<pair<ll,int>>();
	vis[1]=1;
	for (int p=1; p<=k; ++p) {
		if (tc&(1<<(p-1))) continue;
		vis[n+p]=1;
	}
	for (int i=head[1]; i; i=e[i].nxt) {
		if (!(tc&e[i].kf)) continue;
		q.push({-w,v});
	}
	while (!q.empty()) {
		auto x=q.top(); q.pop();
		int &u=x.se;
		if (vis[u]) continue;
		res+=-x.fi;
		vis[u]=1;
		for (int i=head[u]; i; i=e[i].nxt) {
			if (vis[v]) continue;
			if (!(tc&e[i].kf)) continue;
			q.push({-w,v});
		}
	}
	for (int i=1; i<=n+k; ++i) assert(vis[i]);
	return res;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n=read(), m=read(), k=read();
	const int kf_all=(1<<k)-1;
	for (int i=1; i<=m; ++i) {
		int x=read(), y=read();
		ll z=read();
		add_edge(x, y,z,kf_all);
		add_edge(y,x,z,kf_all);
//		if (k==0) edge1[++tot1]={x,y,z};
	}
	ans=t4::min_tree();
	if (k==0) {
		printf("%lld\n", ans);
		return 0;
	}
	for (int i=1; i<=k; ++i) {
		c[i]=read();
		for (int j=1; j<=n; ++j) {
			ll z=read();
			add_edge(n+i, j, z, (1<<(i-1)));
			add_edge(j, n+i, z, (1<<(i-1)));
		}
	}
	for (int tc=(1<<k)-1; tc; tc--) {
//		fprintf(stderr, "-\n");
		ll res=0;
		for (int p=1; p<=k; ++p) {
//			fprintf(stderr, "%d", bool(tc&(1<<(p-1)))); // 
			if (tc&(1<<(p-1))) res+=c[p];
		}
//		fprintf(stderr, "=> %lld ", res); //
		res+=min_tree(tc);
		ans=min(res, ans);
//		fprintf(stderr, "=> %lld\n", res); // 
	}
	printf("%lld\n", ans);
	return 0;
}


