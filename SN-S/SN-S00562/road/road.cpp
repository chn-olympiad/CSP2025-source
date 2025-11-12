#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

int fa[10020], siz[10020];
ll cost[12];
int n, m, K, used;
vector<tuple<int, int, ll>> oldE, addE[12], nowE, tmpE, cur[12];
ll ans;

void clear() {
	used = 0;
	for (int i=1; i<=n+K; ++i) {
		fa[i] = i;
		siz[i] = 1;
	}
}

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return 0;
	if (siz[x] < siz[y]) swap(x, y);
	siz[x] += siz[y];
	fa[y] = x;
	return 1;
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> K;
	for (int i=1; i<=m; ++i) {
		int x, y; ll w;
		cin >> x >> y >> w;
		oldE.emplace_back(x, y, w);
	}
	sort(oldE.begin(), oldE.end(), [](auto &x, auto &y){
		return get<2>(x) < get<2>(y);
	});
	clear();
	for (int id=0; id<m; ++id) {
		int x, y; ll w;
		tie(x, y, w) = oldE[id];
		if (merge(x, y)) {
			++used;
			tmpE.emplace_back(x, y, w);
			ans += w;
			if (used == n - 1) break;
		}
	}
	addE[0] = tmpE;
	tmpE.clear();
	oldE.clear();
	reverse(addE[0].begin(), addE[0].end());
	
	for (int x=1; x<=K; ++x) {
		cin >> cost[x];
		for (int y=1; y<=n; ++y) {
			ll w; cin >> w;
			addE[x].emplace_back(x+n, y, w);
		}
		sort(addE[x].begin(), addE[x].end(), [](auto &x, auto &y){
			return get<2>(x) > get<2>(y);
		});
	}
	
	for (int sta=1; sta<(1<<K); ++sta) {
		int N = n;
		cur[0] = addE[0];
		ll res = 0;
		vector<int> okidx{0};
		for (int i=0; i<K; ++i) {
			if ((sta>>i)&1) {
				++N;
				res += cost[i+1];
				okidx.push_back(i+1);
				cur[i+1] = addE[i+1];
			}
		}
		clear();
		while (used < N - 1) {
			int id = -1;
			int x, y; ll w;
			for (int i : okidx) {
				if (cur[i].empty()) continue;
				int tx, ty; ll tw; 
				tie(tx, ty, tw) = cur[i].back();
				if (find(tx) == find(ty)) continue;
				if (id == -1 || tw < w) {
					id = i;
					x = tx; y = ty; w = tw;
				}
			}
			if (id == -1) {
//				exit(0);
//				cerr << used << ' ' << N << ' ' << bitset<10>(sta) << '\n';
				for (int i : okidx) {
//					cerr << cur[i].size() << '\n';
					if (cur[i].size()) cur[i].pop_back();
				}
				continue;
//				exit(0);
			} 
			merge(x, y);
			++used;
			res += w;
			cur[id].pop_back();
		}
		ans = min(ans, res);
		
	}
	cout << ans << '\n';
	return 0;
}

