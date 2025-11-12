#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,u,v,w,g[10001][10001],c[11],a[11][10001],f[10001][10001],ans,res = 4000000000000000000;
bool vis[10001];
struct node {
	int p,d;
	bool operator< (const node& a1) const {
		return d > a1.d;
	}
};

void Prim() {
	priority_queue<node> q;
	q.push({1,0});
	while(!q.empty()) {
		node nd = q.top();
		q.pop();
		if(vis[nd.p]) continue;
		//cout << nd.p << ' ' << nd.d << endl;
		vis[nd.p] = 1;
		ans += nd.d;
		if(ans >= res) break;
		for(int i = 1; i <= n; i++) {
			if(!vis[i] && f[nd.p][i] <= 2000000000) {
				q.push({i,f[nd.p][i]});
			}
		}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	memset(g,0x3f,sizeof g);
	for(int i = 1; i <= m; i++) {
		scanf("%lld%lld%dll",&u,&v,&w);
		g[u][v] = g[v][u] = w;
	}
	for(int i = 1; i <= k; i++) {
		scanf("%lld",&c[i]);
		for(int j = 1; j <= n; j++) scanf("%d",&a[i][j]);
	}
	for(int i = 0; i < (1 << k); i++) {
		ans = 0;
		for(int x = 1; x < n; x++) {
			for(int y = x + 1; y <= n; y++) {
				f[x][y] = f[y][x] = g[x][y];
			}
		}
		for(int j = 1; j <= k; j++) {
			if(i >> (j - 1) & 1) {
				ans += c[j];
				for(int x = 1; x < n; x++) {
					for(int y = x + 1; y <= n; y++) {
						f[x][y] = f[y][x] = min(f[x][y],a[j][x] + a[j][y]);
					}
				}
			}
		}
		for(int j = 1; j <= n; j++) vis[j] = 0;
		Prim();
		res = min(res,ans);
	}
	printf("%lld",res);
	return 0;
}
