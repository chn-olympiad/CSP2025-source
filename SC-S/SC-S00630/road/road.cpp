#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e4 + 5,M = 1e6 + 5,K = 11;
int n,m,k,c[K],a[K][N],f[N];
ll minn[K][N],res[N][K],g[N][1 << K],mn[N],te[K];
array <int,3> e[M + N * K],mst[N];

void read(int &x) {
	int res = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {
		res = (res << 3) + (res << 1) + (ch ^ 48);
		ch = getchar();
	}
	x = res;
}  

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

void solve() {
	read(n),read(m),read(k);
	for(int i = 1;i <= m;i++) {
		read(e[i][1]),read(e[i][2]),read(e[i][0]);
	}
	bool ok = true;
	for(int i = 1;i <= k;i++) {
		read(c[i]);
		bool flg = false;
		for(int j = 1;j <= n;j++) read(a[i][j]),minn[i][j] = a[i][j],flg |= a[i][j] == 0;
		if(!flg || c[i] != 0) ok = false; 
	}
	if(ok) {
		for(int i = 1;i <= k;i++) {
			int idx = 0;
			for(int j = 1;idx == 0 && j <= n;j++) if(a[i][j] == 0) idx = j;
			for(int j = 1;j <= n;j++) if(j != idx) e[++m] = {a[i][j],idx,j};
		}
		sort(e + 1,e + m + 1);
		for(int i = 1;i <= n;i++) f[i] = i;
		int cnt = 0;
		ll ans = 0;
		for(int i = 1;i <= m;i++) {
			int u = e[i][1],v = e[i][2],w = e[i][0];
			int x = find(u),y = find(v);
			if(x == y) continue;
			f[x] = y;
			ans += w;
			cnt++;
			if(cnt == n - 1) break;
		}
		printf("%lld",ans);
		return ;
	}
	sort(e + 1,e + m + 1);
	for(int i = 1;i <= n;i++) f[i] = i;
	int cnt = 0;
	ll ans = 0;
	for(int i = 1;i <= m;i++) {
		int u = e[i][1],v = e[i][2],w = e[i][0];
		int x = find(u),y = find(v);
		if(x == y) continue;
		f[x] = y;
		ans += w;
		mst[++cnt] = {x,y,w};
		if(cnt == n - 1) break;
	}
	if(k <= 5) {
		for(int i = 1;i <= n;i++) f[i] = i;
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j < (1 << k);j++) g[i][j] = Inf;
			g[i][(1 << k) - 1] = 0;
		}
		for(int i = 1;i < n;i++) {
			int u = mst[i][0],v = mst[i][1],w = mst[i][2];
			u = find(u),v = find(v);
			for(int j = 0;j < (1 << k);j++) te[j] = Inf;
			for(int j = 0;j < (1 << k);j++)
				for(int x = 0;x < (1 << k);x++) {
					int t = (j & x);
					te[t] = min(te[t],g[u][j] + g[v][x] + w);
					for(int l = 0;l < k;l++) {
						ll s = 0;
						int tmp = t;
						if(j >> l & 1) s += a[l + 1][u];
						if(x >> l & 1) s += a[l + 1][v];
						if(j >> l & 1 && x >> l & 1) tmp -= 1 << l;
						if(s <= w) te[tmp] = min(te[tmp],g[u][j] + g[v][x] + s);
					}
				}
			for(int i = 0;i < (1 << k);i++) g[v][i] = te[i]; 
			for(int j = 1;j <= k;j++) a[j][v] = min(a[j][v],a[j][u]);
			f[u] = v;
		}
		ll ans = Inf;
		for(int i = 0;i < (1 << k);i++) {
			ll sum = 0;
			for(int j = 1;j <= k;j++) if(!(i >> (j - 1) & 1)) sum += c[j];
			ans = min(ans,sum + g[find(1)][i]);
		}
		printf("%lld",ans);
		return ;
	}
	ll ans2 = Inf;
	for(int i = 0;i < (1 << k);i++) {
		ll tmp = ans;
		for(int j = 1;j <= k;j++)
			if(i >> (j - 1) & 1) tmp += c[j];
		for(int j = 1;j <= n;j++) f[j] = j;
		for(int j = 1;j <= k;j++)
			for(int x = 1;x <= n;x++)
				a[j][x] = minn[j][x];
		for(int j = 1;j < n;j++) {
			int u = mst[j][0],v = mst[j][1],w = mst[j][2];
			u = find(u),v = find(v);
			int minn = w;
			for(int x = 1;x <= k;x++) if(i >> (x - 1) & 1) minn = min(minn,a[x][u] + a[x][v]);
			f[u] = v;
			tmp += minn - w;
			if(minn == w) {
				for(int x = 1;x <= k;x++)
					if(i >> (x - 1) & 1) a[x][v] = min(a[x][v],a[x][u]);
				continue;
			}
			for(int x = 1;x <= k;x++) {
				if(!(i >> (x - 1) & 1)) continue;
				if(a[x][u] + a[x][v] == minn) {
					for(int x = 1;x <= k;x++)
						if(i >> (x - 1) & 1) a[x][v] = min(a[x][v],a[x][u]);
					a[x][u] = a[x][v] = 0;

					break;
				}
			}
		}
		ans2 = min(ans2,tmp);
	}
	printf("%lld",ans2);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T = 1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}