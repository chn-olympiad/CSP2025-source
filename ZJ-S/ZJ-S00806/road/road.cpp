#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define per(i, r, l) for(int i = r; i >= l; --i)
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, fa[N << 1], ans, tot, c[15], a[15][N];
struct node{
	int x, y, w;
}edg[M << 1], tmp[M];
bool cmp(node a, node b){
	return a.w < b.w;
}
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) cin >> edg[i].x >> edg[i].y >> edg[i].w;
	sort(edg + 1, edg + m + 1, cmp);
	rep(i, 1, m){
		int x = find(edg[i].x), y = find(edg[i].y);
		if (x == y) continue;
		fa[x] = y;
		tmp[++tot] = edg[i];
		ans += edg[i].w;
	}
	rep(i, 1, tot) edg[i] = tmp[i];
	m = tot;
	rep(i, 1, k){
		cin >> c[i];
		rep(j, 1, n) cin >> a[i][j];
	}
	rep(s, 0, (1 << k) - 1){
		int cnt = 0;
		rep(i, 1, n + k) fa[i] = i;
		rep(i, 1, tot) edg[i] = tmp[i];
		m = tot;
		rep(t, 1, k){
			if(s >> t - 1 & 1){
				cnt += c[t];
				rep(i, 1, n){
					edg[++m] = {n + t, i, a[t][i]};
				}
			}
		}
		sort(edg + 1, edg + m + 1, cmp);
		rep(i, 1, m){
			int x = find(edg[i].x), y = find(edg[i].y);
			if (x == y) continue;
			fa[x] = y;
			cnt += edg[i].w;
		}
		ans = min(ans, cnt);
	}
	cout << ans << '\n'; 
	return 0;
}

