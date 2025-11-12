#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T, n;

struct nod {
	int c[3], m1, m2, m3, mi1, mi2;
} p[N];

struct node {
	int mx, mn, id;
	node(int a, int b, int c): mx(a), mn(b), id(c) {}
};

bool operator <(node a, node b) {
	return a.mx - a.mn > b.mx - b.mn;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		priority_queue<node>q[3];
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			pair<int, int>v[3];
			for (int j = 0; j < 3; j++) {
				cin >> p[i].c[j];
				v[j].first = p[i].c[j];
				v[j].second = j;
			}
			sort(v, v + 3);
			p[i].m1 = v[2].first, p[i].m2 = v[1].first, p[i].m3 = v[0].second;
			p[i].mi1 = v[2].second, p[i].mi2 = v[1].second;
		}
		for (int i = 1; i <= n; i++) {
			int j = p[i].mi1, sz = q[j].size();
			if (sz == (n >> 1)) {
				node z = q[j].top();
				int id = z.id;
				if (p[i].m1 + z.mn > p[i].m2 + z.mx) {
					q[j].pop();
					q[j].push(node(p[i].m1, p[i].m2, i));
					q[p[id].mi2].push((node(p[id].m2, p[id].m3, id)));
				} else {
					q[p[i].mi2].push(node(p[i].m2, p[i].m3, i));
				}
			} else
				q[j].push(node(p[i].m1, p[i].m2, i));
		}
		for (int i = 0; i < 3; i++) {
			while (!q[i].empty()) {
				node z = q[i].top();
				q[i].pop();
				ans += z.mx;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
