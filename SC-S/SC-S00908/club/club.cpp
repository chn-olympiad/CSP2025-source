#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define f(i,x,y) for(int i=x;i<=y;++i)
class FoStar {
private:
	struct edge {
		int u, v, w, to;
	};
	vector<int> head;
	vector<edge> edges;
	int cnt = 0;
public:
	FoStar(size_t sz): head(sz), edges(sz) {}
	void add(int u, int v, int w) {
		edges[++cnt] = {u, v, w, head[u]};
		head[u] = cnt;
	}
	edge &operator[](int u) {
		return edges[u];
	}
};
class DSU {
private:
	vector<int> fa;
public:
	DSU(size_t sz): fa(sz) {
		iota(fa.begin(), fa.end(), 0);
	}
	int find(int x) {
		if (fa[x] == x)return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int u, int v) {
		int fu = find(u), fv = find(v);
		fa[fu] = fv;
	}
};
using ppipi = pair<pair<int, int>, pair<int, int>>;
using pii = pair<int, int>;
using tiiii = tuple<int, int, int, int>;
const int maxn = 1e5+5;
int t, n;
pair<int, int> a[maxn][5];
void solve() {
	int ans = 0;
	cin >> n;
	f(i, 1, n) cin >> a[i][1].first >> a[i][2].first >> a[i][3].first, a[i][1].second = 1, a[i][2].second = 2, a[i][3].second = 3;
	f(i, 1, n) sort(a[i] + 1, a[i] + 4);
	priority_queue<tiiii, vector<tiiii>, greater<tiiii>> q[4];
	f(i, 1, n) {
		int id = a[i][3].second, val = a[i][3].first;
		if (q[id].size() < n / 2) q[id].push({val - a[i][2].first, val, i, id});
		else {
			auto [lost,cur_val,cur_i,cur_j] = q[id].top();
			int val1 = val-lost,val2 = a[i][2].first,val3 = a[i][3].first;
			if(val1>val2) q[id].pop(),q[id].push({val-val2,val,i,id}),q[a[cur_i][2].second].push({a[cur_i][2].first-a[cur_i][3].first,a[cur_i][2].first,cur_i,cur_j});
			else q[a[i][2].second].push({val2-val3,val2,i,a[i][2].second});
		}
	}
	while(q[1].size()||q[2].size()||q[3].size()){
		if(q[1].size()) {
			auto [lost,val,i,j] = q[1].top();
			q[1].pop();
			ans+=val;
		}
		if(q[2].size()) {
			auto [lost,val,i,j] = q[2].top();
			q[2].pop();
			ans+=val;
		}
		if(q[3].size()) {
			auto [lost,val,i,j] = q[3].top();
			q[3].pop();
			ans+=val;
		}
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--) solve();
	return 0;
}