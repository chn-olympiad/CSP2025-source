/*
我要能拿1=。我直播吃我的luogu用户名后六位。。。。。 
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 3e4 + 10;

const ll M = 2e6 + 10;

struct node{
	ll u, v, w;
} V[M], V1[M];

bool cmp(node x, node y) {
	return x.w < y.w;
}

ll F[N * 10];

ll W[20], C[12][N];

ll find_father(ll x) {
	if (x == F[x]) return x;
	F[x] = find_father(F[x]);
	return F[x];
} 

ll fx, fy;

void merge_set(ll x, ll y) {
	fx = find_father(x);
	fy = find_father(y);
	F[fx] = fy;
}

ll book[20], yncc[100000];

ll n, m, k, u, v, w, w1, ans = LLONG_MAX, tp, b, tans, tw;

void dfs(ll x) {
	if (x == k + 1) {
		ll tm;
		tm = m;
		tp = 0;
		tw = 0;
		for (int i = 1; i <= k; i++) {
			if (book[i]) {
				tw += W[i];
				tp = tp & (1 << (i - 1));
				for (int j = 1; j <= n; j++) {
					tm++;
					V[tm].u = n + i;
					V[tm].v = j;
					V[tm].w = C[i][j];
				}
			}
		}
		if (yncc[tp]) {
			for (int i = 1; i <= k; i++) yncc[tp & (1 << (i - 1))] = 1;
			return;
		}
		for (int i = 1; i <= n + k; i++) F[i] = i;
		for (int i = 1; i <= m; i++) V[i].u = V1[i].u, V[i].v = V1[i].v, V[i].w = V1[i].w;
		sort(V + 1, V + 1 + tm, cmp);
		tans = 0;
		for (int i = 1; i <= tm; i++) {
			if (find_father(V[i].u) == find_father(V[i].v)) continue;
			merge_set(V[i].u, V[i].v);
			tans += V[i].w;
			if (tans + tw > b) {
				yncc[tp] = 1;
				for (int i = 1; i <= k; i++) yncc[tp & (1 << (i - 1))] = 1;
				return;
			}
		}
		if (LLONG_MAX == ans) {
			ans = tans;
			b = ans;
		} else {
			if (tans + tw > b) {
				yncc[tp] = 1;
				for (int i = 1; i <= k; i++) yncc[tp & (1 << (i - 1))] = 1;
			}
			ans = min(ans, tans + tw);
		}
		return;
	}
	dfs(x + 1);
	book[x] = 1;
	dfs(x + 1);
	book[x] = 0;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> V[i].u >> V[i].v >> V[i].w;
		V1[i].u = V[i].u;
		V1[i].v = V[i].v;
		V1[i].w = V[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> W[i];
		for (int j = 1; j <= n; j++) cin >> C[i][j];
	}
	dfs(1);
	cout << ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
