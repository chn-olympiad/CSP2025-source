#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define ll long long
ll t, n, cnt, ans;

struct no {
	ll x, id;
	bool fl;
} a[N][4];

bool cmp(no xx, no yy) {
	return xx.x > yy.x;
}

struct nod {
	ll ma, mai, iid;
	friend bool operator <(nod a, nod b) {
		return abs(a.ma - a.mai) > abs(b.ma - b.mai);
	}
};
priority_queue<nod>pq[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		for (int i = 1; i <= 3; i++) {
			while (!pq[i].empty()) {
				pq[i].pop();
			}
		}
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j].x;
				a[i][j].id = j;
				a[i][j].fl = 0;
			}
			sort(a[i] + 1, a[i] + 4, cmp);
			int id = a[i][1].id;
			pq[id].push({a[i][1].x, a[i][2].x, i});
			ans += a[i][1].x;
			a[i][1].fl = 1;
			while (pq[id].size() > n / 2) {
				nod tmp = pq[id].top();
				pq[id].pop();
				ans -= tmp.ma;
				int idd = tmp.iid;
				if (a[idd][2].fl == 0) {
					pq[a[idd][2].id].push({a[idd][2].x, a[idd][3].x, idd});
					ans += a[idd][2].x;
					id = a[idd][2].id;
				} else if (a[idd][3].fl == 0) {
					pq[a[idd][3].id].push({a[idd][3].x, a[idd][2].x, idd});
					ans += a[idd][3].x;
				}
			}
		}
		cout  << ans << "\n";
	}
	return 0;
}