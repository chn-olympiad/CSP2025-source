#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, p[5];
long long ans;

priority_queue<int> q[5];

struct ds {
	int i, v;
	bool operator > (ds xy) const {
		return v>xy.v;
	}
};
void solve() {
	cin >> n;
	for (int i=1;i<=n;i++) {
		ds x[3];
		cin >> x[0].v >> x[1].v >> x[2].v;
		x[0].i = 1, x[1].i = 2, x[2].i = 3;
		if (x[0]>x[1]) swap(x[0], x[1]);
		if (x[0]>x[2]) swap(x[0], x[2]);
		if (x[1]>x[2]) swap(x[1], x[2]);
		ans += x[2].v, p[x[2].i]++, q[x[2].i].push(x[1].v-x[2].v);
	}
	for (int i=1;i<=3;i++) {
		if (p[i]<=n/2) continue;
		while (p[i] > n/2) {
			ans += q[i].top();
			q[i].pop();
			p[i]--;
		}
	} 
	cout << ans << '\n';
	ans = 0;
	for (int i=1;i<=3;i++)
		while (!q[i].empty()) q[i].pop();
	memset(p, 0, sizeof(p));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
