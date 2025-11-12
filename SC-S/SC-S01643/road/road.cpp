//dzzfjldyqqwsxdhrdhcyxll
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 10;
const int MAXM = 1e6 + 10;
const int MAXK = 15;
int n,m,k,fa[MAXN],cnt,c[MAXN],f[MAXK][MAXN],ans = 1e18,s[MAXN];
struct Node {
	int u,v,w;
}a[MAXM],b[MAXN];
inline int Find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}
inline bool cmp(Node x,Node y) {
	return x.w < y.w;
}
signed main() {
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k; 
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1,a + m + 1,cmp);
	for(int i = 1;i <= m;i++) {
		if(Find(a[i].u) != Find(a[i].v)) {
			fa[Find(a[i].u)] = a[i].v;
			b[++cnt] = {a[i].u,a[i].v,a[i].w};
		}
	} 
	for(int i = 1;i <= k;i++) {
		cin >> c[i];
		for(int j = 1;j <= n;j++) {
			cin >> f[i][j];
			b[++cnt] = {n + i,j,f[i][j]};
		}
	}
	sort(b + 1,b + cnt + 1,cmp);
	for(int i = 0;i < (1ll << k);i++) {
		for(int j = 1;j <= n + k;j++) fa[j] = j,s[j] = 1;
		int sum = 0;
		for(int j = 1;j <= k;j++) {
			if((i >> (j - 1)) & 1) sum += c[j];
		}
		for(int j = 1;j <= cnt;j++) {
			if(b[j].u > n && !((i >> (b[j].u - n - 1)) & 1)) continue;
			if(b[j].v > n && !((i >> (b[j].v - n - 1)) & 1)) continue;
			int u = Find(b[j].u),v = Find(b[j].v);
			if(u != v) {
				if(s[u] < s[v]) fa[u] = v,s[v] += s[u];
				else fa[v] = u,s[u] += s[v]; 
				sum += b[j].w;
			}
		}
		ans = min(ans,sum);
	}
	cout << ans;
	return 0;
}