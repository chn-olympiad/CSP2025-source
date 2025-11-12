#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long answ = 1e18;
long long r[2000][2000];
vector<long long> lis[2000];
bool vis[2000];
long long a[20];

struct S {
	long long to, v;
	bool operator<(const S &o)const {
		return v > o.v;
	}
};

void func(long long x) {
	memset(vis, 0, sizeof(vis));
	priority_queue<S> q;
	long long ans = 0;
	for (long long i = 0; i < k; i++) {
		if (x & (1 << i)) {
			vis[i + 1 + n] = true;
		} else {
			ans += a[i + 1];
		}
	}
	q.push({1, 0});
	while (!q.empty()) {
		S t;
		do {
			t = q.top();
			q.pop();
		} while (vis[t.to] && !q.empty());
		if (vis[t.to]) {
			break;
		}
		ans += t.v;
		vis[t.to] = true;
		for (long long i = 0; i < lis[t.to].size(); i++) {
			if (vis[lis[t.to][i]] == false) {
				q.push({lis[t.to][i], r[t.to][lis[t.to][i]]});
			}
		}

	}
	answ = min(ans, answ);
	cout << x << " " << ans << endl;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (long long i = 1; i <= m; i++) {
		long long x, y, v;
		cin >> x >> y >> v;
		r[x][y] = v;
		r[y][x] = v;
		lis[x].push_back(y);
		lis[y].push_back(x);
	}
	for (long long i = 1; i <= k; i++) {
		cin >> a[i];
		cout << a[i] << endl;
		long long x = i + n;
		for (long long i2 = 1; i2 <= n; i2++) {
			long long v;
			cin >> v;
			r[x][i2] = v;
			r[i2][x] = v;
			lis[x].push_back(i2);
			lis[i2].push_back(x);
		}
	}
	for (int i = 0; i < (1 << k); i++) {
		func(i);
	}
	cout << answ;
	return 0;
}