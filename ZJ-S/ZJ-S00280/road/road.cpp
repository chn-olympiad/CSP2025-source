#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++ i)
#define per(i, r, l) for(int i = (r); i >= (l); -- i)

using namespace std;

const int M = 2e6 + 10, N = 1e4 + 10;
int n, m, k, s;
struct E{
	int u, v, w;
	
} p[M], h[M];
int c[N], a[12][N];
#define pii pair<int, int>
//vector<pii> g[N];
int ans = 1e15, fa[M], f[N];
int find(int k) {
	if(k == fa[k]) return k;
	return fa[k] = find(fa[k]);
}
bool cmp(E x, E y) {
	return x.w < y.w;
}
int Calc() {
	rep(i, 1, n + 1) fa[i] = i;
	int s = n, tot = 0;
	rep(i, 1, m) h[++ tot] = p[i];
	rep(i, 1, k) {
		if(f[i]) {
			int now = ++ s;
			rep(j, 1, n) {
				h[++ tot] = {now, j, a[i][j]};
			}
		}
	}
	rep(i, 1, s + 1) fa[i] = i;
	sort(h + 1, h + tot + 1, cmp);
	int res = 0, cnt = 0;
	rep(i, 1, tot) {
		int u = h[i].u, v = h[i].v, w = h[i].w,
		fu = find(u), fv = find(v);
		if(fu == fv) continue;
		fa[fv] = fu;
		++ cnt;
		res += w;
		if(cnt == s - 1) {
			break;
		}
	}
//	cout << res << '\n';
	return res;
}
void dfs(int d, int qwq) {
	if(d == k + 1) {
		ans = min(ans, Calc() + qwq);
		return ;
	}
	f[d] = 0;
	dfs(d + 1, qwq);
	f[d] = 1;
	dfs(d + 1, qwq + c[d]);
}
void solve() {
	dfs(1, 0);
	cout << ans << '\n';
}
void sub2() {
	int s = n + 1, tot = 0;
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) h[++ tot] = p[i];
	rep(i, 1, k) {
		int pos;
		rep(j, 1, n) {
			if(a[i][j] == 0) {
				pos = j;
				break;
			}
		}
		rep(j, 1, n) {
			if(j == pos) continue;
			h[++ tot] = {j, pos, a[i][j]};
		}
	}
	sort(h + 1, h + tot + 1, cmp);
	int res = 0, cnt = 0;
//	cout << "De : \n";
//	rep(i, 1, k) cout << f[i] << ' '; cout << '\n';
	rep(i, 1, tot) {
		int u = h[i].u, v = h[i].v, w = h[i].w,
		fu = find(u), fv = find(v);
		if(fu == fv || u == v) continue;
		fa[fv] = fu;
		++ cnt;
		res += w;
//		cout << u << ' ' << v << ' ' << w << '\n';
		if(cnt == n) {
			break;
		}
	}
//	cout << res << '\n';
	cout << res << '\n';
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		p[i] = {u, v, w};
	}
	int F = 1;
	rep(i, 1, k) {
		cin >> c[i];
		if(c[i] > 0) F = 0;
		int flag = 0;
		rep(j, 1, n) {
			cin >> a[i][j];
			if(a[i][j] == 0) flag = 1;
		}
		if(flag == 0) F = 0;
	}
	if(F) {
		sub2();
//		rep(i, 1, k) f[i] = 1;
//		cout << Calc();
		return 0;
	}
	if(pow(2, k) * m * 20 <= 100000000 || k == 0) {
		solve();	
		return 0;
	}
	int dp[15];
	dp[0] = Calc();
	rep(i, 1, min(5ll, k)) {
		dp[i] = dp[i - 1];
		
		f[i] = 1;
		int tmp = Calc();
		if(tmp + c[i] < dp[i]) {
			dp[i] = tmp + c[i];
		}else f[i] = 0;
//		cout << dp[i] << ' ';
	}
	cout << dp[k];
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 0
1 3 100
1 2 5
1 4 2
2 4 5
*/
