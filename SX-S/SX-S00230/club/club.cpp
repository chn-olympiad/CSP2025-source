#include <bits/stdc++.h>
using namespace std;
int t, n, limit, ans;

struct node {
	int a, b, c;
};

struct cmp {
	bool operator()(const node a, const node b) {
		return a.a > b.a;
	}
};

struct cmp1 {
	bool operator()(const node a, const node b) {
		return a.b > b.b;
	}
};

struct cmp2 {
	bool operator()(const node a, const node b) {
		return a.c > b.c;
	}
};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		priority_queue<node, vector<node>, cmp > q1;
		priority_queue<node, vector<node>, cmp1 > q2;
		priority_queue<node, vector<node>, cmp2 > q3;
		cin >> n;
		limit = n / 2;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			if (x > max(y, z)) {
				if (q1.size() < limit)
					q1.push((node) {
					x, y, z
				});
				else {
					node tmp = q1.top();
					int u = (q2.size() < limit ? tmp.b : 0), v = (q3.size() < limit ? tmp.c : 0);
					if (max(u, v) - tmp.a + x > 0) {
						q1.pop();
						if (u > v)
							q2.push(tmp);
						else
							q3.push(tmp);
						q1.push((node) {
							x, y, z
						});
					} else {
						int p = (q2.size() < limit ? y : 0), q = (q3.size() < limit ? z : 0);
						if (p > q)
							q2.push((node) {
							x, y, z
						});
						else
							q3.push((node) {
							x, y, z
						});
					}
				}
			}
			if (y > max(x, z)) {
				if (q2.size() < limit)
					q2.push((node) {
					x, y, z
				});
				else {
					node tmp = q2.top();
					int u = (q1.size() < limit ? tmp.a : 0), v = (q3.size() < limit ? tmp.c : 0);
					if (max(u, v) - tmp.b + y > 0) {
						q2.pop();
						if (u > v)
							q1.push(tmp);
						else
							q3.push(tmp);
						q2.push((node) {
							x, y, z
						});
					} else {
						int p = (q1.size() < limit ? x : 0), q = (q3.size() < limit ? z : 0);
						if (p > q)
							q1.push((node) {
							x, y, z
						});
						else
							q3.push((node) {
							x, y, z
						});
					}
				}
			}
			if (z > max(x, y)) {
				if (q3.size() < limit)
					q3.push((node) {
					x, y, z
				});
				else {
					node tmp = q3.top();
					int u = (q1.size() < limit ? tmp.a : 0), v = (q2.size() < limit ? tmp.b : 0);
					if (max(u, v) - tmp.c + y > 0) {
						q2.pop();
						if (u > v)
							q1.push(tmp);
						else
							q2.push(tmp);
						q3.push((node) {
							x, y, z
						});
					} else {
						int p = (q1.size() < limit ? x : 0), q = (q2.size() < limit ? y : 0);
						if (p > q)
							q1.push((node) {
							x, y, z
						});
						else
							q2.push((node) {
							x, y, z
						});
					}
				}
			}
		}
		while (!q1.empty()) {
			ans += q1.top().a;
			q1.pop();
		}
		while (!q2.empty()) {
			ans += q2.top().b;
			q2.pop();
		}
		while (!q3.empty()) {
			ans += q3.top().c;
			q3.pop();
		}
		cout << ans << endl;
	}
	return 0;
}