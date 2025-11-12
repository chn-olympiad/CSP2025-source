#include <bits/stdc++.h>
using namespace std;
const int maxn = 100006;

struct node {
	int t1, t2, t3, id;
} e[maxn];
int T, n, ans = 0, a1[maxn], a2[maxn], a3[maxn];
bool f1 = 0, f2 = 0;

bool cmp1(node a, node b) {
	return a.t1 > b.t1;
}

bool rcmp(node a, node b) {
	return a.id < b.id;
}

bool cmp2(node a, node b) {
	return a.t2 > b.t2;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		int k = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> e[i].t1 >> e[i].t2 >> e[i].t3;
			e[i].id = i;
			if (e[i].t2 != 0 || e[i].t3 != 0)
				f1 = 1;
			if (e[i].t3 != 0)
				f2 = 1;
		}
		if (n == 2) {
			int m1 = e[1].t1 + e[2].t2, m2 = e[1].t1 + e[2].t3, m3 = e[1].t2 + e[2].t3, m4 = e[1].t2 + e[2].t1,
			    m5 = e[1].t3 + e[2].t1, m6 = e[1].t3 + e[2].t2;
			m1 = max(m1, m2);
			m3 = max(m3, m4);
			m5 = max(m5, m6);
			m1 = max(m1, m3);
			m1 = max(m1, m5);
			ans = max(ans, m1);
			cout << ans;
		} else {
			if (f1 == 0) {
				sort(e + 1, e + 1 + n, cmp1);
				for (int i = 1; i <= k; i++)
					ans += e[i].t1;
				cout << ans;
			} else if (f2 == 0) {
				sort(e + 1, e + 1 + n, cmp1);
				int cnt1 = 0, cnt2 = 0;
				for (int i = 1; i <= n; i++) {
					if (e[i].t1 > e[i].t2 && cnt1 < k) {
						cnt1++;
						ans += e[i].t1;
					} else if (e[i].t1 < e[i].t2 && cnt2 < k) {
						cnt2++;
						ans += e[i].t2;
					} else
						ans += e[i].t1;
				}
				cout << ans;
			}
		}
	}
	return 0;
}