#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

struct P {
	int a, b, c;

	void update(int k, int v) {
		if (k == 1)
			a = v;
		else if (k == 2)
			b = v;
		else if (k == 3)
			c = v;
	}

	const int get(int k) const {
		if (k == 1)
			return a;
		else if (k == 2)
			return b;
		else if (k == 3)
			return c;
		return a;
	}

	// 从 x 换到别的岗位的收益
	const int cost(int x) const {
		int maxx = 0;
		for (int i = 1; i <= 3; i++) {
			if (i == x)
				continue;
			maxx = max(maxx, get(i));
		}

		return get(x) - maxx;
	}

	const bool operator < (const P &x) const {
		return a < x.a;
	}
} a[N];

int n, ans;
int cnt[5], val[5];
bool flag[5];

void dfs(int p) {
	if (p == n + 1) {
		ans = max(ans, val[1] + val[2] + val[3]);
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if ((cnt[i] + 1) * 2 <= n) {
			cnt[i]++;
			val[i] += a[p].get(i);

			dfs(p + 1);

			cnt[i]--;
			val[i] -= a[p].get(i);
		}
	}
}

void solve() {
	memset(a, 0, sizeof a);
	memset(cnt, 0, sizeof cnt);
	memset(flag, 0, sizeof flag);
	memset(val, 0, sizeof val);

	ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].b >> a[i].c;
	}

	if (n <= 10) {
		dfs(1);
		cout << ans << "\n";
		return;
	}

	vector<priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>>> pq(5,
	        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>>());

	for (int i = 1; i <= n; i++) {
		int maxx =  max({a[i].a, a[i].b, a[i].c});
		// 最喜欢 a 部门
		if (a[i].a == maxx) {
//			cerr << "to 1\n";
			pq[1].push({
				a[i].cost(1),
				a[i]
			});
		} else if (a[i].b == maxx) {
//			cerr << "to 2\n";
			pq[2].push({
				a[i].cost(2),
				a[i]
			});
		} else {
//			cerr << "to 3\n";
			pq[3].push({
				a[i].cost(3),
				a[i]
			});
		}
	}

//	cerr << "\n";
//	for (int i = 1; i <= 3; i++)
//		cerr << pq[i].size() << " ";
//	cerr << "\n";

	for (int k = 1; k <= 5; k++) {
		for (int i = 1; i <= 3; i++) {
			while (pq[i].size() * 2 > n) {
				pair<int, P> p = pq[i].top();
				pq[i].pop();
				P px = p.second;
				int maxx = -1; // 除了 i 之外最喜欢的部门
				int tgt = 0;

				px.update(i, -1e9);

				for (int j = 1; j <= 3; j++) {
					if (i == j)
						continue;
					if (px.get(j) > maxx) {
						maxx = px.get(j);
						tgt = j;
					}
				}

//				cerr << "move from " << i << " to " << tgt << "\n";

				pq[tgt].push({px.cost(tgt), px});
			}
		}
	}
//	cerr << "\n";

	for (int i = 1; i <= 3; i++) {
//		cerr << i << ": ";
		while (pq[i].size()) {
			ans += pq[i].top().second.get(i);
//			cerr << pq[i].top().second.get(i) << " ";
			pq[i].pop();
		}
//		cerr << "\n";
	}

//	cerr << "\n\n";
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}