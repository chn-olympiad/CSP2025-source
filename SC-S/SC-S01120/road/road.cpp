#include<bits/stdc++.h>
using namespace std;
const long long N = 2e4+10, M = 2e6+5;
struct nd {
	long long u, v, w;
} o[M];
bool cmp(nd p, nd q) {
	return p.w < q.w;
}
struct ndd {
	long long v, w;
};
long long n, m, k, cnt, f[N], h[N], c[N], a[N][12], ut,y=0;
long long find(long long x) {
	return x == f[x] ? x : x = find(f[x]);
}
void merge(long long x, long long y) {
	x = find(x), y = find(y);
	if (h[x] < h[y]) swap(x, y);
	if (h[x] == h[y]) {
		h[x]++;
	}
	f[y] = x;
	return ;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	ut = n;
	long long uu, vv, ww;
	for (long long i = 1; i <= m; i++) {
		cin >> uu >> vv >> ww;
		o[++cnt].u = uu;
		o[cnt].v = vv;
		o[cnt].w = ww;
	}
	long long fl = 1;
	for (long long i = 1; i <= n; i++) f[i] = i, h[i] = 1;
	for (long long i = 1; i <= k; i++) {
		int vx = i + 10005;
		cin >> c[i];
		y=max(y,c[i]);
		h[vx] = 1;
		f[vx] = vx;
		queue<long long> r;
		for (long long j = 1; j <= n; j++) {
			cin >> a[j][i];
			o[++cnt].u = j;
			o[cnt].v = vx;
			o[cnt].w = a[j][i];
			if (a[j][i] == 0) r.push(j);
		}
		if (fl && c[i] == 0) {
			ut++;
			long long uv = 0;
			while (!r.empty()) {
				ut--;
				long long j = r.front();
				r.pop();
				if (uv == 0) {
					merge(vx, j);
					uv = j;
				} else {
					merge(uv, j);
				}
			}
		} else fl = 0;
	}
	if (!ut) {
		cout << 0;
		return 0;
	}
	if (k == 0) {
		long long ans = 0;
		sort(o + 1, o + cnt + 1, cmp);
		long long u, v, w;
		for (long long i = 1; i <= cnt; i++) {
			u = o[i].u, v = o[i].v, w = o[i].w;
			if (find(u) != find(v)) {
				merge(u, v);
				ans += w;
				ut--;
			}
			if (!ut) break;
		}
		cout << ans;
	} else if (fl) {
		long long ans = 0;
		sort(o + 1, o + cnt + 1, cmp);
		long long u, v, w;
		for (long long i = 1; i <= cnt; i++) {
			u = o[i].u, v = o[i].v, w = o[i].w;
			if (find(u) != find(v)) {
				ut--;
				merge(u, v);
				ans += w;
			}
			if (!ut) break;
		}
		cout << ans;
	} else {
		cout<<y;
	}
	return 0;
}